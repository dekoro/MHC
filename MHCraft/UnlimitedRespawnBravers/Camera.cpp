#include"Camera.h"
#include"Player.h"
#include<d3dx9math.h>
/*
ＤＸライブリの関数の使い方がよくわからなかったのでDirectX9Math
の関数を使ってView変換行列を作成する.

*/

Camera::Camera(Player* player) : player(player)
{
}

Camera::~Camera()
{
}

//拡大りつ、ポジションリセット
void Camera::Initialize()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;
	this->position.z = -750;
}

//ポジション更新
void Camera::Update()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;
}


//名前を後で変更
//これを格描画ターゲットに変更したあとに呼ぶ
void Camera::SetPosition()
{

	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, 200), VGet(0, 0, 0));
	SetupCamera_Ortho(2000.0f);//２Ｄカメラ設定

}


