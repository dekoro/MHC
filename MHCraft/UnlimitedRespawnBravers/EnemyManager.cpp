#include "EnemyManager.h"
#include "ItemManager.h"
#include "PlayerManager.h"
#include "Enemy.h"
#include "Player.h"
#include "ImageRenderer.h"

EnemyManager::EnemyManager() {
}

EnemyManager::~EnemyManager() {
	ClearEnemy();
}

void EnemyManager::Setup(PlayerManager* playerManager)
{
	this->playerManager = playerManager;
}

void EnemyManager::Initialize() {
	using namespace std;
	for(Enemy* e: enemyList){
		e->Initialize();
	}
}

void EnemyManager::Update() {
	for (Enemy* e : enemyList) {
		e->Update();
	}
}

void EnemyManager::Draw() {
	for (Enemy* e : enemyList) {
		e->Draw();
	}
}

void EnemyManager::Finalize() {
	ClearEnemy();
}

void EnemyManager::AddEnemy(IMAGE_ASSET_NAME asset) {
	
}

//-----private------

void EnemyManager::RemoveNotUseEnemys() {
	int itr = 0;
	int numList = enemyList.size();

	for (int i = 0; i < numList; i++) {
		if (enemyList[i]->GetIsUse()) { continue; }
		RemoveEnemy(i);
		numList--;
		i--;
	}
}

void EnemyManager::RemoveEnemy(int index) {
	SAFE_DELETE(enemyList[index]);
	enemyList.erase(enemyList.begin() + index);
}

void EnemyManager::ClearEnemy() {
	while (!enemyList.empty()) {
		RemoveEnemy(0);
	}
}

void EnemyManager::CalcSpawnMob(int rate) {

}

void EnemyManager::DeadPlayerActioon() {
	for (Enemy* en : enemyList) {
		//en->DeadPlayerAction();
		
	}
}



