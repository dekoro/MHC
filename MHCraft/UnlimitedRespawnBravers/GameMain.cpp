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
	
	stage = std::make_shared<Stage>(100,100);


	device->Image()->LoadMapTip("Resource/mapchip.png", 8, 4, (4 * 8) - 3);

	damageAreaManager	= std::make_shared<DamageAreaManager>();
	laserManager		= std::make_shared<LaserManager>(damageAreaManager.get());
	playerManager		= std::make_shared<PlayerManager>(laserManager.get(), damageAreaManager.get());
	enemyManager		= std::make_shared<EnemyManager>(damageAreaManager.get());

}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData){
	ShaderLoad();

	AllManagersInitialize(sceneData.playerIndex);
	this->screen = std::make_shared<ScreenLayout>((e_ScreenLayout)sceneData.playerIndex);
	screen->Initialize(playerManager.get());

}

SceneMediateData SceneGameMain::Update(){
	AllManagersUpdate();
	if (device->GetInstance()->Input()->GetInputState(0)->CheckKeyDown(GKey_Up))
	{
		screen->SetUseTexMapConst(true,e_First);
	}
	else
	{
		screen->SetUseBlurConst(Vec2(1,0),0.2, e_First);
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
}

//-----private-----

void SceneGameMain::LocalDraw()
{
	device->GetInstance()->Image()->DrawBackGround();

	stage->Draw();
	AllManagersDraw();
}

void SceneGameMain::AllManagersInitialize(int startPlayerIndex){
	for (int i = 0; i < startPlayerIndex; i++)
	{
		playerManager->SpawnPlayer(i,Vec2());
	}

	playerManager		->Setup();
	playerManager		->Initialize();
	enemyManager		->Initialize();
	laserManager		->Initialize();
	damageAreaManager	->Initialize();
}

void SceneGameMain::AllManagersUpdate(){
	playerManager		->Update();
	enemyManager		->Update();
	laserManager		->Update();
	damageAreaManager	->Update();
}

void SceneGameMain::AllManagersDraw(){
	playerManager		->Draw();
	enemyManager		->Draw();
	laserManager		->Draw();
	damageAreaManager	->Draw();
}

void SceneGameMain::AllManagersFinalize(){
	playerManager		->Finalize();
	enemyManager		->Finalize();
	damageAreaManager	->Finalize();
}

void SceneGameMain::ShaderLoad()
{
	EffectManager::GetInstance()->AddEffect("CutLeft", "Shader/PSCutLeft.pso");
	EffectManager::GetInstance()->AddEffect("CutRight", "Shader/PSCutRight.pso");
	EffectManager::GetInstance()->AddEffect("Blur", "Shader/PSBlur.pso");
	EffectManager::GetInstance()->AddEffect("TexMap", "Shader/PSTextureMapping.pso");


}

void SceneGameMain::SHaderDalete()
{
	EffectManager::GetInstance()->RemoveAll();
}