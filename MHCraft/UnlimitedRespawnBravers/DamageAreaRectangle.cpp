        #include "DamageAreaRectangle.h"

DamageAreaRectangle::DamageAreaRectangle(GRectangle hitArea, int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy) :AbstractDamageArea(stayCount, hitData, isToPlayer, isToEnemy){
	this->hitArea = hitArea;
}



HitData DamageAreaRectangle::IsHitAndDamage(Vec2 position){
	if (GMath::CheckHitRectangleToPoint(hitArea, position)){
		return GetHitData();
	}
	return HitData::NoHit();
}

HitData DamageAreaRectangle::IsHitAndDamage(GCircle circle){
	if (GMath::CheckHitCircleToRectangle(circle, hitArea)){
		return GetHitData();
	}
	return HitData::NoHit();
}

HitData DamageAreaRectangle::IsHitAndDamage(GRectangle rectangle){
	if (GMath::CheckHitRectangleToRectangle(hitArea, rectangle)){
		return GetHitData();
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







