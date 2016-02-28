#include "DamageAreaCircle.h"
<<<<<<< HEAD
#include "DamageAreaRectangle.h"
#include "GSystem.h"
#include "GRectangle.h"
#include "Debug.h"
#include "Vec2.h"

DamageAreaCircle::DamageAreaCircle(GCircle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter)
	:AbstractDamageArea(stayCount, hitData, isToPlayer, isToEnemy, hitter){
=======

DamageAreaCircle::DamageAreaCircle(GCircle hitArea, int stayCount, bool isToPlayer, bool isToEnemy) :AbstractDamageArea(stayCount, isToPlayer, isToEnemy){
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40
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






