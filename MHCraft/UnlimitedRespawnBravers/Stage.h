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

	//�z��̃`�F�b�N
	int RightCheck(int y, int x);//�E���`�F�b�N

	int LeftCheck(int y, int x);//��

	int HeightCheck(int y, int x);//��

	int LowCheck(int y, int x);//��

	int HeightRightCheck(int y, int x);//�E��

	int HeightLeftCheck(int y, int x);//����

	int LowRightCheck(int y, int x);//�E��

	int LowLeftCheck(int y, int x);//����

	//���͂̌����@���ڂ͎g��Ȃ�
	int CheckIndex(int y, int x, int checkX, int checkY);
	//�z��O�Q�ƃ`�F�b�N
	bool OutOfLength(int y, int x, int checkX, int checkY);

private:
	void mapEach(std::function<void(int, int)> Action);

	std::vector <std::vector<int>> mapDate;

	std::function<void(int, int)> Action;

	Random* rnd;
};

#endif