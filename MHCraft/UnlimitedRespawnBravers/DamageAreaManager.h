#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREAMANAGER_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREAMANAGER_H_

#include "GSystemHub.h"
class AbstractDamageArea;
class DamageAreaCircle;
class DamageAreaRectangle;
<<<<<<< HEAD
class DamageAreaQuadrangle;
class IHittable;
=======

>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40

class DamageAreaManager
{
public:
	DamageAreaManager();
	~DamageAreaManager();

	void	Initialize();
	void	Update();
	void	Draw();
	void	Finalize();

<<<<<<< HEAD
	DamageAreaCircle*		AddDamageAreaCircle(GCircle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter = NULL);
	DamageAreaRectangle*	AddDamageAreaRectangle(GRectangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter = NULL);
	DamageAreaQuadrangle*	AddDamageAreaQuadrangle(GQuadrangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter = NULL);
	HitData	CheckAllHitRectangle(GRectangle target, bool isTargetPlayer, bool isTargetEnemy);
=======
	void	AddDamageAreaCircle(GCircle hitArea, int stayCount, bool isToPlayer, bool isToEnemy);
	void	AddDamageAreaRectangle(GRectangle hitArea, int stayCount, bool isToPlayer, bool isToEnemy);
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40
	HitData	CheckAllHitCircle(GCircle target, bool isTargetPlayer, bool isTargetEnemy);
	void	RefleshDamageArea();

private:
	std::vector<AbstractDamageArea*> damageAreaList;
	void	RemoveDamageArea(int index);
	void	ClearDamageArea();
};



#endif



