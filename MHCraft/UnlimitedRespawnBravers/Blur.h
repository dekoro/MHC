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

	void Initialize();

	void SetDirectionAndVelocity(Vec2 direction,float velocity);//�A�b�v�L���X�g���Ďg���Ă�������

private:
	void ConstSet()override;

private:
	FLOAT4 directoin;
	InputManager* input;//�e�X�g
	float velocity = 0;//�e�X�g
};


#endif