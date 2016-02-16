#include "GameMain.h"
#include "GMath.h"
#include "ScreenLayout.h"
#include "TextureMapping.h"
#include "EffectManager.h"
#include "e_Directon.h"
#include "TextLoader.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"

#include "ScreenLayout.h"
#include "TextureMapping.h"
#include "DamageAreaManager.h"


SceneGameMain::SceneGameMain(){

	TextLoader loader;
	loader.LoadDate("a.txt");
	stage			= std::make_shared<Stage>(loader.GetDate());
	device			= DeviceManager::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_GameMain_BackGround);
	device->Image()->LoadMapTip("Resource/Title_BackGround.png", 5, 5, 25);
	this->screen = std::make_shared<ScreenLayout>(e_Double, blur.get());

	playerManager	  = std::make_shared<PlayerManager>();
	enemyManager	  = std::make_shared<EnemyManager>();
	itemManager		  = std::make_shared<ItemManager>();
	damageAreaManager = std::make_shared<DamageAreaManager>();
}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData){
	ShaderLoad();
	blur = std::make_shared<Blur>();
	cut = std::make_shared<Cutting>(e_Left);
	this->screen = std::make_shared<ScreenLayout>(e_Quad, blur.get());

	AllManagersInitialize();
	for (int i = 0; i < MAX_PLAYER; ++i) {
		playerManager->SpawnPlayer(i, Vec2::Setup(150, 150));
	}
}

SceneMediateData SceneGameMain::Update(){
//	if (playerManager->GetJoinNum() <= 0) { return SceneMediateData::Setup(SCENE_TITLE); }
	AllManagersUpdate();
	return SceneMediateData::Setup(SCENE_GAMEMAIN);
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
	AllManagersDraw();
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

void SceneGameMain::AllManagersInitialize(){
	playerManager		->Setup();
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