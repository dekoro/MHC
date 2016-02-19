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
	AbstractDamageArea(int stayCount, bool hittabeToPlayer, bool hittableToEnemy);
	virtual ~AbstractDamageArea(){}

	virtual bool CheckIsHit(Vec2 position)			= 0;
	virtual bool CheckIsHit(GCircle circle)			= 0;
	virtual void Draw()								= 0;

	void	Setup(int stayCount, bool hittableToPlayer, bool hittableToEnemy);
	void	Update();
	bool	IsHittableToPlayer();
	bool	IsHittableToEnemy();
	bool	GetIsDead();

protected:

private:
	int		maxStayCount;
	int		stayCount;
	bool	isHittableToPlayer;
	bool	isHittableToEnemy;
	bool	isDead;

	void	DestructorCount();




};


#endif


