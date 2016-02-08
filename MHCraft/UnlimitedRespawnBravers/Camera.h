#ifndef CAMERA
#define CAMERA

#include<DxLib.h>
#include"GMath.h"

class Player;

/*
�����Ƃ����v���C���[�̃|�W�V�����𒆐S�ɃJ�����͍X�V����B
SetPosition()�͕`����ύX���邽�тɌĂ΂Ȃ��ƃ��Z�b�g����Ă��܂��̂Œ���
*/

class Camera
{
public:
#if _DEBUG
	Camera()
	{
		position = VGet(0,0,0);
		this->scale = 2000.f;
	};
#endif
	Camera(Player* player,int padNum);
	~Camera();

	void Initialize();

	//�J�����̊g�k���Z�b�g
	void SetScale(float scale);

	void Update();

	void SetPosition();//�J�����̃|�W�V�������Z�b�g����

private:
	Player* player;//��������|�W�V���������炢�J�����̒��S���W�ɂ���
	int padNum;//�ǂ̃v���C���[�����삷��J���������ʂ��邽��

	VECTOR position;//���_
	float scale ;//�g��k����


};


#endif