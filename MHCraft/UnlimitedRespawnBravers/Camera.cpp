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

//�g���A�|�W�V�������Z�b�g
void Camera::Initialize()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;
	this->position.z = -750;
}

//�|�W�V�����X�V
void Camera::Update()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;
}


//���O����ŕύX
//������i�`��^�[�Q�b�g�ɕύX�������ƂɌĂ�
void Camera::SetPosition()
{

	SetCameraPositionAndTarget_UpVecY(VGet(0, 0, 200), VGet(0, 0, 0));
	SetupCamera_Ortho(2000.0f);//�Q�c�J�����ݒ�

}


