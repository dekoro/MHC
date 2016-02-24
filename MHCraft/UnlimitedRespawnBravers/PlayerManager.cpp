#include "PlayerManager.h"
#include "EnemyManager.h"

PlayerManager::PlayerManager(){
	device		= DeviceManager::GetInstance();
}

PlayerManager::~PlayerManager(){
	ClearPlayerList();
}

void PlayerManager::AddPlayerList(int padNo, IMAGE_ASSET_NAME assetName, PlayerColorList colors){
	if (playerList[padNo] != NULL){
		Debug::Alert(STR("PlyerManager::AddPlayerList\n"
			,"���ɓo�^����Ă���C���f�b�N�X("
			+ to_string(padNo)
			+")�ɓo�^���悤�Ƃ��Ă��܂��B"
		));
	}
	playerList[padNo] = new Player(padNo, 5, 0, 4, assetName, colors);
	enablePlayerIndexList.push_back(padNo);
}

void PlayerManager::Initialize(int startPlayer){
	managers = Managers::GetInstance();
	ClearPlayerList();
	InitializeAllPlayers(startPlayer);
	ResetCounter();
	ResetAddPlayerForbiddenCounter();
}

SceneMediateData PlayerManager::Update(){
	CheckAddPlayer();
	PlayerUpdate();
	CheckHitAllPlayer();
	RefleshPlayerList();
	Counting();
	AddPlayerNaviRegister();
	return SceneMediateData::Setup(SCENE_GAMEMAIN);
}

void PlayerManager::Draw(){
	for (int i = 0; i < USE_PAD_MAX; i++){
		if (playerList[i] == NULL){ continue; }
		if (!playerList[i]->FlashManager(count)){ continue; }
		playerList[i]->Draw();
	}
}

void PlayerManager::Finalize(){

}

int PlayerManager::GetJoinNum(){
	return enablePlayerIndexList.size();
}

vector<int> PlayerManager::GetEnablePlayerIndexList(){
	return enablePlayerIndexList;
}

Player* PlayerManager::GetPlayerData(int index){
	if (index >=  (int)playerList.size()){
		Debug::Alert("PlayerList�̔z��O("+ std::to_string(index)+ ")���Q�Ƃ���܂���");
	}
	return playerList[index];
}

void PlayerManager::CheckHitAllPlayer(){
	for (int i = 0; i < USE_PAD_MAX; i++){
		if (playerList[i] == NULL){ continue; }
		CheckHitToEnemy(i);
		CheckHitToItem(i);
	}
}

//----private---

void PlayerManager::InitializeAllPlayers(int startPlayer){
	for (int i = 0; i <= startPlayer; i++)
	{
		AddTempPlayer(i);
	}
	
	for each(Player* pl in playerList){
		if (pl == NULL){ return; }
		pl->Initialize();
	}
	if (startPlayer <  0){ return; }
	if (startPlayer >= USE_PAD_MAX){ return; }
}

void PlayerManager::PlayerUpdate(){
	for (int i = 0; i < USE_PAD_MAX; i++){
		if (playerList[i] == NULL){ continue; }
		playerList[i]->Update();
	}
}

void PlayerManager::CheckAddPlayer(){
	if (countAddForbidden > 0){ return; }
	for (int i = 0; i < USE_PAD_MAX; i++){
		if (!device->Input()->GetInputState(i)->CheckJoinSign()){ continue; }
		AddTempPlayer(i);
	}
}

void PlayerManager::RefleshPlayerList(){
	for (int i = 0; i < USE_PAD_MAX; i++){
		CheckAndDeleteEndPlayer(i);
	}
}

void PlayerManager::DeletePlayer(int index){
	device->Input()->LeaveGamePad(index);
	if (playerList[index] == NULL){ return; }
	managers->Enemy()->LeaveTarget(index);
	DeleteEnablePlayerIndexList(index);
	SAFE_DELETE(playerList[index]);
}

void PlayerManager::DeleteEnablePlayerIndexList(int padNo){
	int itr = 0;
	bool isFound = false;
	for each(int i in enablePlayerIndexList){
		if (padNo == playerList[i]->GetPadNo()){
			isFound = true;
			break;
		}
		itr++;
	}
	if (!isFound){
		Debug::Alert(STR("PlayerManager::DeleteEnablePlayerIndexList\n", "padNo:"+to_string(padNo)+"�̃v���C���[���폜���悤�Ƃ��܂������A���݂��܂���B"));
	}
	enablePlayerIndexList.erase(enablePlayerIndexList.begin() + itr);
}

void PlayerManager::ClearPlayerList(){
	for (int i = 0; i < USE_PAD_MAX; i++){
		DeletePlayer(i);
	}
	enablePlayerIndexList.clear();
}

void PlayerManager::CheckAndDeleteEndPlayer(int index){
	if (USE_PAD_MAX <= index){
		Debug::Alert("�T�C�Y�O��index���Ă΂�܂����B");
	}
	if (playerList[index] == NULL){ return; }
	if (!playerList[index]->GetIsEnd()){ return; }
	int padNo = playerList[index]->GetPadNo();
	device->Input()->LeaveGamePad(padNo);
	DeletePlayer(index);
}

void PlayerManager::CheckHitToEnemy(int index){
	HitData hitData = managers->Enemy()->CalcAttackToPlayer(playerList[index]->GetPosition(), 5);
	if (hitData == HitData::NoHit()){
		return;
	}
	playerList[index]->HitDamage(hitData);
}

void PlayerManager::CheckHitToItem(int index){
	managers->Item()->CheckHitPlayer(playerList[index]);
}


void PlayerManager::AddTempPlayer(int index){
	device->Input()->GetInputState(index)->Join();
	PlayerColorList playerColor = PlayerColorList::Setup(GetRand(255), GetRand(255), GetRand(255),
														 GetRand(255), GetRand(255), GetRand(255),
														 GetRand(255), GetRand(255), GetRand(255));
	AddPlayerList(index, imageAsset_player_fighter, playerColor);
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
void PlayerManager::SetAddForbiddenCounter(){
	countAddForbidden = 300;
}

void PlayerManager::AddPlayerNaviRegister(){
	UIData uiData;
	if (GetJoinNum() == 0){
		uiData = UIData::Setup(Vec2::Setup(820, 5), 20, STR("�Q�[���I�[�o�[", "���̃Q�[�������҂����������B"));
	} else if (countAddForbidden > 0){
		int leftSec = (countAddForbidden+60) / 60;
		uiData = UIData::Setup(Vec2::Setup(1000, 5), 20, STR("�Q���\�܂Ŏc��",to_string(leftSec)+"�b"));
	} else {
		if (GetJoinNum() < USE_PAD_MAX){
			uiData = UIData::Setup(Vec2::Setup(1000, 5), 20, STR(to_string(GetJoinNum()), "�l�Q�����B�Q���ҕ�W��"));
		}
		else {
			uiData = UIData::Setup(Vec2::Setup(1000, 5), 20, STR("�����B", "���X���҂����������B"));
		}
	}
	UI::GetInstance()->AddUI(uiData);

}









