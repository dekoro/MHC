#include "DamageAreaCircle.h"

DamageAreaCircle::DamageAreaCircle(GCircle hitArea, int stayCount, bool isToPlayer, bool isToEnemy) :AbstractDamageArea(stayCount, isToPlayer, isToEnemy){
	this->hitArea = hitArea;
}

bool DamageAreaCircle::CheckIsHit(Vec2 position){
	return (GMath::CheckHitCircleToPoint(hitArea, position));
}

bool DamageAreaCircle::CheckIsHit(GCircle circle){
	return (GMath::CheckHitCircleToCircle(hitArea, circle));
}

bool DamageAreaCircle::CheckIsHit(GRectangle rectangle){
	return (GMath::CheckHitCircleToRectangle(hitArea, rectangle));
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






