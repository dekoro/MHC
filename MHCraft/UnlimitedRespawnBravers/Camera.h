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
	Camera(){};
#endif
	Camera(Player* player);
	~Camera();

	void Initialize();

	//�J�����̊g�k���Z�b�g
	void SetScale(VECTOR scale);

	void Update();

	void SetPosition();//�J�����̃|�W�V�������Z�b�g����

private:
	Player* player;//��������|�W�V���������炢�J�����̒��S���W�ɂ���
	VECTOR position;//���_
	VECTOR lookPos;//�����_
	VECTOR scale ;//�g��k����


};


#endif