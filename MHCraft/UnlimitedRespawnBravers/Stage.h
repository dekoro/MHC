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

	void CheckCircumference(int y, int x,int mapNum);//指定されたマップチップが周りに何個あるか見る

	void Generate(int y, int x, int num, int condition, int ifMapNum, int elseMapNum);

	bool ScopeSearch(int begine1, int end1, int begine2, int end2, int mapNum);//指定範囲を指定されたものがあるか探す

	void MapTipEncode(int mapNum);//指定したマップチップの回りを見て何個あったかを返す

	e_Direction DirectionCheck(int y, int x, int mapNum);

	//配列のチェック
	bool RightCheck(int y, int x, int checNum);//右側チェック

	bool LeftCheck(int y, int x, int checNum);//左
	
	bool HeightCheck(int y, int x, int checNum);//上
	
	bool LowCheck(int y, int x, int checNum);//下
	
	bool HeightRightCheck(int y, int x, int checNum);//右上
	
	bool HeightLeftCheck(int y, int x, int checNum);//左上
	
	bool LowRightCheck(int y, int x, int checNum);//右下
	
	bool LowLeftCheck(int y, int x, int checNum);//左下

	//周囲の検索　直接は使わない
	int CheckIndex(int y, int x, int checkX, int checkY);
	//配列外参照チェック
	bool OutOfLength(int y, int x, int checkX, int checkY);

private:
	void mapEach(std::function<void(int, int)> Action);

	std::vector <std::vector<int>> mapDate;

	Random* rnd;

	int floorFieldCount;//地面フィール数をランダムで決める
	int waterFieldCount;//水の数をランダムに決める


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