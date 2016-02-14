#ifndef _CHARACTER_PLAYERMANAGER_H_
#define _CHARACTER_PLAYERMANAGER_H_

#include "GSystem.h"
class Player;
class DeviceManager;
class Managers;
class ItemManager;

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	void		SpawnPlayer(int padNo, Vec2 position);
	void		Initialize();
	void		Update();
	void		Draw();
	void		Finalize();
	int			GetJoinNum();
	Player*		GetPlayerData(int index);

private:
	DeviceManager*	device;
	Managers*		managers;
	Player*			player[MAX_PLAYER];

	void CreatePlayer();
	void InitializeAllPlayers();
	void PlayerUpdate();
	void CheckHitToEnemy(int index);
	void CheckHitToItem(int index);
	void DeletePlayerList();
	bool IsPresence(int index);
};



#endif


