#include"Blur.h"
#include"Vec2.h"
#include"EffectManager.h"
#include<minmax.h>


Blur::Blur() : BaseEffect(EffectManager::GetInstance()->GetEffect("Blur"))
{
	Initialize();
	input = DeviceManager::GetInstance()->Input();
}

Blur::~Blur()
{
}

void Blur::Initialize()
{
	directoin.w = 0;
	directoin.x = 0;
	directoin.y = 0;
	directoin.z = 0;
}

void Blur::SetDirectionAndVelocity(Vec2 direction,float velocity)
{
	this->directoin.x = direction.X;
	this->directoin.y = direction.Y;
	this->directoin.z = velocity;
}

void Blur::ConstSet()
{
	if (input->CheckKeyDownAllPad(GKey_Up))
	{
		this->directoin.y = 1;
		velocity += 0.002;
	}
	if (input->CheckKeyDownAllPad(GKey_Down))
	{
		this->directoin.y = -1;
		velocity += 0.002;
	}
	if (input->CheckKeyDownAllPad(GKey_Right))
	{
		this->directoin.x = 1;
		velocity += 0.002;
	}
	if (input->CheckKeyDownAllPad(GKey_Left))
	{
		this->directoin.x = -1;
		velocity += 0.002;
	}
	if (!input->CheckKeyDownAllPad(GKey_Up)&&
		!input->CheckKeyDownAllPad(GKey_Down)&&
		!input->CheckKeyDownAllPad(GKey_Right)&&
		!input->CheckKeyDownAllPad(GKey_Left))
	{
		velocity = 0;
	}

	velocity = min(velocity,0.008);

	directoin.z = velocity;

	//SetDirectionAndVelocity(Vec2(1, 1), 0.02f);
	SetPSConstF(0,this->directoin);
}