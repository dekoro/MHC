#ifndef BASE_EFFECT
#define BASE_EFFECT

#include<functional>

class BaseEffect
{
public:
	BaseEffect(int psHundle = 0,int vsHundle = 0);
	virtual ~BaseEffect();

	virtual void Rendering(std::function<void()> Draw);

protected:
	//�V�F�[�_�[�ɒ萔���Z�b�g����
	virtual void ConstantShader(){};

protected:
	int ps;
	int vs;

};

#endif