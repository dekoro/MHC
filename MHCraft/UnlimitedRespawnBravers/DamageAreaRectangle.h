#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREARECTANGLE_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREARECTANGLE_H_
#include "GSystem.h"
#include "AbstractDamageArea.h"
#include "GRectangle.h"



class DamageAreaRectangle: public AbstractDamageArea
{
public:
	DamageAreaRectangle(GRectangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter = NULL);
	~DamageAreaRectangle(){}

	HitData	CheckIsHitAndDamage(Vec2 position);
	HitData	CheckIsHitAndDamage(GCircle circle);
	HitData	CheckIsHitAndDamage(GRectangle rectangle);
	HitData	CheckIsHitAndDamage(AbstractDamageArea* damageArea);
	void	Draw();

	void	ChangePosition(GRectangle rectangle);
	void	ChangePosition(Vec2 posCenter);
private:
	GRectangle hitArea;
};
#endif



