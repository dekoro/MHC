#include "PlayerManager.h"
#include "player.h"
#include "EnemyManager.h"
#include "ItemManager.h"
#include "DeviceManager.h"

PlayerManager::PlayerManager(){
	device	= DeviceManager::GetInstance();
	for (int i = 0; i < MAX_PLAYER; ++i) {
		player[i] = new Player(i);
	}
}

PlayerManager::~PlayerManager(){
	DeleteAllPlayers();
}

void PlayerManager::SpawnPlayer(int padNo, Vec2 position){
	if (!GMath::Inner(padNo, 0, MAX_PLAYER)) { return; }
	if (player[padNo]->IsEnable()) { return; }
	player[padNo]->Setup(CharacterInformation::Setup(10, 10, 5, 5, 3, 5.0));
	player[padNo]->Spawn(position);
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
		if (player[i]->IsEnable()) { ++joinNum; }

	}
	return joinNum;
}

Player* PlayerManager::GetPlayerData(int index){
	if (!GMath::Inner(index, 0, MAX_PLAYER)) {
		return nullptr;
	}
	return player[index];
}

//----private---

void PlayerManager::InitializeAllPlayers(){
	for (Player* pl : player) {
		pl->Initialize();
	}
}

void PlayerManager::UpdateAllPlayers(){
	for (Player* pl: player) {
		pl->Update();
	}
}

void PlayerManager::MoveAllPlayers()
{
	for (int i = 0; i < MAX_PLAYER; ++i) {
		InputState* input = device->Input()->GetInputState(i);
		if (input->CheckKeyDown(GKey_Up))		{ player[i]->Move(Vec2::Setup( 0,  1)); }
		if (input->CheckKeyDown(GKey_Down))		{ player[i]->Move(Vec2::Setup( 0, -1)); }
		if (input->CheckKeyDown(GKey_Left))		{ player[i]->Move(Vec2::Setup(-1,  0)); }
		if (input->CheckKeyDown(GKey_Right))	{ player[i]->Move(Vec2::Setup(1,  0)); }
	}
}

void PlayerManager::DrawAllPlayers(){
	for (Player* pl: player) {
		pl->Draw();
	}
}

void PlayerManager::PlayerDisable(int index){
	player[index]->Dispone();
}

void PlayerManager::DeleteAllPlayers(){
	for (int i = 0; i < MAX_PLAYER; i++){
		SAFE_DELETE(player[i]);
	}
}

void PlayerManager::FinalizeAllPlayers(){
	for (Player* pl : player) {
		pl->Finalize();
	}

}






