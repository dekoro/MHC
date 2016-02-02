#ifndef TIMER
#define TIMER

class Timer
{
public:
	Timer();
	Timer(int time);
	~Timer();

	void Initialize();
	void Update();
	int GetTime();
	int GetMaxTim();
protected:
	int currentTime;
	int maxTime;

};
#endif