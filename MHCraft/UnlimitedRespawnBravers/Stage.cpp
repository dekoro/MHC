#include"Stage.h"
#include"DeviceManager.h"
#include"ImageRenderer.h"
#include"Random.h"

Stage::Stage(std::vector <std::vector<int>> mapDate) : mapDate(mapDate)
{
}

Stage::Stage(int mapSizeX, int mapSizeY)
{
	rnd = Random::Instance();
	rnd->SetSeed(GetTickCount());
	this->mapDate.resize(mapSizeY);
	for (int y = 0; y < mapSizeY; ++y)
	{
		this->mapDate[y].resize(mapSizeX);
		for (int x = 0; x < mapSizeX; ++x)
		{
			mapDate[y][x] = rnd->GetRandom(1);
		}
	}

	MapCreate();
}

Stage::~Stage()
{
}

void Stage::Draw()
{
	mapEach([&](int y, int x)
	{
		DeviceManager::GetInstance()->Image()->DrawLT(DeviceManager::GetInstance()->Image()->GetMapTipHundle(mapDate[y][x]),
			Vec2((x * -DeviceManager::GetInstance()->Image()->GetMapTipSizeX()) + (50 * 32),
			(y* -DeviceManager::GetInstance()->Image()->GetMapTipSizeY()) + (50 * 32)
			));
	});
}

void Stage::mapEach(std::function<void(int y, int x)> Action)
{
	for (int y = 0, yEnd = mapDate.size(); y < yEnd; ++y)
	{
		for (int x = 0, xEnd = mapDate[y].size(); x < xEnd; ++x)
		{
			Action(y, x);
		}
	}
}

void Stage::MapCreate()
{

	for (int i = 0; i < 10; ++i)
	{
		mapEach([&](int y, int x)
		{
			CheckCircumference(y, x);
		});
	}
}


void Stage::CheckCircumference(int y, int x)
{

	int floorCount = 0;//ŽüˆÍ‚Ì’n–Ê‚Ì”
	using namespace std;
	function<void()> Action[8] = {
		[&](){ floorCount += RightCheck(y, x); },
		[&](){ floorCount += LeftCheck(y, x); },
		[&](){ floorCount += HeightCheck(y, x); },
		[&](){ floorCount += LowCheck(y, x); },
		[&](){ floorCount += HeightRightCheck(y, x); },
		[&](){ floorCount += HeightLeftCheck(y, x); },
		[&](){ floorCount += LowRightCheck(y, x); },
		[&](){ floorCount += LowLeftCheck(y, x); },
	};

	for (int i = 0; i < 8; ++i)
	{
		Action[i]();
	}



	Generate(y, x, floorCount);
}


void Stage::Generate(int y, int x, int num)
{
	static const float map_Denominator = mapDate.size() * mapDate[y].size(); 
	int mapFloorCount = 0;
	float mapRate = 0; 

	mapEach([&](int y,int x){
		if (mapDate[y][x] == 1)
			mapFloorCount++;
	});

	mapRate = (float)mapFloorCount / map_Denominator;

	static int rate[9] = 
	{0,10,20,20,50,80,80,90,100};

	int r = this->rnd->GetRandom(100);

	if (mapRate  >= 0.8)
	{
		rate[4] = 40;
	}
	else if (mapRate <= 0.8)
	{
		rate[4] = 60;
	}
	else
	{
		rate[4] = 50;
	}

	if (rate[num] >= r)
	{
		mapDate[y][x] = 1;
	}
	else
	{
		mapDate[y][x] = 0;
	}

}


int Stage::CheckIndex(int y, int x, int checkX, int checkY)
{
	if (OutOfLength(y, x, checkX, checkY))
	{
		return 0;//”z—ñ‚ª—pˆÓ‚³‚ê‚Ä‚¢‚È‚¢‚Æ‚±‚ë‚Í0‚Æ‰¼’è
	}

	return mapDate[y + checkY][x + checkX];
}

int Stage::HeightCheck(int y, int x)
{
	return CheckIndex(y, x, 0, -1) == 1 ? 1 : 0;
}

int Stage::LowCheck(int y, int x)
{
	return CheckIndex(y, x, 0, +1) == 1 ? 1 : 0;
}

int Stage::RightCheck(int y, int x)
{
	return  CheckIndex(y, x, 1, 0) == 1 ? 1 : 0;
}

int Stage::LeftCheck(int y, int x)
{
	return CheckIndex(y, x, -1, 0) == 1 ? 1 : 0;
}

int Stage::HeightRightCheck(int y, int x)
{
	return CheckIndex(y, x, 1, -1) == 1 ? 1 : 0;
}

int Stage::HeightLeftCheck(int y, int x)
{
	return CheckIndex(y, x, -1, -1) == 1 ? 1 : 0;
}

int Stage::LowRightCheck(int y, int x)
{
	return CheckIndex(y, x, 1, 1) == 1 ? 1 : 0;
}

int Stage::LowLeftCheck(int y, int x)
{
	return CheckIndex(y, x, -1, 1) == 1 ? 1 : 0;
}

bool Stage::OutOfLength(int y, int x, int checkX, int checkY)
{
	if (y + checkY < 0 ||
		y + checkY >= mapDate.size())
	{
		return true;
	}

	if (x + checkX < 0 ||
		x + checkX >= mapDate[y].size())
	{
		return true;
	}

	return false;
}

