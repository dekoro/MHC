#ifndef _ANIME_DIRECTION_
#define _ANIME_DIRECTION_

#include "Animation.h"
#include <functional>

enum e_AnimeDirection
{
	e_AnimeRight = 0,
	e_AnimeLeft = 1,
};

class AnimeDirection
{
public:
	AnimeDirection(){}
	~AnimeDirection(){}

	void Initialize();

	void AddMotion(e_Motion motionName, std::vector<int> motions, int intarval, bool isLoop, e_AnimeDirection direction);

	void Update();

	int GetMotion(e_AnimeDirection direction);

	void ChangeMotion( e_Motion name);

	bool IsEnd(e_AnimeDirection direction);

	void Each(std::function<void(int)> action);

private:
	Animation anime[2];
	const int elementNum = 2;

};

#endif