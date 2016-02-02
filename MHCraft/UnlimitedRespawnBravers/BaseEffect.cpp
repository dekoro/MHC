#include"BaseEffect.h"
#include<DxLib.h>
#include<assert.h>

BaseEffect::BaseEffect(int psHundle, int vsHundle)
{
	ps = psHundle;
	vs = vsHundle;

	assert(ps != -1 || vs != -1 && "�V�F�[�_�̓ǂݍ��݂Ɏ��s���܂���");
};

BaseEffect::~BaseEffect()
{
	DeleteShader(ps);
	DeleteShader(vs);
};


void BaseEffect::Rendering(std::function<void()> Draw)
{
	assert(vs != -1 || ps != -1 && "�I���W�i���V�F�[�_�[���ǂݍ��݂Ɏ��s���Ă��܂�");

	MV1SetUseOrigShader(TRUE);//�V�F�[�_�g�p�n�m

	//if (vs != 0)
		SetUseVertexShader(vs);

	//if (ps != 0)
		SetUsePixelShader(ps);

	ConstantShader();//�V�F�[�_�ɒ萔��n��

	Draw();//�`�揈��

	MV1SetUseOrigShader(FALSE);//�V�F�[�_�g�p�nFF
}
