#include"Timer.h"


Timer::Timer()
{
	this->maxTime = 60;
}

Timer::Timer(int maxTime)
{
	this->maxTime = maxTime;
}

Timer::~Timer()
{
}

void Timer::Initialize()
{
	currentTime = 0;
}

void Timer::Update()
{
	currentTime = currentTime > maxTime ? 0 : currentTime + 1;
}

int Timer::GetTime()
{
	return currentTime;
}

int Timer::GetMaxTim()
{
	return maxTime;
}