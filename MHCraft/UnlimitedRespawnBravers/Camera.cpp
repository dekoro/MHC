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
	MATRIX view;
	D3DXMATRIX d9View;
	MATRIX scale;
	VECTOR pos = { 30, 30, 0 };
	MATRIX move;

	CreateIdentityMatrix(&scale);//行列を初期化
	D3DXMatrixIdentity(&d9View);

	D3DXMatrixLookAtLH(&d9View, &D3DXVECTOR3(0, 250, -750), &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 1.0f, 0));

	//XMATRIXに変換
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; j++)
		{
			view.m[i][j] =d9View.m[i][j];
		}
	}

	this->scale = { 1, 1, 1 };

	scale = MMult(scale,MGetScale(this->scale));//スケールのベクトルを行列に変換

	view = MAdd(view , scale);//カメラ位置とスケール行列合成

	CreateIdentityMatrix(&move);

	move = MMult(move,MGetTranslate(pos));

	view = MAdd(move,view);

	SetCameraViewMatrix(view);//ビューをセット
}


