#ifndef _CHARACTTER_DAMAGEAREA_ABSTRACTDAMAGEAREA_H_
#define _CHARACTTER_DAMAGEAREA_ABSTRACTDAMAGEAREA_H_

#include "SystemHub.h"
#include "Debug.h"
#include "GSystem.h"
#include "Vec2.h"
#include "GRectangle.h"
#include "GCircle.h"

class AbstractDamageArea
{
public:
	AbstractDamageArea(int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy);
	virtual ~AbstractDamageArea(){}

	virtual HitData IsHitAndDamage(Vec2 position)			= 0;
	virtual HitData IsHitAndDamage(GCircle circle)			= 0;
	virtual HitData IsHitAndDamage(GRectangle rectangle)	= 0;
	virtual void	Draw()									= 0;

	void	Setup(int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy);
	void	Update();
	bool	IsHitPlayer();
	bool	IsHitEnemy();
	HitData	GetHitData();
	bool	GetIsDead();

protected:

private:
	int		maxStayCount;
	int		stayCount;
	HitData	hitData;
	bool	isHitPlayer;
	bool	isHitEnemy;
	bool	isDead;

	void	DestructorCount();




};


#endif


