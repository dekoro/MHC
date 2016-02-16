#include "EnemyGhost.h"
#include "DeviceManager.h"
#include "Player.h"
#include "PlayerManager.h"
#include "EnemyManager.h"


EnemyGhost::EnemyGhost(std::vector<Enemy*>* enemyList) :Enemy(enemyList, imageAsset_Enemy_Ghost){
	device		= DeviceManager::GetInstance();
	Vec2 pos	= Vec2::Setup((float)GetRand(Window::WIDTH), (float)GetRand(Window::HEIGHT));
	startSpeed	= 0.05;
	maxSpeed	= 4;
	accelSpeed	= 0.005;
	cntSetup	= 30;

	CharacterInformation prm = CharacterInformation::Setup(2, 0, 1, 30, startSpeed, 20);
	SetupData(pos, prm);
	Initialize();
}

EnemyGhost::~EnemyGhost(){
}

void EnemyGhost::Initialize(){

}

void EnemyGhost::Update(){
	if (!isUse)			{ return; }
	if (--cntSetup > 0)	{ return; }
	if (target == NULL)	{ GetTarget(); }
	isInvincible = false;
	Enemy::Update();
	Accelarate();
	if (!isDead)		{ Move(); }
}

void EnemyGhost::Draw(){
	if (cntSetup >0	&& cntSetup % 4 <= 2){ return; }
	if (isDead		&& cntDead  % 4 <= 2){ return; }
	int posX = position.GetIntX();
	int posY = position.GetIntY();
	
	if (!isDead){
		device->Image()->DrawRotation(imageData->GetImageHandle(), position.GetIntX(), position.GetIntY(), angleDeg);
	}
	else
	{
		cutEffect.Cut(imageData->GetImageHandle(), position);
	}
}

void EnemyGhost::Move(){
	if (target == nullptr){ return; }
	Vec2 targetPos			=  target->GetPosition();
	Vec2 toTarget			=  targetPos - position;
	Vec2 toTargetNormalize	=  Vec2::Normalize(toTarget);
	Vec2 moveTo				=  Vec2::Normalize(target->GetPosition() - position) * parameter.speed;
	position				+= moveTo;
}

//-----private-----
//void EnemyGhost::GetRandomTarget(int forbiddenTarget){
//	std::vector<int> plList	= playerManager->GetEnablePlayerIndexList();
//	int			plNum	= plList.size();
//	target				= NULL;
//	if (plNum <= 0){
//		return;
//	}
//
//	if (plNum == 1 && plList[0] == forbiddenTarget){
//		return;
//	}
//
//	while (true){
//		int targetIndex = GetRand(plNum - 1);
//		if (plList[targetIndex] == forbiddenTarget){ continue; }
//		SetTarget(plList[targetIndex]);
//		break;
//	}
//}

HitData	EnemyGhost::CalcAttackToPlayer(Vec2 posOther, double rangeOther){
	if (IsHitToPlayer(posOther, rangeOther)){
		parameter.speed *= (1.0 / 4);
		return HitData::Setup(position, parameter.pushPower, parameter.attackPower);
	}
	return HitData::NoHit();
}

//void	EnemyGhost::SetTarget(int targetIndex){
//	this->target = managers->Player()->GetPlayerData(targetIndex);
//}

void EnemyGhost::Accelarate(){
	parameter.speed = (parameter.speed < maxSpeed) ? parameter.speed + accelSpeed : maxSpeed;
}

void EnemyGhost::DamageAction(HitData hitData){
	parameter.speed *= (1.0 / 2);
}









