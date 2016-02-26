#ifndef _CHARACTER_DAMAGEAREA_DAMAGEAREAMANAGER_H_
#define _CHARACTER_DAMAGEAREA_DAMAGEAREAMANAGER_H_

#include "GSystemHub.h"
#include "Managers.h"
#include "DamageAreaCircle.h"
#include "DamageAreaRectangle.h"


class DamageAreaManager
{
public:
	DamageAreaManager();
	~DamageAreaManager();

	void Initialize();
	SceneMediateData Update();
	void Draw();
	void Finalize();

	void AddDamageAreaCircle(GCircle hitArea, int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy);
	void AddDamageAreaRectangle(GRectangle hitArea, int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy);
	HitData CheckAllHitCircle(GCircle target, bool isTargetPlayer, bool isTargetEnemy);
	void RefleshDamageArea();

private:
	vector<AbstractDamageArea*> damageAreaList;
	Managers* managers;
	void RemoveDamageArea(int index);
	void ClearDamageArea();
};



#endif



