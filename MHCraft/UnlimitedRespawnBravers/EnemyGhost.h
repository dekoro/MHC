#ifndef _CHARACTER_ENEMY_ENEMY_GHOST_H_
#define _CHARACTER_ENEMY_ENEMY_GHOST_H_

#include "Enemy.h"

class EnemyGhost : public Enemy
{
public:
	EnemyGhost(DamageAreaManager* damageAreaManager, vector<Enemy*>* enemyList);
	~EnemyGhost();
	void	Initialize();
	void	Update() override;
	void	Draw();
	void	Move();
	void	DamageAction(HitData hitData);

private:
	AnimeData*	animeData;
	double		angleDeg;
	double		startSpeed;
	double		maxSpeed;
	double		accelSpeed;
	int			cntSetup;

	void		GetRandomTarget(int forbiddenTarget);
	HitData		CalcAttackToPlayer(Vec2 posOther, double rangeOther);
	void		SetTarget(int targetIndex);
	void		Accelarate();
};


#endif






