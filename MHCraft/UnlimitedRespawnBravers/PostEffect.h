#ifndef POST_EFFECT
#define POST_EFFECT

#include<functional>
#include<DxLib.h>
#include"e_ScreenLayout.h"
#include<functional>

/*
ポストエフェクト
このクラス１つにつき１つのゲーム画面。
４つに画面分割する場合は４つ生成する。

コンストラクタで受け取るエフェクトは、ピクセルシェーダを含みかつテクスチャマッピングをする物。
引数のエフェクトによって画面に与えるエフェクトを変える。
*/

class BaseEffect;

class PostEffect
{
public:
	//エフェクトは後でシングルトンにする必要がありそう。
	PostEffect(BaseEffect* effect);
	PostEffect(BaseEffect* effect, e_ScreenLayout lauOut, e_ScreenNumber);
	virtual ~PostEffect();

	void Rendaring(std::function<void()> Draw,float scale);
	
private:
	void VertexErch(std::function<void (int x)> action);


private:
	int hGraphics;
	BaseEffect* effect;
	VERTEX2DSHADER vertex[4];
	unsigned int color;
};

#endif