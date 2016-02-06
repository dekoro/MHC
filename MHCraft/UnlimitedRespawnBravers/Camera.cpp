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

//�v���C���[�̏������̌�ɌĂяo��
//�g���A�|�W�V�������Z�b�g
void Camera::Initialize()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;
	this->position.z = -750;
	this->scale = 2000.f;
}

//�|�W�V�����X�V
void Camera::Update()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;

	/*if (DeviceManager::GetInstance()->Input()->GetInputState(padNum)->"RT�������ꂽ��X�P�[���𑝂₷")
	{
		this->scale += 0.1f;
	}*/

}


//���O����ŕύX
//������i�`��^�[�Q�b�g�ɕύX�������ƂɌĂ�
void Camera::SetPosition()
{
	//Z�͓K���ȋ�������
	SetCameraPositionAndTarget_UpVecY(VGet(this->position.x, this->position.y, 200), VGet(this->position.x, this->position.y, 0));
	SetupCamera_Ortho(scale);//�Q�c�J�����ݒ�

}


