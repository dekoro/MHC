#include "EnemyManager.h"
#include "ItemManager.h"
#include "DamageAreaManager.h"

#include "Enemy_Test.h"
#include "EnemyGhost.h"
#include "EnemyKingPumpkin.h"

EnemyManager::EnemyManager(DamageAreaManager* damageAreaManager){
	this->damageAreaManager = damageAreaManager;
	stage			= 1;
	normaLollipop	= 10+5*(stage-1);
	SetFontSize(20);
}

EnemyManager::~EnemyManager(){
	ClearEnemy();
}

void EnemyManager::Initialize(){
	device		= DeviceManager::GetInstance();
	for each(Enemy* ie in enemyList){
		ie->Initialize();
	}
	gameMode = GameMode_Main;
	cntClear = cntGameOver = 60;
	StageInitialize();
}

SceneMediateData EnemyManager::Update(){
	bool isSceneEnd = false;
	/*for each(Enemy* ie in enemyList){
		ie->Update();
	}*/

	int enemyListNum = enemyList.size();
	for (int i = 0; i < enemyListNum; i++){
		enemyList[i]->Update();
	}

	switch (gameMode){
	case GameMode_Main:
		if (isBoss){
			device->Sound()->Stop(Music_GameMain_BGM_Normal);
			CalcSpawnBoss();
		}else{
			device->Sound()->Play(Music_GameMain_BGM_Normal);
			CalcSpawnMob();
		}
		break;
	case GameMode_Clear:
		isSceneEnd = ClearMode();
		break;
	case GameMode_GameOver:
		isSceneEnd = GameOverMode();
		break;
	default:
		break;
	}

	RemoveNotUseEnemys();
	if (isSceneEnd){
		return SceneMediateData::Setup(SCENE_TITLE);
	} else{
		return SceneMediateData::Setup(SCENE_GAMEMAIN);
	}
}

void EnemyManager::Draw(){
	for each(Enemy* ie in enemyList){
		if (ie->GetAssetName() != imageAsset_Enemy_BigPumpkin){
			ie->Draw();
		}
	}
	for each(Enemy* ie in enemyList){
		if (ie->GetAssetName() == imageAsset_Enemy_BigPumpkin){
			ie->Draw();
		}
	}
	CalcHervestLollipop();
}

void EnemyManager::Finalize(){
	ClearEnemy();
}

void EnemyManager::AddEnemy(IMAGE_ASSET_NAME asset){
	switch (asset){
	case imageAsset_Enemy_Ghost:
		new EnemyGhost(damageAreaManager, &enemyList);
		break;
	case imageAsset_Enemy_BigPumpkin :
		new EnemyKingPumpkin(damageAreaManager, &enemyList);
		break;
	default:
		Debug::Alert(STR("EnemyManager::AddEnemy\n","想定外の引数"+to_string(asset)+"がコールされました。"));
		break;
	}
}

void EnemyManager::LeaveTarget(int forbiddenTarget){
	for each(Enemy* el in enemyList){
		el->ResearchTarget(forbiddenTarget);
	}
}

HitData EnemyManager::CalcAttackToPlayer(Vec2 position, double hitRadius){
	for each(Enemy* en in enemyList){
		if (en->GetIsDead()){ continue; }
		HitData chkHit = en->CalcAttackToPlayer(position, hitRadius);
		if (chkHit == HitData::NoHit()){ continue; }
		return chkHit;
	}
	return HitData::NoHit();
}


//-----private------

void EnemyManager::RemoveNotUseEnemys(){
	int itr		= 0;
	int numList	= enemyList.size();

	for (int i = 0; i < numList; i++){
		if (enemyList[i]->GetIsUse()){ continue; }
		LotDropItem(enemyList[i]->GetPosition());
		RemoveEnemy(i);
		numList--;
		i--;
	}
}

void EnemyManager::RemoveEnemy(int index){
	SAFE_DELETE(enemyList[index]);
	enemyList.erase(enemyList.begin() + index);
}

void EnemyManager::ClearEnemy(){
	while (!enemyList.empty()){
		RemoveEnemy(0);
	}
}

void EnemyManager::CalcSpawnMob(int rate){
	if (--spawnCount > 0){ return; }
	//int spawnCountTemp = rate - managers->Player()->GetJoinNum() * 3;
	//spawnCount = (spawnCountTemp > 5) ? spawnCountTemp : 5;
	AddEnemy(imageAsset_Enemy_Ghost);
}

void EnemyManager::CalcSpawnBoss(){
	if (--cntIntervalSpawnBoss < 0){ return; }
	if (cntIntervalSpawnBoss == 0){
		AddEnemy(imageAsset_Enemy_BigPumpkin);
	}

}

void EnemyManager::LotDropItem(Vec2 position){
	//int rate =  managers->Player()->GetJoinNum();
	//if (GetRand(rate) != GetRand(rate)){ return; }
	DropItem(position);
}


void EnemyManager::DropItem(Vec2 position){
	//managers->Item()->AddItemLollipop(position);
}

void EnemyManager::CalcHervestLollipop(){
	int getLollipopNum = 0;/*managers->Item()->GetCountGetItem();*/
	UI::GetInstance()->AddUI(UIData::Setup(Vec2::Setup(5, 5),20, STR("Lollipop : ", to_string(getLollipopNum) + "個\n")));
	if (isBoss){ return; }
	int left = normaLollipop - getLollipopNum;
	if (left <= 0){
		isBoss = true;
		return;
	}
	UI::GetInstance()->AddUI(UIData::Setup(Vec2::Setup(5,25), 20, STR("残り", to_string(left) + "個")));
}

void EnemyManager::StageInitialize(){
	isBoss = false;
	cntIntervalSpawnBoss = 300;
}

void EnemyManager::DeadPlayerActioon(){
	for (Enemy* en : enemyList){
		en->DeadPlayerAction();
	}
}


bool EnemyManager::ClearMode(){
	UIData ui = UIData::Setup(Vec2::Setup(350, 360), 20, STR("CLEAR!!", "君はハロウィンの悪夢から無事に抜け出せるだろう！"));
	UI::GetInstance()->AddUI(ui);
	ui = UIData::Setup(Vec2::Setup(470, 380), 20, STR("×", "ボタンでタイトルに戻ります。"));
	UI::GetInstance()->AddUI(ui);
	return (--cntClear <= 0 && device->Input()->CheckKeyDownAllPad(GKey_Attack));
}

bool EnemyManager::GameOverMode(){
	UIData ui = UIData::Setup(Vec2::Setup(512, 360), 20, STR("GameOver!!!!", "全滅してしまった。。"));
	UI::GetInstance()->AddUI(ui);
	ui = UIData::Setup(Vec2::Setup(512, 380), 20, STR("×", "ボタンでタイトルに戻ります。"));
	UI::GetInstance()->AddUI(ui);
	return (--cntGameOver <= 0 && device->Input()->CheckKeyDownAllPad(GKey_Attack));
}






