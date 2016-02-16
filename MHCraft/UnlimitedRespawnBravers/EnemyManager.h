#ifndef _CHARACTER_ENEMY_ENEMYMANAGER_H_
#define _CHARACTER_ENEMY_ENEMYMANAGER_H_

#include "GSystemHub.h"
class PlayerManager;
class Enemy;
class Player;
enum IMAGE_ASSET_NAME;

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	
	void	Setup(PlayerManager* playerManager);
	void	Initialize();
	void	Update();
	void	Draw();
	void	Finalize();
	void	AddEnemy(IMAGE_ASSET_NAME asset);
	void	CalcSpawnMob(int rate=90);
	void	DeadPlayerActioon();

private:
	std::vector<Enemy*>	enemyList;
	PlayerManager*	playerManager;

	int	 spawnCount;
	void RemoveNotUseEnemys();
	void RemoveEnemy(int index);
	void ClearEnemy();


};



#endif














