#ifndef ZOOM_BLUR
#define ZOOM_BLUR

#include"BaseEffect.h"
#include"GSystem.h"
#include"Timer.h"

class ZoomBlur  : public BaseEffect
{
public:
	ZoomBlur();
	~ZoomBlur();

	void Initialize()override;

	bool IsEnd();

	void IsStart();
private:
	void ConstSet()override;

private:
	const Vec2 Center;
	bool isStart;
	Timer timer;

};

#endif