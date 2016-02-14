#include "Enemy.h"
#include "DamageAreaManager.h"

Enemy::Enemy(vector<Enemy*>* enemyList, IMAGE_ASSET_NAME assetName){
	enemyList->push_back(this);
	device			= DeviceManager::GetInstance();
	managers		= Managers::GetInstance();
	cntDead			= 30;
	isDead			= false;
	isUse			= true;
	isInvincible	= true;
	this->assetName	= assetName;
}

Enemy::~Enemy(){
	SAFE_DELETE(imageData);
}

void Enemy::SetupData(Vec2 startPos, CharacterInformation chParam, bool isKnockback){
	this->imageData		= device->Image()->CopyImageData(assetName);
	this->position		= startPos;
	this->parameter		= chParam;
	this->isKnockBack	= isKnockback;
}

void Enemy::Update(){
	CheckHitDamageArea();
	CountDeadTimer();
}


void Enemy::ResearchTarget(int forbiddenTarget){
	GetTarget(forbiddenTarget);
}

void Enemy::GetTarget(int forbiddenTarget){
	if (target != NULL && target->GetPadNo() != forbiddenTarget){ return; }
	GetRandomTarget(forbiddenTarget);
}

void Enemy::CalcDamage(HitData hitData){
	parameter.health -= hitData.damage;
	Knockback(hitData.fromPosition, position, hitData.knockbackPower);
}

void Enemy::CheckHitDamageArea(){
	if (isInvincible){ return; }
	HitData hit = managers->Damage()->CheckAllHitCircle(GCircle::Setup(position, parameter.hitRange), false, true);
	if (hit == HitData::NoHit()){ return; }
	Damage(hit.damage);
	if (isKnockBack){
		Knockback(hit.fromPosition, position, hit.knockbackPower);
	}
	DamageAction(hit);
	return;
}

bool Enemy::GetIsUse(){
	return isUse;
}


bool Enemy::GetIsDead(){
	return isDead;
}
CharacterInformation Enemy::GetParameter(){
	return parameter;
}

Vec2 Enemy::GetPosition(){
	return position;
}

IMAGE_ASSET_NAME Enemy::GetAssetName(){
	return assetName;
}

//----protected----



//-----private-----

void Enemy::GetRandomTarget(int forbiddenTarget){
}

void Enemy::SetTarget(int targetIndex){
	this->target = managers->Player()->GetPlayerData(targetIndex);
}

void Enemy::Damage(int damage){
	parameter.health -= damage;
	CheckIsDead();
}

void Enemy::CheckIsDead(){
	isDead = (isDead || parameter.health <= 0);
	if (isDead){
		device->Sound()->Play(SE_Kill);
	}else{
		device->Sound()->Play(SE_Attack);
	}
}

void Enemy::Heal(int heal){
	parameter.health += heal;
	parameter.health = (parameter.health > parameter.maxHealth)? parameter.maxHealth: parameter.health;

}

void Enemy::CheckIsOverHeal(){
	if (parameter.health <= parameter.maxHealth){ return; }
	parameter.health = parameter.maxHealth;
}

void Enemy::CountDeadTimer(){
	if (!isDead){ return; }
	cntDead--;
	if (cntDead > 0){ return; }
	isUse = false;
}

void Enemy::Knockback(Vec2 fromPos, Vec2 toPos, int power){
	Knockback(GMath::CalcAngleRad(fromPos, toPos), power);
}

void Enemy::Knockback(double angleRad, int power){
	Vec2 knockBackVec;
	knockBackVec.SetupSelf((float)(cos(angleRad)), (float)(sin(angleRad)));

	position += knockBackVec * power;
}

bool Enemy::IsHitToPlayer(Vec2 posOther, double rangeOther){
	return (GMath::CheckHitCircleToCircle(this->position, parameter.hitRange, posOther, rangeOther));
}




