#ifndef _GSYSTEM_RANDOM_H_
#define _GSYSTEM_RANDOM_H_

#include "SystemHub.h"
#include "Macro.h"
class Random
{
public:
	~Random();
	Random*	Instance();
	void	SetSeed(int seed);
	int		GetRandom(int max);
	int		GetRandom(int min, int max);
	double	GetRandomD();
	double	GetRandomD(double max);
	double	GetRandomD(double min, double max);
	float	GetRandomF();
	float	GetRandomF(float max);
	float	GetRandomF(float min, float max);
private:
	Random();
	Random* instance;

};


#endif