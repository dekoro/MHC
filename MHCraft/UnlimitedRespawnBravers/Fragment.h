#ifndef FRAGMENT
#define FRAGMENT
#include"Vec2.h"
#include"e_Directon.h"
#include"Cutting.h"

class BaseEffect;

class Frangment
{
public:
	Frangment(Vec2 direction, float velocity,e_CutDirection e_Direction);
	~Frangment();
	void Initialize();

	void Update();

	void Draw(int hGraphics,Vec2 pos);

	bool IsEnd();

private:
	Cutting fragment;//êÿíféûÇÃífï–
	Vec2 pos;
	Vec2 direction;
	const Vec2 originDirection;
	const Vec2  velocity;
	const float END_VELOCITY = 10.0f;
};

#endif