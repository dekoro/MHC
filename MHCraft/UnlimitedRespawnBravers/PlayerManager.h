#ifndef _CHARACTER_PLAYERMANAGER_H_
#define _CHARACTER_PLAYERMANAGER_H_

#include "GSystem.h"
class Player;
class DeviceManager;
class ItemManager;
class DamageAreaManager;
class LaserManager;



class PlayerManager
{
public:
	PlayerManager(LaserManager* laserManager, DamageAreaManager* damageareaManager);
	~PlayerManager();

	void		SpawnPlayer(int padNo, Vec2 position);
	void		Setup();
	void		Initialize();
	void		Update();
	void		Draw();
	void		Finalize();
	int			GetJoinNum();
	Player*		GetPlayerData(int index);
	int			GetLivePlayerNum();
	std::array<Player*, MAX_PLAYER>	GetPlayers();

private:
	DeviceManager*		device;
	std::array<Player*, MAX_PLAYER>	players;

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


