#ifndef POST_EFFECT
#define POST_EFFECT

#include<functional>
#include<DxLib.h>
#include"e_ScreenLayout.h"
#include<functional>
#include"EffectList.h"
#include"Camera.h"


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
	PostEffect(Player* player);
	PostEffect(Player* player,e_ScreenLayout lauOut, e_ScreenNumber);//スクリーンの番号をそのままカメラのインプットに割り当てる
	virtual ~PostEffect();

	void Initialize();//シーンがシェーダの読み込みが終わってから実行する

	void Rendaring(std::function<void()> Draw, float scale);

private:
	void VertexErch(std::function<void(int x)> action);


private:
	int hGraphics;
	BaseEffect* effect;
	EffectList effetList;
	VERTEX2DSHADER vertex[4];
	Camera camera;
	unsigned int color;
};

#endif