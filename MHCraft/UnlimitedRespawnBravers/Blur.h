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

	void SetDirectionAndVelocity(Vec2 direction,float velocity);//アップキャストして使ってください

private:
	void ConstSet()override;

private:
	FLOAT4 directoin;
	InputManager* input;//テスト
	float velocity = 0;//テスト
};


#endif