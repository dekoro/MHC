#ifndef TWIST_EFFECT
#define TWIST_EFFECT

#include"BaseEffect.h"
#include"Timer.h"

class TwistEffect : public BaseEffect
{
public:
	TwistEffect();
	~TwistEffect();

	void Rendering(std::function<void()> Draw) override;

private:
	//�V�F�[�_�[�ɒ萔���Z�b�g����
	virtual void ConstantShader() override;

private:
	Timer timer;
};


#endif