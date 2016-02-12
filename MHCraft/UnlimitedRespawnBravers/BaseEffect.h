#ifndef BASE_EFFECT
#define BASE_EFFECT

#include<functional>
#include<DxLib.h>

/*
�V�F�[�_�[�̊Ǘ��N���X���e�V�[����Initialize���Ń��[�h���Ă��邽�߁A
���̃N���X���p�����Ă�N���X�����݂œ��I�Ɋm�ۂ��Ă���������
*/

class BaseEffect
{
public:
	BaseEffect(int psHundle = 0,int vsHundle = 0);
	virtual ~BaseEffect();

	virtual void Rendering(std::function<void()> Draw);


protected:
	virtual void ConstSet(){};//�V�F�[�_�[�ɒ萔�Z�b�g

protected:
	int ps;
	int vs;

};

#endif