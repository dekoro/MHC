#ifndef _CHARACTER_ENEMY_ENEMY_TEST_H_
#define _CHARACTER_ENEMY_ENEMY_TEST_H_

#include "Enemy.h"

class Enemy_Test : public Enemy
{
public:
	Enemy_Test(DamageAreaManager* damageAreaManager, vector<Enemy*>* enemyList);
	~Enemy_Test();
	void Initialize();
	void Update() override;
	void Draw();
	void Move();
	//void CheckHit();

private:
	AnimeData*		animeData;
	double			angleDeg;

	void	GetRandomTarget(int forbiddenTarget);
	HitData	CalcAttackToPlayer(Vec2 posOther, double rangeOther);
};


#endif









