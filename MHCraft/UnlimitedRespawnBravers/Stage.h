#ifndef STAGE
#define STAGE

#include<vector>
#include<functional>
#include"Random.h"

enum e_Direction
{
	e_Height,
	e_Low,
	e_MapRight,
	e_MapLeft,
	e_Height_Right,
	e_Height_Left,
	e_Low_Right,
	e_Low_Left,
	e_Norn,
};

class Stage
{
public:
	Stage(std::vector <std::vector<int>> date);
	Stage(int mapSizeX, int mapSizeY);
	~Stage();

	void Draw();

private:
	void MapCreate();

	void WaterGenerate();

	void CheckCircumference(int y, int x,int mapNum);//�w�肳�ꂽ�}�b�v�`�b�v������ɉ����邩����

	void Generate(int y, int x, int num, int condition, int ifMapNum, int elseMapNum);

	bool ScopeSearch(int begine1, int end1, int begine2, int end2, int mapNum);//�w��͈͂��w�肳�ꂽ���̂����邩�T��

	void MapTipEncode(int mapNum);//�w�肵���}�b�v�`�b�v�̉������ĉ�����������Ԃ�

	e_Direction DirectionCheck(int y, int x, int mapNum);

	//�z��̃`�F�b�N
	bool RightCheck(int y, int x, int checNum);//�E���`�F�b�N

	bool LeftCheck(int y, int x, int checNum);//��
	
	bool HeightCheck(int y, int x, int checNum);//��
	
	bool LowCheck(int y, int x, int checNum);//��
	
	bool HeightRightCheck(int y, int x, int checNum);//�E��
	
	bool HeightLeftCheck(int y, int x, int checNum);//����
	
	bool LowRightCheck(int y, int x, int checNum);//�E��
	
	bool LowLeftCheck(int y, int x, int checNum);//����

	//���͂̌����@���ڂ͎g��Ȃ�
	int CheckIndex(int y, int x, int checkX, int checkY);
	//�z��O�Q�ƃ`�F�b�N
	bool OutOfLength(int y, int x, int checkX, int checkY);

private:
	void mapEach(std::function<void(int, int)> Action);

	std::vector <std::vector<int>> mapDate;

	Random* rnd;

	int floorFieldCount;//�n�ʃt�B�[�����������_���Ō��߂�
	int waterFieldCount;//���̐��������_���Ɍ��߂�


	const int FLOOR = 15;

	const int WATER = 1;
	const int WATER_HEIGHT = 14;
	const int WATER_LOW = 7;
	const int WATER_RIGHT = 13;
	const int WATER_LEFT = 8;
	const int WATER_HEIGHT_RIGHT = 11;
	const int WATER_HEIGHT_LEFT = 10;
	const int WATER_LOW_RIGHT  =9;
	const int WATER_LOW_LEFTT = 12;
};

#endif