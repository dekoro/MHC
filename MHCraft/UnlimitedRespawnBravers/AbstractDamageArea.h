#ifndef _CHARACTTER_DAMAGEAREA_ABSTRACTDAMAGEAREA_H_
#define _CHARACTTER_DAMAGEAREA_ABSTRACTDAMAGEAREA_H_

#include "SystemHub.h"
#include "Debug.h"
#include "GSystem.h"
<<<<<<< HEAD
class Vec2;
class GRectangle;
class GCircle;
class GQuadrangle;
class IHittable;
=======
#include "Vec2.h"
#include "GRectangle.h"
#include "GCircle.h"
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40

class AbstractDamageArea
{
public:
<<<<<<< HEAD
	AbstractDamageArea(int stayCount, HitData hitData, bool hittabeToPlayer, bool hittableToEnemy, IHittable* hitter = NULL);
	virtual ~AbstractDamageArea(){}

	virtual HitData CheckIsHitAndDamage(Vec2 position)					= 0;
	virtual HitData CheckIsHitAndDamage(GCircle circle)					= 0;
	virtual HitData CheckIsHitAndDamage(GRectangle rectangle)			= 0;
	virtual HitData CheckIsHitAndDamage(AbstractDamageArea* damageArea)	= 0;
	virtual void Draw()													= 0;
=======
	AbstractDamageArea(int stayCount, bool hittabeToPlayer, bool hittableToEnemy);
	virtual ~AbstractDamageArea(){}

	virtual bool CheckIsHit(Vec2 position)			= 0;
	virtual bool CheckIsHit(GCircle circle)			= 0;
	virtual void Draw()								= 0;
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40

	void	Setup(int stayCount, bool hittableToPlayer, bool hittableToEnemy);
	void	Update();
	bool	IsHittableToPlayer();
	bool	IsHittableToEnemy();
	bool	GetIsDead();
<<<<<<< HEAD
	HitData	GetHitData();
	void	HitProcess();
	void	Kill();
=======
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40

protected:

private:
<<<<<<< HEAD
	IHittable*	hitter;
	int			maxStayCount;
	int			stayCount;
	int			shooterPlayerNo;
	bool		isHittableToPlayer;
	bool		isHittableToEnemy;
	bool		isDead;
	HitData		hitData;
	void		DestructorCount();
=======
	int		maxStayCount;
	int		stayCount;
	bool	isHittableToPlayer;
	bool	isHittableToEnemy;
	bool	isDead;

	void	DestructorCount();
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40




};


#endif


