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
			mapDate[y][x] = FLOOR;
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
	for (int i = 0; i < 30; i++)
	{
		WaterGenerate();
	}

	MapTipEncode(WATER);

}


void Stage::WaterGenerate()
{
	int width = rnd->GetRandom(5, 20);
	int height = rnd->GetRandom(5, 20);

	int arrangePositionX = rnd->GetRandom(mapDate.size());
	int arrangePositionY = rnd->GetRandom(mapDate[0].size());

	if (ScopeSearch(arrangePositionY, height, arrangePositionX, width, FLOOR))//範囲がすべて床か検索
	{
		for (int y = arrangePositionY; y < height + arrangePositionY; ++y)
		{
			for (int x = arrangePositionX; x < width + arrangePositionX; ++x)
			{
				mapDate[y][x] = WATER;
			}
		}
	}


}

void Stage::MapTipEncode(int mapNum)
{
	mapEach([&](int y, int x){
		if (mapDate[y][x] == mapNum)
		{
			e_Direction dir = DirectionCheck(y,x,FLOOR);

			switch (dir)
			{
			case e_Height:
				mapDate[y][x] = WATER_HEIGHT;
				break;
			case e_Low:
				mapDate[y][x] = WATER_LOW;
				break;
			case e_MapRight:
				mapDate[y][x] = WATER_RIGHT;
				break;
			case e_MapLeft:
				mapDate[y][x] = WATER_LEFT;
				break;
			case e_Height_Right:
				mapDate[y][x] = WATER_HEIGHT_RIGHT;
				break;
			case e_Height_Left:
				mapDate[y][x] = WATER_HEIGHT_LEFT;
				break;
			case e_Low_Right:
				mapDate[y][x] = WATER_LOW_RIGHT;
				break;
			case e_Low_Left:
				mapDate[y][x] = WATER_LOW_LEFTT;
				break;
			case e_Norn:
				break;
			default:
				break;
			}

		}

		//if (mapDate[y][x] == mapNum)
		//{
		//	e_Direction dir = DirectionCheck(y, x, WATER);

		//	switch (dir)
		//	{
		//	case e_Height_Right:
		//		mapDate[y][x] = WATER_CORNER_HEIGHT_RIGHT;
		//		break;
		//	case e_Height_Left:
		//		mapDate[y][x] = WATER_CORNER_HEIGHT_LEFT;
		//		break;
		//	case e_Low_Right:
		//		mapDate[y][x] = WATER_CORNER_LOW_RIGHT;
		//		break;
		//	case e_Low_Left:
		//		mapDate[y][x] = WATER_CORNER_LOW_LEFT;
		//		break;
		//	case e_Norn:
		//		break;
		//	default:
		//		break;
		//	}
		//}
	});
}

e_Direction Stage::DirectionCheck(int y, int x,int mapNum)
{
	if (HeightRightCheck(y, x, mapNum) && RightCheck(y, x, mapNum) && HeightCheck(y, x, mapNum))
		return e_Height_Right;
	if (HeightLeftCheck(y, x, mapNum) && LeftCheck(y, x, mapNum) && HeightCheck(y, x, mapNum))
		return e_Height_Left;
	if (LowRightCheck(y, x, mapNum) && RightCheck(y, x, mapNum) && LowCheck(y, x, mapNum))
		return e_Low_Right;
	if (LowLeftCheck(y, x, mapNum) && LeftCheck(y, x, mapNum) && LowCheck(y, x, mapNum))
		return e_Low_Left;

	if (RightCheck(y, x, mapNum))
		return e_MapRight;
	if (LeftCheck(y, x, mapNum))
		return e_MapLeft;
	if (HeightCheck(y, x, mapNum))
		return e_Height;
	if (LowCheck(y, x, mapNum))
		return e_Low;

	return e_Norn;
}

//スペースが空いてるか確認する
bool Stage::ScopeSearch(int begin1, int end1, int begin2, int end2, int mapNum)
{
	int count = 0;

	for (int y = begin1; y < end1 + begin1; ++y)
	{
		for (int x = begin2; x < end2 + begin2; ++x)
		{
			if (OutOfLength(y, x, 0, 0))
			{
				return false;
			}
			if (mapDate[y][x] == mapNum)
			{
				count++;
			}
		}
	}

	if (count >= end1 * end2)
	{
		return true;
	}
	return false;
}


void Stage::CheckCircumference(int y, int x, int mapNum)
{

	int count = 0;//周囲の対象の数

	count += RightCheck(y, x, mapNum);
	count += LeftCheck(y, x, mapNum);
	count += HeightCheck(y, x, mapNum);
	count += LowCheck(y, x, mapNum);
	count += HeightRightCheck(y, x, mapNum);
	count += HeightLeftCheck(y, x, mapNum);
	count += LowRightCheck(y, x, mapNum);
	count += LowLeftCheck(y, x, mapNum);

}


int Stage::CheckIndex(int y, int x, int checkX, int checkY)
{
	if (OutOfLength(y, x, checkX, checkY))
	{
		return 0;//配列が用意されていないところは0と仮定
	}

	return mapDate[y + checkY][x + checkX];
}

bool Stage::HeightCheck(int y, int x, int checNum)
{
	return CheckIndex(y, x, 0, -1) == checNum;
}

bool Stage::LowCheck(int y, int x, int checNum)
{
	return CheckIndex(y, x, 0, +1) == checNum;
}

bool Stage::RightCheck(int y, int x, int checNum)
{
	return  CheckIndex(y, x, 1, 0) == checNum;
}

bool Stage::LeftCheck(int y, int x, int checNum)
{
	return CheckIndex(y, x, -1, 0) == checNum;
}

bool Stage::HeightRightCheck(int y, int x, int checNum)
{
	return CheckIndex(y, x, 1, -1) == checNum;
}

bool Stage::HeightLeftCheck(int y, int x, int checNum)
{
	return CheckIndex(y, x, -1, -1) == checNum;
}

bool Stage::LowRightCheck(int y, int x, int checNum)
{
	return CheckIndex(y, x, 1, 1) == checNum;
}

bool Stage::LowLeftCheck(int y, int x, int checNum)
{
	return CheckIndex(y, x, -1, 1) == checNum;
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

