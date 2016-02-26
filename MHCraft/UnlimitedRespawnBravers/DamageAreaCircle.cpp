#include "DamageAreaCircle.h"
#include "DamageAreaRectangle.h"
#include "GSystem.h"
#include "GRectangle.h"
#include "Debug.h"
#include "Vec2.h"

DamageAreaCircle::DamageAreaCircle(GCircle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy)
	:AbstractDamageArea(stayCount, hitData, isToPlayer, isToEnemy){
	this->hitArea = hitArea;
}

HitData DamageAreaCircle::CheckIsHitAndDamage(Vec2 position) {
	if (GMath::CheckHitCircleToPoint(hitArea, position)) { return GetHitData(); }
	return HitData::NoHit();
}
HitData DamageAreaCircle::CheckIsHitAndDamage(GCircle circle) {
	if (GMath::CheckHitCircleToCircle(hitArea, circle)) { return GetHitData(); }
	return HitData::NoHit();
}
HitData DamageAreaCircle::CheckIsHitAndDamage(GRectangle rectangle) {
	if (GMath::CheckHitCircleToRectangle(hitArea, rectangle)) { return GetHitData(); }
	return HitData::NoHit();
}
HitData DamageAreaCircle::CheckIsHitAndDamage(AbstractDamageArea * damageArea){
	if (typeid(damageArea) == typeid(AbstractDamageArea)) {
		return damageArea->CheckIsHitAndDamage(hitArea);
	}
	return HitData::NoHit();
}

void DamageAreaCircle::Draw(){
	Debug::DrawSimpleCircle(hitArea, GetColor(255, 128, 128));
}

void DamageAreaCircle::ChangeParameter(GCircle circle){
	hitArea = circle;
}

void DamageAreaCircle::ChangePosition(Vec2 posCenter){
	hitArea.posCenter = posCenter;
}






