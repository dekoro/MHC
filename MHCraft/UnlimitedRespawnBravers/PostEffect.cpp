#include"PostEffect.h"
#include<DxLib.h>
#include"BaseEffect.h"
#include"GSystem.h"
PostEffect::PostEffect(int hGraphics, BaseEffect* effect) : hGraphics(hGraphics), effect(effect)
{
	for (int i = 0; i < 4; ++i)
	{
		vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT,0);
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

	SetUseTextureToShader(0, hGraphics);

	effect->Rendering([&](){DrawPrimitive2DToShader(vertex, 4, DX_PRIMTYPE_TRIANGLESTRIP);
	});
}