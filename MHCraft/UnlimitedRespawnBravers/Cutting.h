#ifndef CUTTING
#define CUTTING

#include"BaseEffect.h"
#include"e_Directon.h"

class Cutting : public BaseEffect
{
public:
	Cutting(e_CutDirection e_Dir);
	~Cutting();

	void SetSlope(VECTOR);//�A�b�v�L���X�g���Ďg���Ă�������
	
private:
	void ConstSet()override;//�V�F�[�_�[�ɒ萔�Z�b�g

	FLOAT4 slope;//���̌X��

};

#endif


