#include "PlayerManager.h"
#include "Player.h"
#include "DamageAreaManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"
#include "DeviceManager.h"
#include "LaserManager.h"

PlayerManager::PlayerManager(LaserManager* laserManager, DamageAreaManager* damageareaManager){
	device	= DeviceManager::GetInstance();
	for (int i = 0; i < MAX_PLAYER; ++i) {
		players[i] = new Player(i, laserManager, damageareaManager);
	}
}

PlayerManager::~PlayerManager(){
	DeleteAllPlayers();
}

void PlayerManager::SpawnPlayer(int padNo, Vec2 position){
	if (!GMath::Inner(padNo, 0, MAX_PLAYER)) { return; }
	if (players[padNo]->IsEnable()) { return; }
	players[padNo]->Setup(CharacterInformation::Setup(10, 10, 5, 5, 3, 5.0));
	players[padNo]->Spawn(position);
}

void PlayerManager::Setup(){
	for (int i = 0; i < MAX_PLAYER; ++i){

		SpawnPlayer(i, Vec2::Setup(150, 150));
	}
}

void PlayerManager::Initialize(){
	InitializeAllPlayers();
}

void PlayerManager::Update(){
	MoveAllPlayers();
	UpdateAllPlayers();
}

void PlayerManager::Draw(){
	DrawAllPlayers();
}

void PlayerManager::Finalize(){
	FinalizeAllPlayers();
}

int PlayerManager::GetJoinNum(){
	//Player* wheredPlayer = cpplinq::from_array(player)
	//	>> cpplinq::where([](Player* pl) { return !pl->GetIsDead(); })
	//	>> cpplinq::sum();
	//return sizeof(wheredPlayer) / sizeof(Player*);
	int joinNum = 0;
	for (int i = 0; i < MAX_PLAYER; ++i) {
		if (players[i]->IsEnable()) { ++joinNum; }

	}
	return joinNum;
}

Player* PlayerManager::GetPlayerData(int index){
	if (!GMath::Inner(index, 0, MAX_PLAYER)) {
		return nullptr;
	}
	return players[index];
}

int PlayerManager::GetLivePlayerNum(){
	int playerNum = 0;
	for (int i = 0; i < MAX_PLAYER; ++i){
		if (!players[i]->GetIsDead()){ ++playerNum; }
	}
	return playerNum;
}


std::array<Player*, MAX_PLAYER>	PlayerManager::GetPlayers(){
	return players;
}

//----private---

void PlayerManager::InitializeAllPlayers(){
	for (Player* pl : players) {
		pl->Initialize();
	}
}

void PlayerManager::UpdateAllPlayers(){
	for (Player* pl: players) {
		pl->Update();
	}
}

void PlayerManager::MoveAllPlayers(){
	for (int i = 0; i < MAX_PLAYER; ++i) {
		InputState* input = device->Input()->GetInputState(i);
	}
}

void PlayerManager::AttackAllPlayers()
{
}

void PlayerManager::DrawAllPlayers(){
	for (Player* pl: players) {
		pl->Draw();
	}
}

void PlayerManager::PlayerDisable(int index){
	players[index]->Dispone();
}

void PlayerManager::DeleteAllPlayers(){
	for (int i = 0; i < MAX_PLAYER; i++){
		SAFE_DELETE(players[i]);
	}
}

void PlayerManager::FinalizeAllPlayers(){
	for (Player* pl : players) {
		pl->Finalize();
	}

}






