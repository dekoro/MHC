#ifndef TIMER
#define TIMER

/*
カウントアップ形式のタイマー
*/

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
	bool IsEnd();

	float Rate();
protected:
	int currentTime;
	int maxTime;

};
#endif