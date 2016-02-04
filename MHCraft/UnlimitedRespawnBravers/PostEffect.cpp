#include"PostEffect.h"
#include<DxLib.h>
#include"BaseEffect.h"
#include"GSystem.h"
PostEffect::PostEffect(int hGraphics, BaseEffect* effect) : hGraphics(hGraphics), effect(effect)
{
	for (int i = 0; i < 4; ++i)
	{
		vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT,0);
		vertex[i].rhw = 1.0f;//アルファ値
		vertex[i].dif = GetColorU8(255, 255, 255, 255);
		vertex[i].spc = GetColorU8(0, 0, 0, 0);
		vertex[i].u = vertex[i].su = (float)(i % 2);
		vertex[i].v = vertex[i].sv = (float)(i / 2);
	}
	//for (int i = 0; i < 4; ++i)
	//{
	//	vertex2[i].pos = VGet(((i % 2) * Window::WIDTH) + Window::WIDTH / 2, (i / 2) * Window::HEIGHT, 0);
	//	vertex2[i].rhw = 1.0f;//アルファ値
	//	vertex2[i].dif = GetColorU8(255, 255, 255, 255);
	//	vertex2[i].spc = GetColorU8(0, 0, 0, 0);
	//	vertex2[i].u = vertex[i].su = (float)(i % 2);
	//	vertex2[i].v = vertex[i].sv = (float)(i / 2);
	//}
}

PostEffect::~PostEffect()
{
	delete(effect);
}

void PostEffect::Rendaring(std::function<void()> Draw)
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	SetPSConstF(0,pos);

	SetDrawScreen(this->hGraphics);

	ClearDrawScreen();

	Draw();

	SetDrawScreen(DX_SCREEN_BACK);

	SetUseTextureToShader(0, hGraphics);

	//DrawBillboard3D(VGet(0, 0, 0), 0, 0, 0, 0, hGraphics, FALSE);
	effect->Rendering([&](){DrawPrimitive2DToShader(vertex, 4, DX_PRIMTYPE_TRIANGLESTRIP); });
	//effect->Rendering([&](){DrawPrimitive2DToShader(vertex2, 4, DX_PRIMTYPE_TRIANGLESTRIP); });

	//DrawGraph(0,0,hGraphics,TRUE);
}
