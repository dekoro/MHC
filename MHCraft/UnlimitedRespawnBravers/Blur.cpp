#include"Blur.h"
#include"Vec2.h"
#include"EffectManager.h"
#include<minmax.h>


Blur::Blur() : BaseEffect(EffectManager::GetInstance()->GetEffect("Blur"))
{
	Initialize();
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
	directoin.z = min(directoin.z, 0.008);

	SetPSConstF(0,this->directoin);
}