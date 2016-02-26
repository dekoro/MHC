#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREAMANAGER_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREAMANAGER_H_

#include "GSystemHub.h"
class AbstractDamageArea;
class DamageAreaCircle;
class DamageAreaRectangle;
class DamageAreaQuadrangle;


class DamageAreaManager
{
public:
	DamageAreaManager();
	~DamageAreaManager();

	void	Initialize();
	void	Update();
	void	Draw();
	void	Finalize();

	DamageAreaCircle*		AddDamageAreaCircle(GCircle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy);
	DamageAreaRectangle*	AddDamageAreaRectangle(GRectangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy);
	DamageAreaQuadrangle*	AddDamageAreaQuadrangle(GQuadrangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy);
	HitData	CheckAllHitRectangle(GRectangle target, bool isTargetPlayer, bool isTargetEnemy);
	HitData	CheckAllHitCircle(GCircle target, bool isTargetPlayer, bool isTargetEnemy);
	void	RefleshDamageArea();

private:
	std::vector<AbstractDamageArea*> damageAreaList;
	void	RemoveDamageArea(int index);
	void	ClearDamageArea();
};



#endif



