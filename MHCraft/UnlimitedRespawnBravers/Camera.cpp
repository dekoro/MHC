#include"Camera.h"
#include"Player.h"
#include<d3dx9math.h>
/*
�c�w���C�u���̊֐��̎g�������悭�킩��Ȃ������̂�DirectX9Math
�̊֐����g����View�ϊ��s����쐬����.

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

	CreateIdentityMatrix(&scale);//�s���������
	D3DXMatrixIdentity(&d9View);

	D3DXMatrixLookAtLH(&d9View, &D3DXVECTOR3(0, 250, -750), &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 1.0f, 0));


	//XMATRIX�ɕϊ�
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; j++)
		{
			view.m[i][j] =d9View.m[i][j];
		}
	}

	scale = MMult(scale,MGetScale(this->scale));//�X�P�[���̃x�N�g�����s��ɕϊ�

	view = MAdd(view , scale);//�J�����ʒu�ƃX�P�[���s�񍇐�


	VECTOR pos = {30,30,0};
	MATRIX move;
	CreateIdentityMatrix(&move);

	move = MMult(move,MGetTranslate(pos));

	//view = MAdd(move,view);

	SetCameraViewMatrix(view);//�r���[���Z�b�g
}


