#ifndef POST_EFFECT
#define POST_EFFECT

#include<functional>
#include<DxLib.h>

/*
ポストエフェクトに使う描画ターゲットは1つ
*/

class BaseEffect;

class PostEffect
{
public:
	PostEffect(int hGraphics, BaseEffect* effect);
	virtual ~PostEffect();

	void Rendaring(std::function<void()> Draw);
	
private:


private:
	int hGraphics;//この一つのハンドルをいろんなポストエフェクトで使いまわす
	BaseEffect* effect;
	VERTEX2DSHADER vertex[4];
};

#endif