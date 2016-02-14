#include "GameMain.h"
#include"ScreenLayout.h"
#include"TextureMapping.h"
#include"EffectManager.h"
#include"e_Directon.h"
#include"TextLoader.h"

SceneGameMain::SceneGameMain(){
	TextLoader loader;
	loader.LoadDate("a.txt");
	device = DeviceManager::GetInstance();
	managers = Managers::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_GameMain_BackGround);
	stage = std::make_shared<Stage>(loader.GetDate());
	device->Image()->LoadMapTip("Resource/Title_BackGround.png",5,5,25);
}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData){
	ShaderLoad();
	blur = std::make_shared<Blur>();
	cut = std::make_shared<Cutting>(e_Left);
	this->screen = std::make_shared<ScreenLayout>(e_Quad, blur.get());

	AllManagersInitialize(sceneData.playerIndex);
}

SceneMediateData SceneGameMain::Update(){
	SceneMediateData nextScene;
	camera->Update();
	nextScene = AllManagersUpdate();
	return nextScene;
}


void SceneGameMain::Draw(){

	screen->Rendaring([&]()
	{
		camera->SetPosition();
		LocalDraw();
	});
	/*camera->SetPosition();
	LocalDraw();*/

	//blur->Rendering([&](){
	//	device->GetInstance()->Image()->DrawBackGround();
	//});
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
}

void SceneGameMain::AllManagersInitialize(int startPlayerIndex){
	managers->Player()->Initialize(startPlayerIndex);
	managers->Enemy()->Initialize();
	managers->Damage()->Initialize();
	managers->Item()->Initialize();

	camera = std::make_shared<Camera>(managers->Player()->GetPlayerData(0), 0);
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