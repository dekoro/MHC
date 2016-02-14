#include"CutEffect.h"



CutEffect::CutEffect(int time, Vec2 direction) 
	:timer(time), right(direction, e_Right), left(Vec2(-direction.X, -direction.Y), e_Left)
{
	isStart = false;

}

CutEffect::~CutEffect()
{
}

void CutEffect::Initialize()
{
	right.Initialize();
	left.Initialize();
	timer.Initialize();

	isStart = false;

}

void CutEffect::Update()
{
	if (!isStart)
		return;

	if (right.IsEnd() && left.IsEnd())
		return;
	timer.Update();
	right.Update();
	left.Update();
}



void CutEffect::Cut(int hGraphics,Vec2 pos)
{
	if (!isStart)
		return;

	if (right.IsEnd() && left.IsEnd())
		return;

	right.Draw(hGraphics,pos);
	left.Draw(hGraphics, pos);
}

void CutEffect::IsStart()
{
	isStart = true;
}

bool CutEffect::IsEnd()
{
	return right.IsEnd() && left.IsEnd();
}