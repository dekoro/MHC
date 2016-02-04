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

void Camera::Update()
{

}

void Camera::SetPosition()
{
	MATRIX view;
	D3DXMATRIX d9View;
	MATRIX scale;

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

	scale = MMult(scale,MGetScale(this->scale));//スケールのベクトルを行列に変換

	view = MAdd(view , scale);//カメラ位置とスケール行列合成


	VECTOR pos = {30,30,0};
	MATRIX move;
	CreateIdentityMatrix(&move);

	move = MMult(move,MGetTranslate(pos));

	//view = MAdd(move,view);

	SetCameraViewMatrix(view);//ビューをセット
}


