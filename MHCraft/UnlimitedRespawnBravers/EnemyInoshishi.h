#ifndef _CHARACTER_ENEMY_ENEMY_INOSHISHI_
#define _CHARACTER_ENEMY_ENEMY_INOSHISHI_
#include "Enemy.h"

class Player;


int GetGroupCount(int, vector<Enemy*>);
int GetSpaceGroupNum(vector<Enemy*>);

class EnemyInoshishi : public Enemy
{
public:
	EnemyInoshishi(vector<Enemy*>*enemyList);
	~EnemyInoshishi();
	void Initialize();
	void Draw() override;
	void Update() override;
	void Move();
	void DamageAction(HitData hitData);
	BOOL IsElder();
	Player* Target();
	EnemyInoshishi* Elder();
	void MoveTo(Vec2);
	void SetSpeedToElder();
	int GetGroupNum();
private:
	double angle;
	int moveCount,maxMoveCount;
	int stopCount;
	int state;
	Player* target;
	Vec2 speed;
	EnemyInoshishi* elder;
	BOOL isElder;
	int group;
private:
	HitData CalcAttackToPlayer(Vec2 posOther, double rangeOher);
	void SetStopCount(int min, int max);
	void SetMoveCount();
	void UpdateCount();
	void Stop();
	void SetAngle();
	void SetSpeed();
	void SerchPlayer();
	void MoveToPlayer();
	void CheckTargetPlayer();
	void SetTarget(int);
	void SetSpeedToPlayer();
	BOOL OutOfElderRange(float range);

	static Random *random;
};

#endif _CHARACTER_ENEMY_ENEMY_INOSHISHI_