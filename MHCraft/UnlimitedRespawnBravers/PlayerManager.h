#ifndef _CHARACTER_PLAYERMANAGER_H_
#define _CHARACTER_PLAYERMANAGER_H_

#include "GSystem.h"
class Player;
class DeviceManager;
class ItemManager;

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	void		SpawnPlayer(int padNo, Vec2 position);
	void		Setup();
	void		Initialize();
	void		Update();
	void		Draw();
	void		Finalize();
	int			GetJoinNum();
	Player*		GetPlayerData(int index);

private:
	DeviceManager*	device;
	Player*			player[MAX_PLAYER];

	void InitializeAllPlayers();
	void UpdateAllPlayers();
	void MoveAllPlayers();
	void AttackAllPlayers();
	void DrawAllPlayers();
	void FinalizeAllPlayers();
	void PlayerDisable(int index);
	void DeleteAllPlayers();
};


#endif


