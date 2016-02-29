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
	EnemyManager(DamageAreaManager* damageAreaManager, PlayerManager* playerManager);
	~EnemyManager();
	
	void				Initialize();
	SceneMediateData	Update();
	void				Draw();
	void				Finalize();
	void				AddEnemy(IMAGE_ASSET_NAME asset);
	void				LeaveTarget(int forbiddenTarget);
	HitData				CalcAttackToPlayer(Vec2 position, double hitRadius);
	void				CalcSpawnMob(int rate = 90);
	void				SpawnMob(int spawnNum);
	void				CalcSpawnBoss();
	GameMode			gameMode;
	void				DeadPlayerActioon();
	int					GetLeftEnemyNum();

private:
//	Managers*		managers;

	const int ENEMY_BOSS_NUM = 5;
	const int ENEMY_ENTOURAGE_PER_BOSS = 10;

	vector<Enemy*>		enemyList;
	DeviceManager*		device;
	DamageAreaManager*	damageAreaManager;
	PlayerManager*		playerManager;
	int					stage;
	int					normaLollipop;

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














