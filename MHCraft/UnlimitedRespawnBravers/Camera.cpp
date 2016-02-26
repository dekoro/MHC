#include"Camera.h"
#include"Player.h"
#include"DeviceManager.h"
#include"InputManager.h"
#include<minmax.h>


Camera::Camera(Player* player, int padNum) : player(player), padNum(padNum)
{
	this->scale = originScale;
	SetCameraNearFar(1, 1000);
}

Camera::~Camera()
{
}

//プレイヤーの初期化の後に呼び出す
//拡大りつ、ポジションリセット
void Camera::Initialize()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;
	this->position.z = -750;
	this->scale = 2000.f;
	this->scaleSpeed = 2;
}

//ポジション更新
void Camera::Update()
{
	//プレイヤーが死ぬと参照エラー起こすので後で変更
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;

	//とりあえず0を指定、後でメンバ変数のpadNumを引数に入れる
	if (DeviceManager::GetInstance()->Input()->GetInputState(this->padNum)->CheckLeftTrigger())
	{
		this->scale += scaleUp;
	}
	if (DeviceManager::GetInstance()->Input()->GetInputState(this->padNum)->CheckRightTrigger())
	{
		this->scale -= scaleUp;
	}
	
	if (DeviceManager::GetInstance()->Input()->GetInputState(this->padNum)->CheckKeyDown(GKey_Skill) &&
		DeviceManager::GetInstance()->Input()->GetInputState(this->padNum)->CheckKeyDown(GKey_Attack))
	{
		scale = originScale;
	}

	scale = min(max(MIN_SCALE, scale), MAX_SCALE);
}


//名前を後で変更
//これを格描画ターゲットに変更したあとに呼ぶ
void Camera::SetPosition()
{
	//Zは適当な距離離す
	SetCameraPositionAndTarget_UpVecY(VGet(this->position.x, this->position.y, 200), VGet(this->position.x, this->position.y, 0));
	SetupCamera_Ortho(scale);//２Ｄカメラ設定
}


