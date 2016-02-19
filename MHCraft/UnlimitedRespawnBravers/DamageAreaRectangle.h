#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREARECTANGLE_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREARECTANGLE_H_

#include "AbstractDamageArea.h"

class DamageAreaRectangle: public AbstractDamageArea
{
public:
	DamageAreaRectangle(GRectangle hitArea, int stayCount, bool isToPlayer, bool isToEnemy);
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



