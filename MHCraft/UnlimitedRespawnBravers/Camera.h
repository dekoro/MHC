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
	Camera(){};
	Camera(Player* player);
	~Camera();

	//�J�����̊g�k���Z�b�g
	//void SetScale(VECTOR scale);

	//�J�����̃|�W�V�������Z�b�g
	//void SetMove(Vec2 pos);

	void Update();

	void SetPosition();//�J�����̃|�W�V�������Z�b�g����

private:
	Player* player;//��������|�W�V���������炢�J�����̒��S���W�ɂ���

	VECTOR lookPos;//���_
	VECTOR scale ;//�g��k����


};


#endif