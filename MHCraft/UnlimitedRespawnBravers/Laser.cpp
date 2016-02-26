#include "Laser.h"
#include "Macro.h"
#include "DamageAreaManager.h"


Laser::Laser(DamageAreaManager* damageAreaManager){
	this->damageAreaManager = damageAreaManager;
}

Laser::~Laser(){}



void Laser::Set(double width, double height, Vec2 shotPosition, double angleDeg, double lengthFromShotPosition, int knockBackPower, int damage, double speed, int liveCount){
	Vec2 point1position = Vec2::Setup(shotPosition.X + lengthFromShotPosition, shotPosition.Y - height / 2);
	GQuadrangle damageArea = GQuadrangle::Setup(point1position.X, point1position.Y, width, height);
	damageArea.Rotate(shotPosition, GMath::ChangeDegToRad(angleDeg));
	HitData hitData = HitData::Setup(damageArea.GetCenterPosition(), knockBackPower, damage);
	angleRad = GMath::ChangeDegToRad(angleDeg);
	Setup(damageArea, hitData, Vec2::GetVelocityFromDeg(angleDeg), speed, liveCount);
}
void Laser::Set(double width, double height, Vec2 shotPosition, Vec2 velocity, double lengthFromShotPosition, int knockBackPower, int damage, double speed, int liveCount){
	Set(width, height, shotPosition, velocity.GetAngleDeg(), lengthFromShotPosition, knockBackPower, damage, speed, liveCount);
}
void Laser::Set(LaserData laserData){
	Set(laserData.width,
		laserData.height,
		laserData.shotPosition,
		laserData.velocity,
		laserData.lengthFromShotPosition,
		laserData.knockBackPower,
		laserData.damage,
		laserData.speed,
		laserData.liveCount);
}

void Laser::Initialize(){
	isUse = false;
}

void Laser::Update(){
	Move();
	CheckDead();
}
void Laser::Draw(){
	GQuadrangle quadrangle = damageArea->damageArea;
	VECTOR pos1 = VGet((quadrangle.x4 - quadrangle.x1) / 2 + quadrangle.x1, (quadrangle.y4 - quadrangle.y1) / 2 + quadrangle.y1, 0);
	VECTOR pos2 = VGet(quadrangle.x2, quadrangle.y2, 0);
	VECTOR pos3 = VGet(quadrangle.x3, quadrangle.y3, 0);


	DrawTriangle3D(pos1, pos2, pos3, GetColor(255, 255, 255), 1);
//	Debug::DrawSimpleQuadrangle(damageArea->damageArea, GetColor(255, 255, 255));
}

bool Laser::GetIsUse(){
	return (liveCounter > 0);
}

void Laser::Kill(){
	isUse = false;
	damageArea->Kill();
}

void Laser::Move(){
	if (moveVeclocity == Vec2::Zero()){ return; }
	GQuadrangle area = damageArea->damageArea;
	area.MoveVector(moveVeclocity*speed);
	damageArea->damageArea = area;
}

void Laser::Setup(GQuadrangle damageArea, HitData hitData, Vec2 velocity, float speed, int liveCount){
	this->speed			= speed;
	this->damageArea	= damageAreaManager->AddDamageAreaQuadrangle(damageArea, hitData, 120, true, true);
	this->liveCounter	= liveCount;
	this->isUse			= true;
	position = damageArea.GetCenterPosition();
	if (velocity == Vec2::Zero()){ moveVeclocity = Vec2::Zero(); }
	else{ moveVeclocity = Vec2::Normalize(velocity); }
}

void Laser::CheckDead(){
	if (GMath::OnField(position.GetIntX(), position.GetIntY())){ liveCounter = 0; }
	if (--liveCounter < 0){
		Kill();
	}

}

LaserData LaserData::Setup(double width, double height, Vec2 shotPosition, Vec2 velocity, double lengthFromShotPosition, int knockBackPower, int damage, double speed, int liveCount){
	LaserData tmp;
	tmp.width					= width;
	tmp.height					= height;
	tmp.shotPosition			= shotPosition;
	tmp.velocity				= velocity;
	tmp.lengthFromShotPosition	= lengthFromShotPosition;
	tmp.knockBackPower			= knockBackPower;
	tmp.damage					= damage;
	tmp.speed					= speed;
	tmp.liveCount				= liveCount;
	return tmp;
}



