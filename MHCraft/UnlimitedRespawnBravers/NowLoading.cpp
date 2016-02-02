#define LENGTH 300//長さ
#define WIDTH_BEGIN  450//矩形のはじめり
#define WIDTH_END    750//矩形の終わり
#define HIGHT_BEGIN  600
#define HIGHT_END	 640
#include"NowLoading.h"
#include<DxLib.h>
#include<assert.h>

//引数：ロード画面に使う画像のパス
void NowLoading(const char* filePath)
{
	float scale,tmp;

	tmp = GetASyncLoadNum();

	int graHundle = LoadGraph(filePath);

	assert(graHundle != -1 && "読み込みに失敗しました。ファイルパスを確認してください");

	while (GetASyncLoadNum() != 0 && !ProcessMessage())
	{
		ClearDrawScreen();

		scale = GetASyncLoadNum() / tmp;

		DrawGraph(0,0,graHundle,true);

		DrawBox(WIDTH_BEGIN, HIGHT_BEGIN, WIDTH_END, HIGHT_END, GetColor(0, 50, 100), TRUE);

		DrawBox(WIDTH_BEGIN, HIGHT_BEGIN, WIDTH_END - (LENGTH  * scale), HIGHT_END, GetColor(0, 100, 100), TRUE);

		DrawFormatString(550, 580, GetColor(0, 100, 100), "%s", "NowLoading");

		ScreenFlip();
	}

	MV1DeleteModel(graHundle);
}