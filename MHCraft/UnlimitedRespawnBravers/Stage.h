#ifndef STAGE
#define STAGE

#include<vector>
#include<functional>
#include"Random.h"

class Stage
{
public:
	Stage(std::vector <std::vector<int>> date);
	Stage(int mapSizeX, int mapSizeY);
	~Stage();

	void Draw();

private:
	void MapCreate();

	void CheckCircumference(int y, int x);

	void Generate(int y, int x, int num);

	//配列のチェック
	int RightCheck(int y, int x);//右側チェック

	int LeftCheck(int y, int x);//左

	int HeightCheck(int y, int x);//上

	int LowCheck(int y, int x);//下

	int HeightRightCheck(int y, int x);//右上

	int HeightLeftCheck(int y, int x);//左上

	int LowRightCheck(int y, int x);//右下

	int LowLeftCheck(int y, int x);//左下

	//周囲の検索　直接は使わない
	int CheckIndex(int y, int x, int checkX, int checkY);
	//配列外参照チェック
	bool OutOfLength(int y, int x, int checkX, int checkY);

private:
	void mapEach(std::function<void(int, int)> Action);

	std::vector <std::vector<int>> mapDate;

	std::function<void(int, int)> Action;

	Random* rnd;
};

#endif