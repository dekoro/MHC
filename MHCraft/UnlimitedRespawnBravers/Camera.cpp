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

//�v���C���[�̏������̌�ɌĂяo��
//�g���A�|�W�V�������Z�b�g
void Camera::Initialize()
{
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;
	this->position.z = -750;
	this->scale = 2000.f;
	this->scaleSpeed = 2;
}

//�|�W�V�����X�V
void Camera::Update()
{
	//�v���C���[�����ʂƎQ�ƃG���[�N�����̂Ō�ŕύX
	this->position.x = player->GetPosition().X;
	this->position.y = player->GetPosition().Y;

	//�Ƃ肠����0���w��A��Ń����o�ϐ���padNum�������ɓ����
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


//���O����ŕύX
//������i�`��^�[�Q�b�g�ɕύX�������ƂɌĂ�
void Camera::SetPosition()
{
	//Z�͓K���ȋ�������
	SetCameraPositionAndTarget_UpVecY(VGet(this->position.x, this->position.y, 200), VGet(this->position.x, this->position.y, 0));
	SetupCamera_Ortho(scale);//�Q�c�J�����ݒ�
}


