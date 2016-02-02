#ifndef POST_EFFECT
#define POST_EFFECT

#include<functional>
#include<DxLib.h>

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
	PostEffect(int hGraphics, BaseEffect* effect);
	virtual ~PostEffect();

	void Rendaring(std::function<void()> Draw);
	
private:


private:
	int hGraphics;
	BaseEffect* effect;
	VERTEX2DSHADER vertex[4];
};

#endif