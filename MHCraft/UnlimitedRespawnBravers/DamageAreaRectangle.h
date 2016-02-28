#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREARECTANGLE_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREARECTANGLE_H_
<<<<<<< HEAD
#include "GSystem.h"
#include "AbstractDamageArea.h"
#include "GRectangle.h"
=======

#include "AbstractDamageArea.h"
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40



class DamageAreaRectangle: public AbstractDamageArea
{
public:
<<<<<<< HEAD
	DamageAreaRectangle(GRectangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter = NULL);
=======
	DamageAreaRectangle(GRectangle hitArea, int stayCount, bool isToPlayer, bool isToEnemy);
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40
	~DamageAreaRectangle(){}

	bool	CheckIsHit(Vec2 position);
	bool	CheckIsHit(GCircle circle);
	bool	CheckIsHit(GRectangle rectangle);
	void	Draw();

	void	ChangePosition(GRectangle rectangle);
	void	ChangePosition(Vec2 posCenter);
private:
	GRectangle hitArea;
};
#endif



