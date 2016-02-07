#include"PostEffect.h"
#include<DxLib.h>
#include"BaseEffect.h"
#include"GSystem.h"
#include"ChildWindow.h"

//レイアウトが無ければシングルウィンドウ用配置
PostEffect::PostEffect(BaseEffect* effect) : hGraphics(hGraphics), effect(effect)
{
	this->hGraphics = MakeScreen(Window::WIDTH, Window::HEIGHT);

	VertexErch([&](int i){
		vertex[i].pos = VGet((i % 2) * Window::WIDTH, (i / 2) * Window::HEIGHT, 0);
		vertex[i].rhw = 1.0f;//アルファ値
		vertex[i].dif = GetColorU8(255, 255, 255, 255);
		vertex[i].spc = GetColorU8(0, 0, 0, 0);
		vertex[i].u = vertex[i].su = (float)(i % 2);
		vertex[i].v = vertex[i].sv = (float)(i / 2);
	});
}

//とりあえずswitchで、後でファクタリング
PostEffect::PostEffect(BaseEffect* effect, e_ScreenLayout layOut, e_ScreenNumber number) : hGraphics(hGraphics), effect(effect)
{
	int lWidth = Window::WIDTH, lHeight = Window::HEIGHT;

	//画面の数に応じてレンダーターゲットを配置
	switch (layOut)
	{
	case e_Double:
		lWidth = Window::WIDTH / 2;
		lHeight = Window::HEIGHT;

		this->hGraphics = MakeScreen(lWidth, lHeight / 2);

		switch (number)
		{
		case e_First:
		default:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) * lHeight, 0);
			});
			break;
		case e_Second:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth + (lWidth), (i / 2) * lHeight, 0);
			});
			break;
		}
		break;
	case e_Triple:
		lWidth = Window::WIDTH / 2;
		lHeight = Window::HEIGHT / 2;
		this->hGraphics = MakeScreen(lWidth, lHeight);
		switch (number)
		{
		case e_First:
		default:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) *lHeight, 0);
			});

			break;
		case e_Second:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth + (lWidth), (i / 2) * lHeight, 0);
			});
			break;
		case e_Third:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) * lHeight + (lHeight), 0);
			});
			break;
		}
		break;
	case e_Quad:
		lWidth = Window::WIDTH / 2;
		lHeight = Window::HEIGHT / 2;
		this->hGraphics = MakeScreen(lWidth, lHeight);
		switch (number)
		{
		case e_First:
		default:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) * lHeight, 0);
			});

			break;
		case e_Second:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth + (lWidth), (i / 2) * lHeight, 0);
			});
			break;
		case e_Third:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) * lHeight + (lHeight), 0);
			});
			break;
		case e_Fourth:
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth + (lWidth), (i / 2) * lHeight + (lHeight), 0);
			});
			break;
		}
		break;

		//1Pかどれでもなかったら1P画面
	case e_Single:
	default:
		this->hGraphics = MakeScreen(lWidth, lHeight);
		VertexErch([&](int i){
			vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) * lHeight, 0);
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

	//effect->Rendering([&](){

	DrawPrimitive2DToShader(vertex, 4, DX_PRIMTYPE_TRIANGLESTRIP);

	//});
}


void PostEffect::VertexErch(std::function<void(int x)> action)
{
	for (int i = 0; i < 4; ++i)
	{
		action(i);
	}
}