<<<<<<< HEAD
#include "DamageAreaRectangle.h"
#include "DamageAreaCircle.h"
#include "GSystem.h"
#include "GCircle.h"
#include "Debug.h"
#include "IHittable.h"

DamageAreaRectangle::DamageAreaRectangle(GRectangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter) :AbstractDamageArea(stayCount, hitData, isToPlayer, isToEnemy, hitter){
=======
        #include "DamageAreaRectangle.h"

DamageAreaRectangle::DamageAreaRectangle(GRectangle hitArea, int stayCount, bool isToPlayer, bool isToEnemy) :AbstractDamageArea(stayCount, isToPlayer, isToEnemy){
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40
	this->hitArea = hitArea;
}

bool DamageAreaRectangle::CheckIsHit(Vec2 position){
	return (GMath::CheckHitRectangleToPoint(hitArea, position));
}

bool DamageAreaRectangle::CheckIsHit(GCircle circle){
	return (GMath::CheckHitCircleToRectangle(circle, hitArea));
}

bool DamageAreaRectangle::CheckIsHit(GRectangle rectangle){
	return (GMath::CheckHitRectangleToRectangle(hitArea, rectangle));
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







