#include"PostEffect.h"
#include<DxLib.h>
#include"BaseEffect.h"
#include"GSystem.h"
#include"ChildWindow.h"

//レイアウトが無ければシングルウィンドウ用配置
PostEffect::PostEffect(BaseEffect* effect) : hGraphics(hGraphics), effect(effect)
{
	this->hGraphics = MakeScreen(Window::WIDTH, Window::HEIGHT);
	this->color = GetColor(255,0,0);
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
			this->color = GetColor(255, 0, 0);
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) * lHeight, 0);
			});
			break;
		case e_Second:
			this->color = GetColor(0, 0, 255);
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
			this->color = GetColor(255, 0, 0);
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) *lHeight, 0);
			});

			break;
		case e_Second:
			this->color = GetColor(0, 0, 255);
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth + (lWidth), (i / 2) * lHeight, 0);
			});
			break;
		case e_Third:
			this->color = GetColor(0, 255, 0);
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
			this->color = GetColor(255, 0, 0);
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) * lHeight, 0);
			});

			break;
		case e_Second:
			this->color = GetColor(0, 0, 255);
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth + (lWidth), (i / 2) * lHeight, 0);
			});
			break;
		case e_Third:
			this->color = GetColor(0, 255, 0);
			VertexErch([&](int i){
				vertex[i].pos = VGet((i % 2) * lWidth, (i / 2) * lHeight + (lHeight), 0);
			});
			break;
		case e_Fourth:
			this->color = GetColor(0, 255, 255);
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

void PostEffect::Rendaring(std::function<void()> Draw,float scale)
{
	SetDrawScreen(this->hGraphics);

	ClearDrawScreen();
	SetupCamera_Ortho(1000);//２Ｄカメラ設定

	Draw();

	SetDrawScreen(DX_SCREEN_BACK);

	SetUseTextureToShader(0, hGraphics);

	//effect->Rendering([&](){

	DrawPrimitive2DToShader(vertex, 4, DX_PRIMTYPE_TRIANGLESTRIP);

	DrawLineBox(vertex[0].pos.x, vertex[0].pos.y, vertex[3].pos.x, vertex[3].pos.y,color);
	//});
}


void PostEffect::VertexErch(std::function<void(int x)> action)
{
	for (int i = 0; i < 4; ++i)
	{
		action(i);
	}
}