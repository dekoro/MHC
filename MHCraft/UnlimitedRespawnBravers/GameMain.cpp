#include "GameMain.h"
#include"ScreenLayout.h"
#include"TextureMapping.h"
#include"EffectManager.h"
#include"e_Directon.h"
#include"TextLoader.h"

SceneGameMain::SceneGameMain(){
	TextLoader loader;
	loader.LoadDate("testMap.csv");
	device = DeviceManager::GetInstance();
	managers = Managers::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_GameMain_BackGround);
	//stage = std::make_shared<Stage>(loader.GetDate());
	
	stage = std::make_shared<Stage>(100,100);


	device->Image()->LoadMapTip("Resource/mapchip.png", 8, 4, (4 * 8) - 3);

	anime.AddMotion(e_STAND, device->GetInstance()->Image()->LoadMotion("Resource/mapchip2.png", 8, 4, 8, (4 * 8) - 3, 8),true);
	anime.AddMotion(e_WALK, device->GetInstance()->Image()->LoadMotion("Resource/mapchip2.png", 8, 4, 16, (4 * 8) - 3, 8),false);

	anime.ChangeMotion(e_STAND);
}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData){
	ShaderLoad();
	blur = std::make_shared<Blur>();
	cut = std::make_shared<Cutting>(e_Left);
	AllManagersInitialize(sceneData.playerIndex);
	this->screen = std::make_shared<ScreenLayout>((e_ScreenLayout)sceneData.playerIndex);
	screen->Initialize(managers->Player());
}

SceneMediateData SceneGameMain::Update(){
	SceneMediateData nextScene;
	nextScene = AllManagersUpdate();
	anime.Update();
	return nextScene;
}


void SceneGameMain::Draw(){

	screen->Rendaring([&]()
	{
		LocalDraw();
	});

	//LocalDraw();
}

void SceneGameMain::Finalize(){
	AllManagersFinalize();
}

//-----private-----

void SceneGameMain::LocalDraw()
{
	device->GetInstance()->Image()->DrawBackGround();

	stage->Draw();
	AllManagersDraw();

	if (device->GetInstance()->Input()->CheckKeyDownAllPad(GKey_Skill)){

		anime.ChangeMotion(e_WALK);
		if (!anime.IsEnd())
		{
			//anime.ChangeMotion("a");
		}
		else
		{
		}
	}

	device->GetInstance()->Image()->DrawLT(anime.GetMotion(), Vec2(0, 0));
}

void SceneGameMain::AllManagersInitialize(int startPlayerIndex){
	managers->Player()->Initialize(startPlayerIndex);

	managers->Enemy()->Initialize();
	managers->Damage()->Initialize();
	managers->Item()->Initialize();
}

SceneMediateData SceneGameMain::AllManagersUpdate(){
	managers->Player()->Update();
	SceneMediateData nextScene = managers->Enemy()->Update();
	managers->Damage()->Update();
	managers->Item()->Update();

	return nextScene;
}

void SceneGameMain::AllManagersDraw(){
	managers->Damage()->Draw();
	managers->Item()->Draw();
	managers->Player()->Draw();
	managers->Enemy()->Draw();
}

void SceneGameMain::AllManagersFinalize(){
	managers->Player()->Finalize();
	managers->Enemy()->Finalize();
	managers->Damage()->Finalize();
	managers->Item()->Finalize();
}

void SceneGameMain::ShaderLoad()
{
	EffectManager::GetInstance()->AddEffect("CutLeft", "Shader/PSCutRight.pso");
	EffectManager::GetInstance()->AddEffect("CutRight", "Shader/PSCutRight.pso");
	EffectManager::GetInstance()->AddEffect("Blur", "Shader/PSBlur.pso");
	EffectManager::GetInstance()->AddEffect("TexMap", "Shader/PSCutRight.pso");


}

void SceneGameMain::SHaderDalete()
{
	EffectManager::GetInstance()->RemoveAll();
}