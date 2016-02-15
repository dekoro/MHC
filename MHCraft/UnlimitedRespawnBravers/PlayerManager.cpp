#include "PlayerManager.h"
#include "EnemyManager.h"

PlayerManager::PlayerManager(){
	device		= DeviceManager::GetInstance();
}

PlayerManager::~PlayerManager(){
	DeleteAllPlayers();
}

void PlayerManager::Setup(){
	for (int i = 0; i < USE_PAD_MAX; ++i) {
		AddPlayerList(i, i);
	}
}

void PlayerManager::AddPlayerList(int playerNo, int padNo){
	//if (playerList[playerNo] != NULL){
	//	//Debug::Alert(STR("PlyerManager::AddPlayerList\n"
	//	//	,"���ɓo�^����Ă���C���f�b�N�X("
	//	//	+ std::to_string(playerNo)
	//	//	+")�ɓo�^���悤�Ƃ��Ă��܂��B"
	//	//));
	//}
	playerList[playerNo]	= new Player(playerNo);
	padNoList[playerNo]		= padNo;
}

void PlayerManager::Initialize(){
	InitializeAllPlayers();
	ResetCounter();
	ResetAddPlayerForbiddenCounter();
}

void PlayerManager::Update(){
	UpdateAllPlayers();
	Counting();
}

void PlayerManager::Draw(){
	for (int i = 0; i < USE_PAD_MAX; i++){
		if (playerList[i] == NULL){ continue; }
		playerList[i]->Draw();
	}
}

void PlayerManager::Finalize(){

}

Player* PlayerManager::GetPlayerData(int index){
	if (index >=  (int)playerList.size()){
		Debug::Alert("PlayerList�̔z��O("+ std::to_string(index)+ ")���Q�Ƃ���܂���");
	}
	return playerList[index];
}


//----private---

void PlayerManager::InitializeAllPlayers(){
	for (Player* pl : playerList) {
		pl->Initialize();
	}
}

void PlayerManager::UpdateAllPlayers(){
	for (Player* pl: playerList) {
		pl->Update();
	}
}

void PlayerManager::DrawAllPlayers(){
	for (Player* pl: playerList) {
		pl->Draw();
	}
}

void PlayerManager::PlayerDisable(int index){
	playerList[index]->Dispone();
}

void PlayerManager::DeleteAllPlayers(){
	for (int i = 0; i < USE_PAD_MAX; i++){
		SAFE_DELETE(playerList[i]);
	}
}


void PlayerManager::Counting(){
	if (++count >= 65000){ ResetCounter(); }
	if (countAddForbidden > 0){ countAddForbidden--; }

}

void PlayerManager::ResetCounter(){
	count = 0;
}

void PlayerManager::ResetAddPlayerForbiddenCounter(){
	countAddForbidden = 0;
}








