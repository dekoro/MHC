#include"Fragment.h"
#include"DeviceManager.h"
#include"MusicRenderer.h"
#include"Cutting.h"
#include"EffectManager.h"
#include<stdio.h>

Frangment::Frangment(Vec2 direction, e_CutDirection e_Direction)
	: originDirection(direction),
	fragment(e_Direction)
{
	pos = Vec2();
	this->direction = originDirection;
}

Frangment::~Frangment()
{
}

void Frangment::Initialize()
{
	pos = Vec2();
	this->direction = originDirection;
}

//direction�̕����Ɉړ�������
void Frangment::Update()
{
	pos += velocity;
}

void Frangment::Draw(int hGraphics, Vec2 pos)
{
	fragment.Rendering([&](){
		DeviceManager::GetInstance()->Image()->DrawLTUseToShader(hGraphics, pos + this->pos);
	});
}

bool Frangment::IsEnd()
{//�|�W�V�����̐�Βl��������x���ꂽ��I��
	return  (float)fabs(pos.X) >= END_VELOCITY || (float)fabs(pos.Y) >= END_VELOCITY;
}