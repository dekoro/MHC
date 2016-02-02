#include "Random.h"

Random::Random(){

}

Random::~Random(){
	SAFE_DELETE(instance);
}

Random* Random::Instance(){
	if (!instance){
		instance = new Random();
	}
	return instance;
}

void Random::SetSeed(int seed){
	SRand(seed);
}

int Random::GetRandom(int max){
	return GetRand(max);
}

int Random::GetRandom(int min, int max){
	return GetRand(max - min) + min;
}

double Random::GetRandomD(){
	int rnd = 65535;
	return (double)GetRand(rnd) / rnd;
}

double Random::GetRandomD(double max){
	return GetRandomD()*max;
}

double Random::GetRandomD(double min, double max){
	return GetRandomD()*(max - min) + min;
}

float Random::GetRandomF(){
	int rnd = 65535;
	return (float)GetRand(rnd) / rnd;

}

float Random::GetRandomF(float max){
	return GetRandomF()*max;
}

float Random::GetRandomF(float min, float max){
	return GetRandomF()*(max - min) + min;
}



