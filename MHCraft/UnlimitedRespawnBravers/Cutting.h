#ifndef CUTTING
#define CUTTING

#include"BaseEffect.h"

class Cutting : public BaseEffect
{
public:
	Cutting();
	~Cutting();

	void SetSlope(VECTOR);//�A�b�v�L���X�g���Ďg���Ă�������
	
private:
	void ConstSet()override;//�V�F�[�_�[�ɒ萔�Z�b�g

	FLOAT4 slope;//���̌X��

};

#endif


