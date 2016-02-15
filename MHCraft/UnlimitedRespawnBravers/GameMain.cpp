#include "GameMain.h"
#include "ScreenLayout.h"
#include "TextureMapping.h"
#include "DamageAreaManager.h"


SceneGameMain::SceneGameMain(){
	device			= DeviceManager::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_GameMain_BackGround);

	this->screen = std::make_shared<ScreenLayout>(e_Double, &blur);
}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData){
	AllManagersInitialize(sceneData.playerIndex);
}

SceneMediateData SceneGameMain::Update(){
	camera->Update();
	AllManagersUpdate();
	return SceneMediateData::Setup(SCENE_GAMEMAIN);
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
	playerManager		->Initialize();
	enemyManager		->Initialize();
	itemManager			->Initialize();
	damageAreaManager	->Initialize();

	camera = std::make_shared<Camera>(playerManager->GetPlayerData(0),0);
}

void SceneGameMain::AllManagersUpdate(){
	playerManager->Update();
	enemyManager->Update();
	itemManager->Update();
	damageAreaManager->Update();
}

void SceneGameMain::AllManagersDraw(){
	playerManager->Draw();
	enemyManager->Draw();
	itemManager->Draw();
	damageAreaManager->Draw();
}

void SceneGameMain::AllManagersFinalize(){
	playerManager->Finalize();
	enemyManager->Finalize();
	itemManager->Finalize();
	damageAreaManager->Finalize();
}
