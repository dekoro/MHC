#include "Player.h"
#include "PlayerManager.h"
#include "EnemyManager.h"

Player::Player(int padNo, int health, int sp, float speed, IMAGE_ASSET_NAME assetName, PlayerColorList colors){
	this->device		= DeviceManager::GetInstance();
	this->managers		= Managers::GetInstance();
	this->padNo			= padNo;
	//position			= Vec2::Setup(Window::WIDTH/2, Window::HEIGHT*4/5);
	position = Vec2(0,0);
	SetupPlayer(health, sp, speed, assetName, colors);
	Initialize();
	maxCntAttack = 20;
}

Player::~Player(){

}

void Player::Initialize(){
	isDead			= false;
	isWalk			= false;
	isEnd			= false;
	cntInvincible	= 120;
}

void Player::Update(){
	Attack();
	cntHoldDirection = device->Input()->GetInputState(padNo)->CheckKeyDown(GKey_Attack);
	Move();
	CountdownInvincible();
}

void Player::Draw(){
	int attackImage = (cntAttack > 0) ? 4 : 0;
	cut.Rendering([&]()
	{
		device->Image()->ChangeImageType(imageHandle, imageType + attackImage);
		device->Image()->ChangeAnimePlay(imageHandle, animeData.isAnimation);
		device->Image()->DrawPlayerCenter(imageHandle, position);
	});
}

int Player::GetImageHandle(){
	return imageHandle;
}

int Player::GetPadNo(){
	return padNo;
}

void Player::SetupPlayer(int health, int sp, float speed, IMAGE_ASSET_NAME assetName, PlayerColorList colors){
	parameter.SetupSelf(health, sp, 1, 100, speed, 5);
	SetPlayerColor(colors);
	SetAnimeData(device->Image()->GetAnimeData(assetName));
	LoadImageHandle(assetName);
}

bool Player::GetIsEnd(){
	return isEnd;
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

Vec2 Player::GetPosition(){
	return position;
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


//---private---

void Player::SetPlayerColor(PlayerColorList colors){
	this->colors	= colors;
}

void Player::SetAnimeData(AnimeData animeData){
	this->animeData = animeData;
}

void Player::LoadImageHandle(IMAGE_ASSET_NAME assetName){
	imageHandle = device->Image()->AddCharacterImageMap(assetName, colors);

}

void Player::Attack(){
	if (--cntAttack > 0){
		return;
	}
	if (!device->Input()->GetInputState(padNo)->CheckKeyPush(GKey_Attack)){ return; }
	SetDamageArea();
	cntAttack = maxCntAttack;
}

void Player::ChangeImageType(int type){
	if (imageType == type){ return; }
	imageType = type;
}

void Player::ChangeDirection(Vec2 moveTo){
	if (device->Input()->GetInputState(padNo)->CheckKeyDown(GKey_Skill)){ return; }
	if (moveTo.X == moveTo.Y){ return; }
	if (moveTo.X == -moveTo.Y){ return; }
	if (moveTo.X > 0){ direction = 3; }
	if (moveTo.X < 0){ direction = 2; }
	if (moveTo.Y > 0){ direction = 0; }
	if (moveTo.Y < 0){ direction = 1; }
	ChangeImageType(direction);
}

void Player::Move(){
	if (cntAttack > 0){ return; }
	Vec2 moveVec	=  MoveVector();
	Vec2 moveTo		=  moveVec*parameter.speed;
	position		+= moveTo;
	Clamp();
}

Vec2 Player::MoveVector(){
	Vec2 pos = Vec2::Zero();
	if (device->Input()->GetInputState(padNo)->CheckKeyDown(GKey_Up))	{
		pos.Y -= 1;
	}
	if (device->Input()->GetInputState(padNo)->CheckKeyDown(GKey_Down))	{
		pos.Y += 1;
	}
	if (device->Input()->GetInputState(padNo)->CheckKeyDown(GKey_Left))	{
		pos.X -= 1;
	}
	if (device->Input()->GetInputState(padNo)->CheckKeyDown(GKey_Right)){
		pos.X += 1; 
	}
	pos.NormalizeSelf();
	if (pos == Vec2::Zero()){
		animeData.isAnimation = false;
		return pos;
	}

	animeData.isAnimation = true;
	pos.NormalizeSelf();
	ChangeDirection(pos);
	return pos;
}

void Player::SetIsEnd(){
	managers->Player()->SetAddForbiddenCounter();
	managers->Enemy()->DeadPlayerActioon();
	isDead	= true;
	isEnd	= true;
}

void Player::SetDamageArea(){
	Vec2		attackVec;
	float		range	= 52;
	int			width	= 32;
	int			height	= 24;
	GRectangle	hitArea;

	switch (direction){
	case 0:
		attackVec	= Vec2(0, range);
		hitArea		= GRectangle::Setup(position + attackVec, width, height);
		break;
	case 1:
		attackVec	= Vec2(0, -range);
		hitArea		= GRectangle::Setup(position + attackVec, width, height);
		break;
	case 2:
		attackVec	= Vec2(-range, 0);
		hitArea		= GRectangle::Setup(position + attackVec, height, width);
		break;
	case 3:
		attackVec	= Vec2(range, 0);
		hitArea		= GRectangle::Setup(position + attackVec, height, width);
		break;
	default:
		break;
	}
	HitData	hitData = HitData::Setup(position, 100, 1);
	managers->Damage()->AddDamageAreaRectangle(hitArea, 5, hitData, false, true);
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
	//cntDead--;
	//if (cntDead > 0){ return; }
	//isUse = false;
}

void Player::CountdownInvincible(){
	if (cntInvincible <= 0){ return; }
	cntInvincible--;
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







