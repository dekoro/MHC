#ifndef _CHARACTER_DAMAGEAREAQUADRANGLE_H_
#define _CHARACTER_DAMAGEAREAQUADRANGLE_H_

#include "AbstractDamageArea.h"
#include "GQuadrangle.h"

class DamageAreaQuadrangle :public AbstractDamageArea {
public:
	DamageAreaQuadrangle(GQuadrangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy);
	~DamageAreaQuadrangle() {}

	GQuadrangle damageArea;

	HitData CheckIsHitAndDamage(Vec2 position);
	HitData CheckIsHitAndDamage(GCircle circle);
	HitData CheckIsHitAndDamage(GRectangle rectangle);
	HitData CheckIsHitAndDamage(AbstractDamageArea* damageArea);
	void	Draw();
	void	ChangeParameter(GQuadrangle quadrangle);

private:

};



#endif




