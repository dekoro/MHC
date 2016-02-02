#include"PostEffect.h"
#include"ConstantNumber.h"
#include<DxLib.h>
#include"MathHelper.h"
#include"BaseEffect.h"

PostEffect::PostEffect(int hGraphics, BaseEffect* effect) : hGraphics(hGraphics), effect(effect)
{
	for (int i = 0; i < 4; ++i)
	{
		vertex[i].pos = VGet((i % 2) * SCREEN_WIDTH, (i / 2) * SCREEN_HEIGHT,0);
		vertex[i].rhw = 1.0f;//�A���t�@�l
		vertex[i].dif = GetColorU8(255, 255, 255, 255);
		vertex[i].spc = GetColorU8(0, 0, 0, 0);
		vertex[i].u = vertex[i].su = (float)(i % 2);
		vertex[i].v = vertex[i].sv = (float)(i / 2);

	}
}

PostEffect::~PostEffect()
{
	delete(effect);
}

void PostEffect::Rendaring(std::function<void()> Draw)
{
	SetDrawScreen(this->hGraphics);

	ClearDrawScreen();

	Draw();

	SetDrawScreen(DX_SCREEN_BACK);

	SetUseTextureToShader(1, hGraphics);

	effect->Rendering([&](){DrawPrimitive2DToShader(vertex, 4, DX_PRIMTYPE_TRIANGLESTRIP);
	});
}
