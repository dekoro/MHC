#include "DamageAreaCircle.h"

DamageAreaCircle::DamageAreaCircle(GCircle hitArea, int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy) :AbstractDamageArea(stayCount, hitData, isToPlayer, isToEnemy){
	this->hitArea = hitArea;
}

HitData DamageAreaCircle::IsHitAndDamage(Vec2 position){
	if (GMath::CheckHitCircleToPoint(hitArea, position)){
		return GetHitData();
	}
	return HitData::NoHit();
}

HitData DamageAreaCircle::IsHitAndDamage(GCircle circle){
	if (GMath::CheckHitCircleToCircle(hitArea, circle)){
		return GetHitData();
	}
	return HitData::NoHit();
}

HitData DamageAreaCircle::IsHitAndDamage(GRectangle rectangle){
	if (GMath::CheckHitCircleToRectangle(hitArea, rectangle)){
		return GetHitData();
	}
	return HitData::NoHit();
}

void DamageAreaCircle::Draw(){
	Debug::DrawSimpleCircle(hitArea, GetColor(255, 128, 128));
}

void DamageAreaCircle::ChangePosition(GCircle circle){
	hitArea = circle;
}

void DamageAreaCircle::ChangePosition(Vec2 posCenter){
	hitArea.posCenter = posCenter;
}






