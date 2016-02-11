#include "GameMain.h"
#include"ScreenLayout.h"
#include"TextureMapping.h"
#include"EffectManager.h"
#include"e_Directon.h"

SceneGameMain::SceneGameMain(){
	device			= DeviceManager::GetInstance();
	managers		= Managers::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_GameMain_BackGround);

	this->screen = std::make_shared<ScreenLayout>(e_Quad, &blur);
}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData){
	AllManagersInitialize(sceneData.playerIndex);
	ShaderLoad();
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
}

void SceneGameMain::Finalize(){
	AllManagersFinalize();
}

//-----private-----

void SceneGameMain::LocalDraw()
{
	device->GetInstance()->Image()->DrawBackGround();
	AllManagersDraw();
}

void SceneGameMain::AllManagersInitialize(int startPlayerIndex){
	managers->Player()->Initialize(startPlayerIndex);
	managers->Enemy()->Initialize();
	managers->Damage()->Initialize();
	managers->Item()->Initialize();

	camera = std::make_shared<Camera>(managers->Player()->GetPlayerData(0),0);
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
	EffectManager::GetInstance()->AddEffect("CutLeft",std::make_shared<Cutting>(e_Left));
	EffectManager::GetInstance()->AddEffect("CutRight", std::make_shared<Cutting>(e_Right));
	EffectManager::GetInstance()->AddEffect("Blur",std::make_shared<Blur>());
	EffectManager::GetInstance()->AddEffect("TexMap",std::make_shared<TextureMapping>());
	
}

void SceneGameMain::SHaderDalete()
{
	EffectManager::GetInstance()->RemoveAll();
}