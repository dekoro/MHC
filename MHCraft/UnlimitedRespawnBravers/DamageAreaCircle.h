#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREACIRCLE_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREACIRCLE_H_

#include "AbstractDamageArea.h"

class DamageAreaCircle: public AbstractDamageArea
{
public:
<<<<<<< HEAD
	DamageAreaCircle(GCircle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter = NULL);
=======
	DamageAreaCircle(GCircle hitArea, int stayCount, bool isToPlayer, bool isToEnemy);
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40
	~DamageAreaCircle(){}

	bool CheckIsHit(Vec2 position);
	bool CheckIsHit(GCircle circle);
	bool CheckIsHit(GRectangle rectangle);
	void	Draw();

	void	ChangeParameter(GCircle circle);
	void	ChangePosition(Vec2 posCenter);
private:
	GCircle hitArea;
};



#endif





