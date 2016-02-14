#include "Player.h"
#include "Managers.h"
#include "DeviceManager.h"

Player::Player(int padNo){
	this->device		= DeviceManager::GetInstance();
	this->padNo			= padNo;
	SetupPlayer();
	maxStopCntAttack	= PLAYER_ATTACK_STOP_COUNT;
	cntInvincible		= PLAYER_DAMAGE_INVINCIBLE_COUNT;
	isEnable			= false;
}

Player::~Player(){

}

void Player::Initialize(){
	isDead			= false;
	isWalk			= false;
	cntInvincible	= 120;
}

void Player::Update(){
	CountdownInvincible();
	InputState* input = device->Input()->GetInputState(padNo);
	if (input->CheckKeyPush(GKey_Attack)) {
		Move(Vec2::Setup(0, -1));
	}
}


void Player::Draw() {
	if (!isEnable) { return; }
	int attackImage = (cntStop > 0) ? 4 : 0;
	device->Image()->ChangeImageType(imageHandle, imageType + attackImage);
	device->Image()->ChangeAnimePlay(imageHandle, animeData.isAnimation);
	device->Image()->DrawPlayerCenter(imageHandle, position);
}

void Player::Finalize()
{
	Delete();
}

void Player::Delete()
{
	isEnable = false;
}

int Player::GetImageHandle(){
	return imageHandle;
}

void Player::SetupPlayer(int health, int sp, float speed, IMAGE_ASSET_NAME assetName){
	parameter.SetupSelf(health, sp, 1, 100, speed, 5);
	SetAnimeData(device->Image()->GetAnimeData(assetName));
	LoadImageHandle(assetName);
}

bool Player::IsEnable(){
	return isEnable;
}

void Player::HitDamage(HitData hitData){
	Knockback(hitData.fromPosition, position, hitData.knockbackPower);
	if (cntInvincible > 0){ return; }
	Damage(hitData.damage);
	cntInvincible = 60;
}

CharacterInformation Player::GetParameter(){
	return parameter;
}

GCircle Player::GetHitArea(){
	return GCircle::Setup(position, parameter.hitRange);
}

int Player::GetLeftHealth(){
	return parameter.health;
}


void Player::Damage(int damage){
	parameter.health -= damage;
	CheckIsDead();
}

void Player::Heal(int heal){
	parameter.health += heal;
	CheckIsOverHeal();
}

void Player::Spawn(Vec2 position)
{
	isEnable		= true;
	this->position	= position;

}

int Player::GetPadNo()
{
	return padNo;
}


//---private---
void Player::SetAnimeData(AnimeData animeData){
	this->animeData = animeData;
}

void Player::LoadImageHandle(IMAGE_ASSET_NAME assetName){
	imageHandle = device->Image()->AddCharacterImageMap(assetName);

}

void Player::Attack(float angleDeg, int chargeLevel){
	if (--cntStop > 0){
		return;
	}
	if (!device->Input()->GetInputState(padNo)->CheckKeyPush(GKey_Attack)){ return; }

	cntStop = maxStopCntAttack;
}

void Player::ChangeImageType(int type){
	if (imageType == type){ return; }
	imageType = type;
}

void Player::Move(Vec2 velocity, float multiply){
	if (velocity == Vec2::Zero()) { return; }
	if (cntStop > 0){ return; }
	velocity.NormalizeSelf();
	position		+= velocity * parameter.speed * multiply;
	Clamp();
}

void Player::SetPlayAnimation(Vec2 velocity) {
	animeData.isAnimation = !(velocity == Vec2::Zero());
}

void Player::SetIsEnd(){
	isDead	= true;
}


void Player::Knockback(Vec2 fromPos, Vec2 toPos, int power){
	Knockback(GMath::CalcAngleRad(fromPos, toPos), power);
}

void Player::Knockback(double angleRad, int power){
	device->Sound()->Play(SE_Damage);
	Vec2 knockBackVec;
	knockBackVec.SetupSelf((float)(cos(angleRad)), (float)(sin(angleRad)));
	position += knockBackVec * power;
}

void Player::CheckIsDead(){
	if (parameter.health <= 0){
		SetIsEnd();
	}
}

void Player::CheckIsOverHeal(){
	if (parameter.health <= parameter.maxHealth){ return; }
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
	Vec2 imageHalfSize = device->Image()->GetCharacterImageHalfSize(imageHandle);
	if (position.X - imageHalfSize.X < 0)				{ position.X = imageHalfSize.X; }
	if (position.Y - imageHalfSize.Y < 0)				{ position.Y = imageHalfSize.Y; }
	if (position.X + imageHalfSize.X > Window::WIDTH)	{ position.X = Window::WIDTH - imageHalfSize.X; }
	if (position.Y + imageHalfSize.Y > Window::HEIGHT)	{ position.Y = Window::HEIGHT - imageHalfSize.Y; }
}







