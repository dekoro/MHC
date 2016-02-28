#include"AnimeDirection.h"


AnimeDirection::AnimeDirection()
{
}

AnimeDirection::~AnimeDirection()
{
}

void AnimeDirection::AddMotion(e_Motion motionName, std::vector<int> motions, int intarval, bool isLoop, e_AnimeDirection direction)
{
	anime[direction].AddMotion(motionName, motions, intarval, isLoop);
}

void AnimeDirection::Initialize()
{
	Each([&](int i){anime[i].Initialize();});
	
}

void AnimeDirection::Update()
{
	Each([&](int i){anime[i].Update(); });

}

int AnimeDirection::GetMotion(e_AnimeDirection direction)
{
	return anime[direction].GetMotion();
}

bool AnimeDirection::IsEnd(e_AnimeDirection direction)
{
	return anime[direction].IsEnd();
}

void AnimeDirection::ChangeMotion( e_Motion name)
{
	anime[e_AnimeRight].ChangeMotion(name);
	anime[e_AnimeLeft].ChangeMotion(name);
}

void AnimeDirection::Each(std::function<void(int)> action)
{
	for (int i = 0; i < elementNum; ++i)
	{
		action(i);
	}
}