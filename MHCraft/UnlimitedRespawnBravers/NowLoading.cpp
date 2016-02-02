#define LENGTH 300//����
#define WIDTH_BEGIN  450//��`�̂͂��߂�
#define WIDTH_END    750//��`�̏I���
#define HIGHT_BEGIN  600
#define HIGHT_END	 640
#include"NowLoading.h"
#include<DxLib.h>
#include<assert.h>

//�����F���[�h��ʂɎg���摜�̃p�X
void NowLoading(const char* filePath)
{
	float scale,tmp;

	tmp = GetASyncLoadNum();

	int graHundle = LoadGraph(filePath);

	assert(graHundle != -1 && "�ǂݍ��݂Ɏ��s���܂����B�t�@�C���p�X���m�F���Ă�������");

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