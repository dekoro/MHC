#include "Laser.h"
#include "Macro.h"
#include "DamageAreaManager.h"


Laser::Laser(DamageAreaManager* damageAreaManager, double width, double height, Vec2 shotPosition, double angleDeg, double lengthFromShotPosition, int knockBackPower, int damage, double speed){
	Vec2 point1position = Vec2::Setup(shotPosition.X + lengthFromShotPosition, shotPosition.Y - height / 2);
	GQuadrangle damageArea = GQuadrangle::Setup(point1position, point1position + Vec2::Setup(width, 0), point1position + Vec2::Setup(width, height), point1position + Vec2::Setup(0, height));
	damageArea.Rotate(shotPosition, GMath::ChangeDegToRad(angleDeg));

	Setup(damageAreaManager, damageArea, HitData::Setup(damageArea.GetCenterPosition(), knockBackPower, damage), Vec2::GetVelocityFromDeg(angleDeg), speed);
}

Laser::Laser(DamageAreaManager* damageAreaManager, double width, double height, Vec2 shotPosition, Vec2 velocity, double lengthFromShotPosition, int knockBackPower, int damage, double speed){
	Vec2 point1position = Vec2::Setup(shotPosition.X + lengthFromShotPosition, shotPosition.Y - height / 2);
	double angleDeg = velocity.GetAngleDeg();
	GQuadrangle damageArea = GQuadrangle::Setup(point1position.X, point1position.Y, width, height);
	damageArea.Rotate(shotPosition, GMath::ChangeDegToRad(angleDeg));

	Setup(damageAreaManager, damageArea, HitData::Setup(damageArea.GetCenterPosition(), knockBackPower, damage), Vec2::GetVelocityFromDeg(angleDeg), speed);

}

Laser::~Laser(){}

void Laser::Setup(DamageAreaManager* damageAreaManager, GQuadrangle damageArea, HitData hitData, Vec2 velocity, float speed){
	this->speed = speed;
	this->damageArea = damageAreaManager->AddDamageAreaQuadrangle(damageArea, hitData, 120, true, true);
	position = damageArea.GetCenterPosition();
	if (velocity == Vec2::Zero()){ moveVeclocity = Vec2::Zero(); }
	else{ moveVeclocity = Vec2::Normalize(velocity); }
}

void Laser::Initialize(){}

void Laser::Update(){
	Move();
}
void Laser::Draw(){
	Debug::DrawSimpleQuadrangle(damageArea->damageArea, GetColor(255, 255, 255));
}

bool Laser::GetIsDead(){
	return false;
}

void Laser::Move(){
	if (moveVeclocity == Vec2::Zero()){ return; }
	GQuadrangle area = damageArea->damageArea;
	area.MoveVector(moveVeclocity*speed);
	damageArea->damageArea = area;
}






