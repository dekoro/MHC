#ifndef CUT_EFFECT
#define CUT_EFFECT

#include"Timer.h"
#include"Vec2.h"
#include"Fragment.h"


class CutEffect
{
public:
	CutEffect(int time = 60,Vec2 direction = Vec2());
	~CutEffect();

	void Initialize();

	void Update();

	//カットしたいグラフィックハンドル
	void Cut(int hGraphics, Vec2 pos);

	void IsStart();

private:
	Frangment right;
	Frangment left;
	Timer timer;
	bool isStart;
	const float SPEED = 4;

};

#endif