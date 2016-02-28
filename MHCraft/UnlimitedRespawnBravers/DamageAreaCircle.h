#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREACIRCLE_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREACIRCLE_H_

#include "AbstractDamageArea.h"
#include "GCircle.h"

class DamageAreaCircle: public AbstractDamageArea{
public:
	DamageAreaCircle(GCircle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter = NULL);
	~DamageAreaCircle(){}

	HitData CheckIsHitAndDamage(Vec2 position);
	HitData CheckIsHitAndDamage(GCircle circle);
	HitData CheckIsHitAndDamage(GRectangle rectangle);
	HitData CheckIsHitAndDamage(AbstractDamageArea* damageArea);
	void	Draw();
	void	ChangeParameter(GCircle circle);
	void	ChangePosition(Vec2 posCenter);
private:
	GCircle hitArea;
};



#endif





