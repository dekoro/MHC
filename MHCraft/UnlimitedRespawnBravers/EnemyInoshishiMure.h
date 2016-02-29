#ifndef _ENEMY_INOSHISHI_MURE_H_
#define _ENEMY_INOSHISHI_MURE_H_

#include "Enemy.h"

#define MURE_MAX 10

class EnemyInoshishi;

class InoshishiMure
{
private:
	EnemyInoshishi* inoshshis[MURE_MAX];
public:
	InoshishiMure(vector<EnemyInoshishi*>*enemyList);
	~InoshishiMure();
};

#endif