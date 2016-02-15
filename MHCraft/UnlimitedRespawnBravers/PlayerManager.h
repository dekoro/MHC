#ifndef _CHARACTER_PLAYERMANAGER_H_
#define _CHARACTER_PLAYERMANAGER_H_

#include "Player.h"
#include "DeviceManager.h"
#include "ItemManager.h"

class PlayerManager
{
public:
	PlayerManager();
	~PlayerManager();

	void	Setup();
	void	AddPlayerList(int playerNo, int padNo);
	void	Initialize();
	void	Update();
	void	Draw();
	void	Finalize();
	Player*	GetPlayerData(int index);

private:
	DeviceManager*						device;
	std::array<Player*, USE_PAD_MAX>	playerList;
	std::array<int, USE_PAD_MAX>		padNoList;
	int		count;
	int		countAddForbidden;

	void	InitializeAllPlayers();
	void	UpdateAllPlayers();
	void	DrawAllPlayers();
	void	PlayerDisable(int index);
	void	DeleteAllPlayers();
	void	Counting();
	void	ResetCounter();
	void	ResetAddPlayerForbiddenCounter();
};



#endif


