#ifndef BLUR
#define BLUR

#include"BaseEffect.h"
#include"InputManager.h"
#include"DeviceManager.h"

class Vec2;

class Blur : public BaseEffect
{
public:
	Blur();
	~Blur();

	void Initialize() override;

	void SetDirectionAndVelocity(Vec2 direction,float velocity);//�_�E���L���X�g���Ďg���Ă�������

private:
	void ConstSet()override;

private:
	FLOAT4 directoin;
};


#endif