#include "Enemy_Test.h"

Enemy_Test::Enemy_Test(DamageAreaManager* damageAreaManager, vector<Enemy*>* enemyList) :Enemy(damageAreaManager, enemyList, imageAsset_Enemy_Test){
	Vec2 pos					= Vec2::Setup((float)GetRand(Window::WIDTH), (float)GetRand(Window::HEIGHT));
	CharacterInformation prm	= CharacterInformation::Setup(2, 0, 1, 30, 2, 32);
	SetupData(pos, prm);
	Initialize();
}

Enemy_Test::~Enemy_Test(){

}

void Enemy_Test::Initialize(){
	isDead = false;
	isUse  = true;
}

void Enemy_Test::Update(){
	if (!isUse)			{ return; }
	if (target == NULL)	{ GetTarget(); }
	Enemy::Update();
	if (!isDead)		{ Move(); }
}

void Enemy_Test::Draw(){
	int posX = position.GetIntX();
	int posY = position.GetIntY();
	device->Image()->DrawRotation(imageData->GetImageHandle(), position.GetIntX(), position.GetIntY(), angleDeg);
}

void Enemy_Test::Move(){
	if (target == nullptr){ return; }
	Vec2 targetPos			=  target->GetPosition();
	Vec2 toTarget			=  targetPos - position;
	Vec2 toTargetNormalize	=  Vec2::Normalize(toTarget);
	Vec2 moveTo				=  Vec2::Normalize(target->GetPosition() - position) * parameter.speed;
	position				+= moveTo;
}

HitData Enemy_Test::CalcAttackToPlayer(Vec2 posOther, double rangeOther){
	if (IsHitToPlayer(posOther, rangeOther)){
		return HitData::Setup(position, parameter.pushPower, parameter.attackPower);
	}
	return HitData::NoHit();
}

