#include "Player.h"
#include "DeviceManager.h"
#include "LaserManager.h"
#include "AbstractDamageArea.h"
#include "DamageAreaCircle.h"
#include "DamageAreaRectangle.h"
#include "DamageAreaManager.h"

Player::Player(int padNo, LaserManager* laserManager, DamageAreaManager* damageAreaManager){
	this->device			= DeviceManager::GetInstance();
	this->padNo				= padNo;
	this->damageAreaManager	= damageAreaManager;
	this->laserManager		= laserManager;
	height					= 32;
	width					= 32;
	maxStopCntAttack		= PLAYER_ATTACK_STOP_COUNT;
	cntInvincible			= PLAYER_DAMAGE_INVINCIBLE_COUNT;
	isEnable				= false;
	inputState				= device->Input()->GetInputState(padNo);
}

Player::~Player() {

}

void Player::Setup(CharacterInformation parameter){
	this->parameter = parameter;
	SetAnimeData(device->Image()->GetAnimeData(imageAsset_player_fighter));
	imageHandle		= LoadGraph("Resource/Enemy_KingPumpkin.png");
	laserData		= LaserData::Setup(30, 5, position, Vec2::Zero(), 16, 5, 1, 15, 60);
	maxAttackCount	= 5;
	leftAttackCount	= 0;
	isAttackInput	= false;
	attackVec		= Vec2::Zero();
}

void Player::Initialize() {
	isDead			= !isEnable;
	isWalk			= false;
	cntInvincible	= 120;
	cut				= std::make_shared<Cutting>(e_Right);
}

void Player::Update(){
	CountdownInvincible();
	ControllManager();
	HitData hit = damageAreaManager->CheckAllHitCircle(GetHitArea(), false, true);
	if (hit == HitData::NoHit() || hit.shooterPlayerNo == padNo){ return; }
	
	Knockback(GMath::CalcAngleRad(hit.fromPosition, position), hit.knockbackPower);
	Damage(hit.damage);
}

void Player::Draw() {
	int attackImage = (cntStop > 0) ? 4 : 0;
	device->Image()->DrawLT(imageHandle, position);
}

void Player::Finalize()
{
	Dispone();
}

void Player::Dispone()
{
	isEnable = false;
}

void Player::Die(){
	isDead = true;
}

int Player::GetImageHandle(){
	return imageHandle;
}

bool Player::IsEnable(){
	return isEnable;
}

void Player::HitDamage(HitData hitData){
	Knockback(hitData.fromPosition, position, hitData.knockbackPower);
	if (cntInvincible > 0) { return; }
	Damage(hitData.damage);
	cntInvincible = 60;
}

CharacterInformation Player::GetParameter() {
	return parameter;
}

Vec2 Player::GetPosition() {
	return position;
}

Vec2 Player::GetCenterPosition() {
	return position - Vec2::Setup((float)width / 2, (float)height / 2);
}

void Player::CheckHitDamageArea(AbstractDamageArea* damageArea){
	if (hitArea->CheckIsHitAndDamage(damageArea) == HitData::NoHit()) { return; }
	HitData hitData = damageArea->GetHitData();
	Knockback(GMath::CalcAngleRad(hitData.fromPosition, position), hitData.knockbackPower);
	Damage(hitData.damage);
}

GCircle Player::GetHitArea() {
	return GCircle::Setup(GetCenterPosition(), parameter.hitRange);
}

int Player::GetLeftHealth() {
	return parameter.health;
}

float Player::GetLeftHealthPercent(int digits){
	int		digitOfTen = (int)pow(10.0, (double)digits);
	float	healthPercentage = (float)parameter.health / parameter.maxHealth;
	return	(float)(int)(healthPercentage * pow(10, digitOfTen)) / digitOfTen;
}

void Player::Damage(int damage) {
	parameter.health -= damage;
	CheckIsDead();
}

void Player::Heal(int heal) {
	parameter.health += heal;
	CheckIsOverHeal();
}

void Player::Spawn(Vec2 position)
{
	isEnable = true;
	this->position = position;
}

int Player::GetPadNo()
{
	return padNo;
}


