#include "GameMain.h"
#include"ScreenLayout.h"
#include"TextureMapping.h"
#include"EffectManager.h"
#include"e_Directon.h"
#include"TextLoader.h"
#include "GMath.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "LaserManager.h"
#include "DamageAreaManager.h"

SceneGameMain::SceneGameMain(){
	TextLoader loader;
	loader.LoadDate("testMap.csv");
	device = DeviceManager::GetInstance();
	//stage = std::make_shared<Stage>(loader.GetDate());

	stage = std::make_shared<Stage>(100, 100);


	device->Image()->LoadMapTip("Resource/mapchip.png", 8, 4, (4 * 8) - 3);


	damageAreaManager	= std::make_shared<DamageAreaManager>();
	laserManager		= std::make_shared<LaserManager>(damageAreaManager.get());
	playerManager		= std::make_shared<PlayerManager>(laserManager.get(), damageAreaManager.get());
	enemyManager		= std::make_shared<EnemyManager>(damageAreaManager.get(), playerManager.get());
}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData){
	ShaderLoad();
	nowStart = true;
	AllManagersInitialize(sceneData.playerIndex);
	this->screen = std::make_shared<ScreenLayout>((e_ScreenLayout)sceneData.playerIndex);
	screen->Initialize(playerManager.get());

}

SceneMediateData SceneGameMain::Update(){
	AllManagersUpdate();

	FadeIn();

	if (enemyManager->GetLeftEnemyNum() <= 0){
		SHaderDalete();
		return SceneMediateData::Setup(SCENE_CLEAR);
	}
	if (playerManager->GetLivePlayerNum() <= 0){
		SHaderDalete();
		return SceneMediateData::Setup(SCENE_GAMEOVER);
	}
	return SceneMediateData::Setup(SCENE_GAMEMAIN, 1);
}


void SceneGameMain::Draw(){

	screen->Rendaring([&]()
	{
		LocalDraw();
	});
}

void SceneGameMain::Finalize(){
	AllManagersFinalize();
	screen.reset();
}

//-----private-----

void SceneGameMain::LocalDraw()
{
	device->GetInstance()->Image()->DrawBackGround();

	stage->Draw();
	AllManagersDraw();
}

void SceneGameMain::AllManagersInitialize(int startPlayerIndex){
	for (int i = 0; i < startPlayerIndex+1 ; i++)
	{
		playerManager->SpawnPlayer(i, Vec2());
	}

	playerManager		->Initialize();
	enemyManager		->Initialize();
	laserManager		->Initialize();
	damageAreaManager	->Initialize();
}

void SceneGameMain::AllManagersUpdate(){
	playerManager->Update();
	enemyManager->Update();
	laserManager->Update();
	damageAreaManager->Update();
}

void SceneGameMain::AllManagersDraw(){
	playerManager->Draw();
	enemyManager->Draw();
	laserManager->Draw();
	damageAreaManager->Draw();
}

void SceneGameMain::AllManagersFinalize(){
	playerManager->Finalize();
	enemyManager->Finalize();
	damageAreaManager->Finalize();
}

void SceneGameMain::ShaderLoad()
{
	EffectManager::GetInstance()->AddEffect("CutLeft", "Shader/PSCutLeft.pso");
	EffectManager::GetInstance()->AddEffect("CutRight", "Shader/PSCutRight.pso");
	EffectManager::GetInstance()->AddEffect("Blur", "Shader/PSBlur.pso");
	EffectManager::GetInstance()->AddEffect("TexMap", "Shader/PSTextureMapping.pso");

	//�e�X�g
	EffectManager::GetInstance()->AddEffect("Zoom", "Shader/ZoomBlur.pso");
}

void SceneGameMain::SHaderDalete()
{
	EffectManager::GetInstance()->RemoveAll();
}

void SceneGameMain::FadeIn()
{
	if (!nowStart)
		return;

	for (int i = 0; i < screen->GetScreenNum(); i++)
	{
		screen->ZoomStart((e_ScreenNumber)i);
	}
	this->nowStart = false;


}