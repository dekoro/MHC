#ifndef _CHARACTER_ENEMY_ENEMYMANAGER_H_
#define _CHARACTER_ENEMY_ENEMYMANAGER_H_

#include "GSystemHub.h"
#include "Enemy.h"
class DamageAreaManager;

enum GameMode{
	GameMode_Main,
	GameMode_Clear,
	GameMode_GameOver
};

enum GameDeadOrClear{
	GameNever,
	GameOver,
	GameClear
};

class EnemyManager
{
public:
	EnemyManager(DamageAreaManager* damageAreaManager);
	~EnemyManager();
	
	void				Initialize();
	SceneMediateData	Update();
	void				Draw();
	void				Finalize();
	void				AddEnemy(IMAGE_ASSET_NAME asset);
	void				LeaveTarget(int forbiddenTarget);
	HitData				CalcAttackToPlayer(Vec2 position, double hitRadius);
	void				CalcSpawnMob(int rate=90);
	void				CalcSpawnBoss();
	GameMode			gameMode;
	void DeadPlayerActioon();

private:
//	Managers*		managers;
	vector<Enemy*>	enemyList;
	DeviceManager*	device;
	DamageAreaManager* damageAreaManager;
	int				stage;
	int				normaLollipop;

	void StageInitialize();
	int	 spawnCount;
	int	 cntIntervalSpawnBoss;
	bool isBoss;
	void RemoveNotUseEnemys();
	void RemoveEnemy(int index);
	void ClearEnemy();
	void LotDropItem(Vec2 position);
	void DropItem(Vec2 position);
	void CalcHervestLollipop();

	bool ClearMode();
	bool GameOverMode();

	int cntClear;
	int cntGameOver;


};



#endif














