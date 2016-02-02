#include"BaseEffect.h"
#include<DxLib.h>
#include<assert.h>

BaseEffect::BaseEffect(int psHundle, int vsHundle)
{
	ps = psHundle;
	vs = vsHundle;

	assert(ps != -1 || vs != -1 && "シェーダの読み込みに失敗しました");
};

BaseEffect::~BaseEffect()
{
	DeleteShader(ps);
	DeleteShader(vs);
};


void BaseEffect::Rendering(std::function<void()> Draw)
{
	assert(vs != -1 || ps != -1 && "オリジナルシェーダーが読み込みに失敗しています");

	MV1SetUseOrigShader(TRUE);//シェーダ使用ＯＮ

	//if (vs != 0)
		SetUseVertexShader(vs);

	//if (ps != 0)
		SetUsePixelShader(ps);

	ConstantShader();//シェーダに定数を渡す

	Draw();//描画処理

	MV1SetUseOrigShader(FALSE);//シェーダ使用ＯFF
}
