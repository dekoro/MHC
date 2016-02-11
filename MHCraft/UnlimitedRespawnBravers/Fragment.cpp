#include"Fragment.h"
#include"DeviceManager.h"
#include"MusicRenderer.h"
#include"Cutting.h"
#include"EffectManager.h"
#include<stdio.h>

Frangment::Frangment(Vec2 direction, float velocity, e_CutDirection e_Direction)
	: originDirection(direction), velocity(Vec2(velocity * direction.X, velocity * direction.Y))
{
	this->fragment = EffectManager::GetInstance()->GetEffect("Cutting");
	pos = Vec2();
	this->direction = originDirection;

	switch (e_Direction)
	{
	case e_Right:
		this->fragment = EffectManager::GetInstance()->GetEffect("CutRight");
		break;
	case e_Left:
		this->fragment = EffectManager::GetInstance()->GetEffect("CutRight");
		break;
	}

}

Frangment::~Frangment()
{
}

void Frangment::Initialize()
{
	pos = Vec2();
	this->direction = originDirection;
}

//directionの方向に移動させる
void Frangment::Update()
{
	pos += velocity;
}

void Frangment::Draw(int hGraphics, Vec2 pos)
{
	fragment->Rendering([&](){
		DeviceManager::GetInstance()->Image()->DrawLT(hGraphics, pos + this->pos);
	});
}

bool Frangment::IsEnd()
{//ポジションの絶対値がある程度離れたら終了
	return  (float)fabs(pos.X) >= END_VELOCITY || (float)fabs(pos.Y) >= END_VELOCITY;
}