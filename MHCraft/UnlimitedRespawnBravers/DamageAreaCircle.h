#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREACIRCLE_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREACIRCLE_H_

#include "AbstractDamageArea.h"

class DamageAreaCircle: public AbstractDamageArea
{
public:
	DamageAreaCircle(GCircle hitArea, int stayCount, bool isToPlayer, bool isToEnemy);
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





