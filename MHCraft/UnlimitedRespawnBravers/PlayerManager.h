#ifndef _CHARACTER_PLAYERMANAGER_H_
#define _CHARACTER_PLAYERMANAGER_H_

#include "Player.h"
#include "DeviceManager.h"
#include "Managers.h"
#include "ItemManager.h"

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	void		AddPlayerList(int padNo, IMAGE_ASSET_NAME assetName, PlayerColorList colors);
	void		Initialize(int startPlayer);
	SceneMediateData		Update();
	void		Draw();
	void		Finalize();
	int			GetJoinNum();
	vector<int>	GetEnablePlayerIndexList();
	Player*		GetPlayerData(int index);
	void		CheckHitAllPlayer();
	void		SetAddForbiddenCounter();

private:
	DeviceManager*				device;
	Managers*					managers;
	array<Player*, USE_PAD_MAX>	playerList;
	vector<int>					enablePlayerIndexList;
	int							count;
	int							countAddForbidden;

	void InitializeAllPlayers(int startPlayer);
	void PlayerUpdate();
	void CheckAddPlayer();
	void RefleshPlayerList();
	void DeletePlayer(int index);
	void DeleteEnablePlayerIndexList(int padNo);
	void CheckHitToEnemy(int index);
	void CheckHitToItem(int index);
	void ClearPlayerList();
	void CheckAndDeleteEndPlayer(int index);
	void AddTempPlayer(int index);
	void Counting();
	void ResetCounter();
	void ResetAddPlayerForbiddenCounter();
	void AddPlayerNaviRegister();
};



#endif