void Player::CheckControll(){
	InputState* input = device->Input()->GetInputState(padNo);
}

//---private---
void Player::SetAnimeData(AnimeData animeData){
	this->animeData = animeData;
}

void Player::LoadImageHandle(IMAGE_ASSET_NAME assetName){
	imageHandle = device->Image()->GetHGraphics(0);//AddCharacterImageMap(assetName);
}

void Player::Attack(Vec2 vector, int chargeLevel){
	if (--cntStop > 0){ return; }
	cntStop = maxStopCntAttack;
	laserData.shotPosition = GetCenterPosition();
	double attackAngleDeg = vector.GetAngleDeg();
	attackAngleDeg += GetRand(10) - 5;
	laserData.velocity = Vec2::GetVelocityFromDeg(attackAngleDeg);
	laserManager->AddLaser(laserData, padNo);

}

void Player::ChangeImageType(int type) {
	if (imageType == type) { return; }
	imageType = type;
}

void Player::Move(Vec2 velocity, float multiply){
	if (velocity == Vec2::Zero()) { return; }
	//	if (cntStop > 0){ return; }
	velocity.NormalizeSelf();
	position += velocity * parameter.speed * multiply;
	Clamp();
}

void Player::SetPlayAnimation(Vec2 velocity) {
	animeData.isAnimation = !(velocity == Vec2::Zero());
}

void Player::SetIsEnd(){
	isDead = true;
}

void Player::Knockback(Vec2 fromPos, Vec2 toPos, int power){
	Knockback(GMath::CalcAngleRad(fromPos, toPos), power);
}

void Player::Knockback(double angleRad, int power) {
	device->Sound()->Play(SE_Damage);
	Vec2 knockBackVec;
	knockBackVec.SetupSelf((float)(cos(angleRad)), (float)(sin(angleRad)));
	position += knockBackVec * power;
	Clamp();
}

void Player::CheckIsDead() {
	if (parameter.health <= 0) {
		Die();
	}
}

void Player::CheckIsOverHeal() {
	if (parameter.health <= parameter.maxHealth) { return; }
	parameter.health = parameter.maxHealth;
}

void Player::CountDeadTimer(){
	if (!isDead){ return; }
	if (--cntDead > 0){ return; }
	isEnable = false;
}

void Player::CountdownInvincible(){
	if (cntInvincible <= 0){ return; }
	--cntInvincible;
}

bool Player::FlashManager(int counter){
	if (cntInvincible > 0){
		if (counter % 4 <= 2){ return false; }
	}
	if (GetLeftHealth() <= 2){
		int invisible = (GetLeftHealth() == 1) ? 20 : 40;
		if (counter % invisible <= 2){ return false; }
	}
	return true;
}


void Player::Clamp(){
	Vec2 imageHalfSize = Vec2::Zero();// device->Image()->GetCharacterImageHalfSize(imageHandle);
	if (position.X - imageHalfSize.X < FIELD_MIN_X) { position.X = FIELD_MIN_X + imageHalfSize.X; }
	if (position.Y - imageHalfSize.Y < FIELD_MIN_Y) { position.Y = FIELD_MIN_Y + imageHalfSize.Y; }
	if (position.X + imageHalfSize.X > FIELD_MAX_X) { position.X = FIELD_MAX_X - imageHalfSize.X; }
	if (position.Y + imageHalfSize.Y > FIELD_MAX_Y) { position.Y = FIELD_MAX_Y - imageHalfSize.Y; }
}

void Player::ControllManager(){
	Vec2 moveVec = inputState->GetLeftStickLeanVector();
	if (moveVec != Vec2::Zero()) { Move(moveVec); }

	Vec2 tmpAttackVec = inputState->GetRightStickLeanVector();
	if (tmpAttackVec != Vec2::Zero()){ attackVec = tmpAttackVec; }
	if (tmpAttackVec == Vec2::Zero()){ isAttackInput = false; }
	if (tmpAttackVec != Vec2::Zero() && !isAttackInput) {
		isAttackInput = true;
		leftAttackCount = maxAttackCount;
	}
	if (--leftAttackCount > 0){
		Attack(attackVec, 1);
	}
}








