#include "DamageAreaRectangle.h"
#include "DamageAreaCircle.h"
#include "GSystem.h"
#include "GCircle.h"
#include "Debug.h"
#include "IHittable.h"

DamageAreaRectangle::DamageAreaRectangle(GRectangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter) :AbstractDamageArea(stayCount, hitData, isToPlayer, isToEnemy, hitter){
	this->hitArea = hitArea;
}

HitData DamageAreaRectangle::CheckIsHitAndDamage(Vec2 position){
	if (GMath::CheckHitRectangleToPoint(hitArea, position)) { return GetHitData(); }
	return HitData::NoHit();
}
HitData DamageAreaRectangle::CheckIsHitAndDamage(GCircle circle){
	if (GMath::CheckHitCircleToRectangle(circle, hitArea)) { return GetHitData(); }
	return HitData::NoHit();
}
HitData DamageAreaRectangle::CheckIsHitAndDamage(GRectangle rectangle){
	if (GMath::CheckHitRectangleToRectangle(hitArea, rectangle)) { return GetHitData(); }
	return HitData::NoHit();
}
HitData DamageAreaRectangle::CheckIsHitAndDamage(AbstractDamageArea * damageArea){
	if (typeid(damageArea) == typeid(AbstractDamageArea)) {
		return damageArea->CheckIsHitAndDamage(hitArea);
	}
	return HitData::NoHit();
}

void DamageAreaRectangle::Draw(){
	Debug::DrawSimpleRectangle(hitArea, GetColor(0, 64, 0));
}

void	DamageAreaRectangle::ChangePosition(GRectangle rectangle){
	hitArea = rectangle;
}

void	DamageAreaRectangle::ChangePosition(Vec2 posision){
	hitArea.X = posision.GetIntX();
	hitArea.Y = posision.GetIntY();
}

