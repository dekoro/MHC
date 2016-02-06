#include"Camera.h"
#include"Player.h"
#include"DeviceManager.h"
#include"InputManager.h"


Camera::Camera(Player* player, int padNum) : player(player), padNum(padNum)
{
	this->scale = 2000.f;
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
}

//ポジション更新
void Camera::Update()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;

	/*if (DeviceManager::GetInstance()->Input()->GetInputState(padNum)->"RTが押されたらスケールを増やす")
	{
		this->scale += 0.1f;
	}*/

}


//名前を後で変更
//これを格描画ターゲットに変更したあとに呼ぶ
void Camera::SetPosition()
{
	//Zは適当な距離離す
	SetCameraPositionAndTarget_UpVecY(VGet(this->position.x, this->position.y, 200), VGet(this->position.x, this->position.y, 0));
	SetupCamera_Ortho(scale);//２Ｄカメラ設定

}


