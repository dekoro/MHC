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
			Vec2((x * -DeviceManager::GetInstance()->Image()->GetMapTipSize().X) + (50 * 32),
			(y* -DeviceManager::GetInstance()->Image()->GetMapTipSize().Y) + (50 * 32)
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

	for (int i = 0; i < 100; ++i)
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
	using namespace std;

	function<void()> Action[9] = {
		[&](){ mapDate[y][x] = ChangeMap0(); },
		[&](){ mapDate[y][x] = ChangeMap1(); },
		[&](){ mapDate[y][x] = ChangeMap2(); },
		[&](){ mapDate[y][x] = ChangeMap3(); },
		[&](){ mapDate[y][x] = ChangeMap4(); },
		[&](){ mapDate[y][x] = ChangeMap5(); },
		[&](){ mapDate[y][x] = ChangeMap6(); },
		[&](){ mapDate[y][x] = ChangeMap7(); },
		[&](){ mapDate[y][x] = ChangeMap8(); },
	};

	Action[num]();
}

int Stage::ChangeMap0()
{
	return 1;
}

int Stage::ChangeMap1()
{
	if (rnd->GetRandom(10) == 0)
		return 0;

	return 1;
}

int Stage::ChangeMap2()
{
	int num = rnd->GetRandom(10);
	if (num == 0 || num == 1)
		return 0;

	return 1;

}

int Stage::ChangeMap3()
{
	int num = rnd->GetRandom(10);
	if (num == 0 || num == 1)
		return 0;

	return 1;
}

int Stage::ChangeMap4()
{

	int num = rnd->GetRandom(1);
	if (num == 0)
		return 0;

	return 1;
}

int Stage::ChangeMap5()
{
	int num = rnd->GetRandom(10);
	if (num == 0 || num == 1)
		return 1;

	return 0;
}

int Stage::ChangeMap6()
{
	int num = rnd->GetRandom(10);
	if (num == 0 || num == 1)
		return 1;

	return 0;
}

int Stage::ChangeMap7()
{
	if (rnd->GetRandom(10) == 0)
		return 1;

	return 0;
}

int Stage::ChangeMap8()
{
	return 0;
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

