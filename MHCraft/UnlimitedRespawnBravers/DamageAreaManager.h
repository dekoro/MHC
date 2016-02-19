#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREAMANAGER_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREAMANAGER_H_

#include "GSystemHub.h"
class AbstractDamageArea;
class DamageAreaCircle;
class DamageAreaRectangle;


class DamageAreaManager
{
public:
	DamageAreaManager();
	~DamageAreaManager();

	void	Initialize();
	void	Update();
	void	Draw();
	void	Finalize();

	void	AddDamageAreaCircle(GCircle hitArea, int stayCount, bool isToPlayer, bool isToEnemy);
	void	AddDamageAreaRectangle(GRectangle hitArea, int stayCount, bool isToPlayer, bool isToEnemy);
	HitData	CheckAllHitCircle(GCircle target, bool isTargetPlayer, bool isTargetEnemy);
	void	RefleshDamageArea();

private:
	std::vector<AbstractDamageArea*> damageAreaList;
	void	RemoveDamageArea(int index);
	void	ClearDamageArea();
};



#endif



