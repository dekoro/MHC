#include"Stage.h"
#include"DeviceManager.h"
#include"ImageRenderer.h"


Stage::Stage(std::vector <std::vector<int>> mapDate) : mapDate(mapDate)
{
}


Stage::~Stage()
{
}

void Stage::Draw()
{
	mapEach([&](int y, int x)
	{
		DeviceManager::GetInstance()->Image()->DrawLT(DeviceManager::GetInstance()->Image()->GetMapTipHundle(mapDate[y][x]),
			Vec2((x * -DeviceManager::GetInstance()->Image()->GetMapTipSize().X) + (50* 32),
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
