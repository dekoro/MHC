#include"PostEffect.h"
#include<DxLib.h>
#include"BaseEffect.h"
#include"GSystem.h"

//レイアウトが無ければシングルウィンドウ用配置
PostEffect::PostEffect(int hGraphics, BaseEffect* effect) : hGraphics(hGraphics), effect(effect)
{

	VertexErch([&](int i){
		vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT, 0);
		vertex[i].rhw = 1.0f;//アルファ値
		vertex[i].dif = GetColorU8(255, 255, 255, 255);
		vertex[i].spc = GetColorU8(0, 0, 0, 0);
		vertex[i].u = vertex[i].su = (float)(i % 2);
		vertex[i].v = vertex[i].sv = (float)(i / 2);
	});
}

PostEffect::PostEffect(int hGraphics, BaseEffect* effect, e_ScreenLayout layOut) : hGraphics(hGraphics), effect(effect)
{
	//画面の数に応じてレンダーターゲットを配置
	switch (layOut)
	{
	case e_Single:
		VertexErch([&](int i){
			vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT, 0);
		});
		break;
	case e_Double:
		VertexErch([&](int i){
			vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT, 0);
		});
		break;

	case e_Triple:
		VertexErch([&](int i){
			vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT, 0);
		});
		break;
	case e_Quad:
		VertexErch([&](int i){
			vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT, 0);
		});
		break;

	//どれでもなかったら1P画面
	default:
		VertexErch([&](int i){
			vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT, 0);
		});
		break;
	}

	VertexErch([&](int i)
	{
		vertex[i].rhw = 1.0f;//アルファ値
		vertex[i].dif = GetColorU8(255, 255, 255, 255);
		vertex[i].spc = GetColorU8(0, 0, 0, 0);
		vertex[i].u = vertex[i].su = (float)(i % 2);
		vertex[i].v = vertex[i].sv = (float)(i / 2);
	});



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

	effect->Rendering([&](){DrawPrimitive2DToShader(vertex, 4, DX_PRIMTYPE_TRIANGLESTRIP); });
}


void PostEffect::VertexErch(std::function<void(int x)> action)
{
	for (int i = 0; i < 4; ++i)
	{
		action(i);
	}
}