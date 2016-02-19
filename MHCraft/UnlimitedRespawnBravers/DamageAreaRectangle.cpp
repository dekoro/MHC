        #include "DamageAreaRectangle.h"

DamageAreaRectangle::DamageAreaRectangle(GRectangle hitArea, int stayCount, bool isToPlayer, bool isToEnemy) :AbstractDamageArea(stayCount, isToPlayer, isToEnemy){
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







