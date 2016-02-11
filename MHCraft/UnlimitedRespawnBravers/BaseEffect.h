#ifndef BASE_EFFECT
#define BASE_EFFECT

#include<functional>
#include<DxLib.h>

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