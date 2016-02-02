#ifndef _GSYSTEM_COLOR_H_
#define _GSYSTEM_COLOR_H_

#include "SystemHub.h"

struct Color{
public:
	char GetR();
	void SerR(char r);
	char GetG();
	void SerG(char g);
	char GetB();
	void SerB(char b);
	char GetA();
	void SerA(char a);
private:
	unsigned int color;

	unsigned int AdaptationRed();
	unsigned int AdaptationGreen();
	unsigned int AdaptationBlue();
	unsigned int AdaptationAlpha();
};



#endif
