
#include "EnemyKingPumpkin.h"
#include "Enemy.h"
#include "Managers.h"
#include "ItemManager.h"
#include "EnemyManager.h"
#include "DamageAreaManager.h"


EnemyKingPumpkin::EnemyKingPumpkin(vector<Enemy*>* enemyList) :Enemy(enemyList, imageAsset_Enemy_BigPumpkin){
	Vec2 pos = Vec2::Setup(640, 300);

	CharacterInformation prm = CharacterInformation::Setup(300, 0, 2, 150, 1, 128);
	moveVelocity = Vec2::One()*-5;
	cntInvisible = 400;
	countForDeadEffect = 0;
	SetupData(pos, prm, false);
	Initialize();
	cntChange = maxCntChange = 300;
}

EnemyKingPumpkin::~EnemyKingPumpkin(){

}


void	EnemyKingPumpkin::Initialize(){
	device->Sound()->Stop(Music_GameMain_BGM_Normal);
	isDead	= false;
	isUse	= true;
}

void EnemyKingPumpkin::Update(){
	CountdownInvisible();
	Move();
	DispInfoRegister();
	Enemy::Update();
	cntChange--;
	if (cntChange <= 0){
		ChangeMode();
		cntChange = maxCntChange;
	}
}

void	EnemyKingPumpkin::Draw(){
	if (!IsDisp()){ return; }
	device->Image()->DrawRotation(imageData->GetImageHandle(), position.GetIntX(), position.GetIntY(), 0);

}

HitData	EnemyKingPumpkin::CalcAttackToPlayer(Vec2 posOther, double rangeOther){
	if (cntInvisible > 0){ return HitData::NoHit(); }
	if (IsHitToPlayer(posOther, rangeOther)){
		return HitData::Setup(position, parameter.pushPower, parameter.attackPower);
	}
	return HitData::NoHit();
}

void EnemyKingPumpkin::DeadPlayerAction(){
	Heal(8);
}

void EnemyKingPumpkin::DamageAction(HitData hitData){
	double angleRad = (GMath::CalcAngleRad(hitData.fromPosition, position));
	Vec2 knockBackVec;
	knockBackVec.SetupSelf((float)(cos(angleRad)), (float)(sin(angleRad)));
	knockBackVec *= 15;
	moveVelocity += knockBackVec;
	double maxSpeed = 10;
	if (moveVelocity.Length() > maxSpeed){ moveVelocity = Vec2::Normalize(moveVelocity) * maxSpeed; }
}

//-----private---
void EnemyKingPumpkin::Damage(int damage){
	int joinNum = managers->Player()->GetJoinNum();
	if (parameter.health > 0){
		parameter.health -= damage*(5 - (joinNum+2) / 4);
	}
	CheckIsDead();
}

void EnemyKingPumpkin::Move(){
	if (cntInvisible > 0){ return; }
	if (isDead){ return; }
	managers->Enemy()->CalcSpawnMob(180);
	position += moveVelocity;
	CheckHitWall();
	Breaking();
}

void EnemyKingPumpkin::CountdownInvisible(){
	if (cntInvisible <= 0){ return; }
	cntInvisible--;
	if (cntInvisible == 0){
		device->Sound()->Play(Music_GameMain_BGM_BOSS);
		isInvincible = false;
	}
}

bool EnemyKingPumpkin::IsDisp(){
	if (cntInvisible <  0){ return false; }
	if (isDead && (cntDead+180) % 6 < 3){
		return false;
	}
	if (cntInvisible == 0)								{ return true; }
	if (cntInvisible <	20 && cntInvisible %  4 < 2)	{ return true; }
	if (cntInvisible < 120 && cntInvisible % 30 < 2)	{ return true; }
	if (cntInvisible % 120  < 2)						{ return true; }
	return false;
}

void EnemyKingPumpkin::CheckHitWall(){
	if (isBoundMode){
		BountingWall();
	} else {
		ThroughWall();
	}
}

void EnemyKingPumpkin::Breaking(){
	if (moveVelocity.Length() < 4){ return; }
	moveVelocity *= (9.95/10);
}

void EnemyKingPumpkin::ThroughWall(){
	Vec2 imageHalfSize = Vec2::Setup((float)imageData->GetSizeHalfImageX(), (float)imageData->GetSizeHalfImageY());
	if (position.X < -imageHalfSize.X)					{ position.X = Window::WIDTH  + imageHalfSize.X; }
	if (position.Y < -imageHalfSize.Y)					{ position.Y = Window::HEIGHT + imageHalfSize.Y; }
	if (position.X > Window::WIDTH + imageHalfSize.X)	{ position.X = -imageHalfSize.X; }
	if (position.Y > Window::HEIGHT + imageHalfSize.Y)	{ position.Y = -imageHalfSize.Y; }
}

void EnemyKingPumpkin::BountingWall(){
	Vec2 imageHalfSize = Vec2::Setup((float)imageData->GetSizeHalfImageX(), (float)imageData->GetSizeHalfImageY());
	if (position.X - imageHalfSize.X < 0)				{ moveVelocity.X =  abs(moveVelocity.X); }
	if (position.Y - imageHalfSize.Y < 0)				{ moveVelocity.Y =  abs(moveVelocity.Y); }
	if (position.X + imageHalfSize.X > Window::WIDTH)	{ moveVelocity.X = -abs(moveVelocity.X); }
	if (position.Y + imageHalfSize.Y > Window::HEIGHT)	{ moveVelocity.Y = -abs(moveVelocity.Y); }
}


void EnemyKingPumpkin::ChangeMode(){
	if (isDead){ return;  }
	isBoundMode = !isBoundMode;
	imageData->SetAnimeType((isBoundMode) ? 0 : 1);
}

void EnemyKingPumpkin::DeadEffect(){
	if (countForDeadEffect % 3 == 0){
		float  oneSideLength = 192;
		Vec2 dropPosition;
		do{
			dropPosition = Vec2::Setup(position.X + ((float)GetRand((int)oneSideLength * 2) - oneSideLength)
									 , position.Y + ((float)GetRand((int)oneSideLength * 2) - oneSideLength));
		} while (!GMath::CheckHitCircleToPoint(GCircle::Setup(position, (double)oneSideLength), dropPosition));
		managers->Item()->AddItemLollipop(dropPosition);
	}
	countForDeadEffect++;
}

void EnemyKingPumpkin::CountDeadTimer(){
	if (!isDead){ return; }
	cntDead--;
	if (cntDead == 0){ 
		device->Sound()->Play(SE_KillBoss);
		AttackAllEnemy();
	}
	if (cntDead > -180){ return; }
	if (cntDead > -380){
		DeadEffect();
		cntInvisible = -1;
		return;
	}
	if (cntDead > -640){ return; }
	managers->Enemy()->gameMode = GameMode_Clear;
	isUse = false;
}

void EnemyKingPumpkin::AttackAllEnemy(){
	GRectangle attackArea = GRectangle::Setup(-Window::WIDTH, -Window::HEIGHT, Window::WIDTH*3, Window::HEIGHT*3);
	HitData hitData			= HitData::Setup(position, 1, 99999);
	managers->Damage()->AddDamageAreaRectangle(attackArea, 30, hitData, false, true);
}

void EnemyKingPumpkin::DispInfoRegister(){
	if (parameter.health <= 0){ return; }
	UIData ui = UIData::Setup(Vec2::Setup(600, 5), 20, STR("BOSS Žc‚èHP : ",to_string(parameter.health)));
	UI::GetInstance()->AddUI(ui);
}









