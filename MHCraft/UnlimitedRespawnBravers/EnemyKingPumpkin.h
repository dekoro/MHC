#ifndef _CHARACTER_ENEMY_ENEMYGHOST_H_
#define _CHARACTER_ENEMY_ENEMYGHOST_H_

#include "Enemy.h"
class EnemyManager;
class DeiceManager;
class EnemyKingPumpkin: public Enemy
{
public:
	EnemyKingPumpkin(std::vector<Enemy*>* enemyList);
	~EnemyKingPumpkin();

	void	Initialize();
	void	Update() override;
	void	Draw();
	HitData	CalcAttackToPlayer(Vec2 posOther, double rangeOther);
	void	DeadPlayerAction() override;
	void	DamageAction(HitData hitData);

	void CountDeadTimer() override;
private:
	Vec2	moveVelocity;
	int		cntInvisible;
	bool	isBoundMode;
	int		cntChange;
	int		maxCntChange;
	int		countForDeadEffect;

	void	Damage(int damage) override;
	void	Move();
	void	CountdownInvisible();
	bool	IsDisp();
	void	CheckHitWall();
	void	Breaking();
	void	ThroughWall();
	void	BountingWall();
	void	ChangeMode();
	void	DeadEffect();
	void	AttackAllEnemy();
	void	DispInfoRegister();

	
};

#endif





