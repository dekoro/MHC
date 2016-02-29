#include"ZoomBlur.h"
#include"EffectManager.h"


ZoomBlur::ZoomBlur() : BaseEffect(EffectManager::GetInstance()->GetEffect("Zoom")), Center(0.5f,0.5f),
timer(30)
{
}

ZoomBlur::~ZoomBlur()
{
}

void ZoomBlur::Initialize()
{
	timer.Initialize();
	isStart = false;
}

void ZoomBlur::ConstSet()
{
	if (isStart)
	{
		timer.Update();
	}

	float a = 1 - timer.Rate();

	SetPSConstSF(0, a);
	SetPSConstSF(1, this->Center.X);//�ꂶ�����[�P���w
	SetPSConstSF(2, this->Center.Y);//�ꂶ�����[2��Y
	SetPSConstSF(3, timer.Rate());
}

bool ZoomBlur::IsEnd()
{
	return timer.IsEnd();
}

void ZoomBlur::IsStart()
{
	this->isStart = true;
}



