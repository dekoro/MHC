#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREARECTANGLE_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREARECTANGLE_H_

#include "AbstractDamageArea.h"

class DamageAreaRectangle: public AbstractDamageArea
{
public:
	DamageAreaRectangle(GRectangle hitArea, int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy);
	~DamageAreaRectangle(){}

	HitData IsHitAndDamage(Vec2 position);
	HitData IsHitAndDamage(GCircle circle);
	HitData IsHitAndDamage(GRectangle rectangle);
	void	Draw();

	void	ChangePosition(GRectangle rectangle);
	void	ChangePosition(Vec2 posision);
private:
	GRectangle hitArea;
};






#endif



