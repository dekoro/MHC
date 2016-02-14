#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"

PlayerManager::PlayerManager(){
	device	= DeviceManager::GetInstance();
	CreatePlayer();
}

PlayerManager::~PlayerManager(){
	DeletePlayerList();
}

void PlayerManager::SpawnPlayer(int padNo, Vec2 position){
	if (!GMath::Inner(padNo, 0, MAX_PLAYER)) { return; }
	if (player[padNo]->IsEnable()) { return; }
	player[padNo]->Spawn(position);
}

void PlayerManager::Initialize(){
	managers = Managers::GetInstance();
	InitializeAllPlayers();
}

void PlayerManager::Update(){
	PlayerUpdate();
	return;
}

void PlayerManager::Draw(){
	for (Player* pl : player) {
		pl->Draw();
	}
}

void PlayerManager::Finalize()
{
	for (Player* pl: player) {
		pl->Finalize();
	}
}

int PlayerManager::GetJoinNum(){
	//Player* wheredPlayer = cpplinq::from_array(player)
	//	>> cpplinq::where([](Player* pl) { return !pl->GetIsDead(); })
	//	>> cpplinq::sum();
	//return sizeof(wheredPlayer) / sizeof(Player*);
	int joinNum = 0;
	for (int i = 0; i < MAX_PLAYER; ++i) {
		if (player[i]->IsEnable()) { ++joinNum; }
	}
	return joinNum;
}

Player* PlayerManager::GetPlayerData(int index){
	if (!IsPresence(index)) { return NULL; }
	return player[index];
}

//----private---

void PlayerManager::CreatePlayer()
{
	//int padNo = 0;
	//for(Player* pl: player){
	//	pl = new Player(padNo);
	//	++padNo;
	//}
	for (int i = 0; i < MAX_PLAYER; ++i) {
		player[i] = new Player(i);
	}
}

void PlayerManager::InitializeAllPlayers(){
	for (Player* pl : player) {
		pl->Initialize();
	}
}

void PlayerManager::PlayerUpdate(){
	for (Player* pl : player) {
		pl->Update();
	}
}

void PlayerManager::DeletePlayerList(){
	for (Player* pl : player) {
		SAFE_DELETE(pl);
	}
}

void PlayerManager::CheckHitToEnemy(int index){
	HitData hitData =	managers->
						Enemy()->
						CalcAttackToPlayer(player[index]->GetPosition(), 5);
	if (hitData == HitData::NoHit()){
		return;
	}
	player[index]->HitDamage(hitData);
}

void PlayerManager::CheckHitToItem(int index){
	managers->Item()->CheckHitPlayer(player[index]);
}

bool PlayerManager::IsPresence(int index){
	if (!GMath::Inner(index, 0, MAX_PLAYER)) { return false; }
	if (!player[index]->IsEnable()) { return false; }
	return true;
}









