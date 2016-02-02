#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREACIRCLE_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREACIRCLE_H_

#include "AbstractDamageArea.h"

class DamageAreaCircle: public AbstractDamageArea
{
public:
	DamageAreaCircle(GCircle hitArea, int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy);
	~DamageAreaCircle(){}

	HitData IsHitAndDamage(Vec2 position);
	HitData IsHitAndDamage(GCircle circle);
	HitData IsHitAndDamage(GRectangle rectangle);
	void	Draw();

	void	ChangePosition(GCircle circle);
	void	ChangePosition(Vec2 posCenter);
private:
	GCircle hitArea;


};



#endif





