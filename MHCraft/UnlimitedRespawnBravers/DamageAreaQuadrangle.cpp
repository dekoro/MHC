#include "DamageAreaQuadrangle.h"
#include "DamageAreaCircle.h"
#include "DamageAreaRectangle.h"
#include "GSystem.h"
#include "GRectangle.h"
#include "Debug.h"
#include "Vec2.h"

DamageAreaQuadrangle::DamageAreaQuadrangle(GQuadrangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter)
:AbstractDamageArea(stayCount, hitData, isToPlayer, isToEnemy, hitter) {
	this->damageArea		= hitArea;
}

HitData DamageAreaQuadrangle::CheckIsHitAndDamage(Vec2 position){
	if (GMath::CheckHitCircleToQuadrangle(GCircle::Setup(position, 0.001), damageArea)) { return GetHitData(); }
	return HitData::NoHit();
}

HitData DamageAreaQuadrangle::CheckIsHitAndDamage(GCircle circle){
	if (GMath::CheckHitCircleToQuadrangle(circle, damageArea)) { return GetHitData(); }
	return HitData::NoHit();
}

HitData DamageAreaQuadrangle::CheckIsHitAndDamage(GRectangle rectangle){
	return HitData::NoHit();
}

HitData DamageAreaQuadrangle::CheckIsHitAndDamage(AbstractDamageArea* damageArea){
	return HitData::NoHit();
}

void DamageAreaQuadrangle::Draw(){
//	Debug::DrawSimpleQuadrangle(damageArea, GetColor(255, 128, 128));
}

void DamageAreaQuadrangle::ChangeParameter(GQuadrangle quadrangle){
	damageArea = quadrangle;
}












