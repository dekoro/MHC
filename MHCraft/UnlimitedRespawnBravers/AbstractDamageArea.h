#ifndef _CHARACTTER_DAMAGEAREA_ABSTRACTDAMAGEAREA_H_
#define _CHARACTTER_DAMAGEAREA_ABSTRACTDAMAGEAREA_H_

#include "GSystem.h"
class Vec2;
class GRectangle;
class GCircle;
class GQuadrangle;
class IHittable;

class AbstractDamageArea
{
public:
	AbstractDamageArea(int stayCount, HitData hitData, bool hittabeToPlayer, bool hittableToEnemy, IHittable* hitter = NULL);
	virtual ~AbstractDamageArea(){}

	virtual HitData CheckIsHitAndDamage(Vec2 position)					= 0;
	virtual HitData CheckIsHitAndDamage(GCircle circle)					= 0;
	virtual HitData CheckIsHitAndDamage(GRectangle rectangle)			= 0;
	virtual HitData CheckIsHitAndDamage(AbstractDamageArea* damageArea)	= 0;
	virtual void Draw()													= 0;

	void	Setup(int stayCount, HitData hitData, bool hittableToPlayer, bool hittableToEnemy);
	void	Update();
	bool	IsHittableToPlayer();
	bool	IsHittableToEnemy();
	bool	GetIsDead();
	HitData	GetHitData();
	void	HitProcess();
	void	Kill();

protected:

private:
	IHittable*	hitter;
	int			maxStayCount;
	int			stayCount;
	int			shooterPlayerNo;
	bool		isHittableToPlayer;
	bool		isHittableToEnemy;
	bool		isDead;
	HitData		hitData;
	void		DestructorCount();




};


#endif


