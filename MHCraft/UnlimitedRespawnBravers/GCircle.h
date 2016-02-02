#ifndef _GSYSTEM_GCIRCLE_H_
#define _GSYSTEM_GCIRCLE_H_

#include "SystemHub.h"
#include "Vec2.h"

class GCircle
{
public:
	Vec2 posCenter;
	double radius;

	GCircle(Vec2 posCenter = Vec2::Zero(),double radius = 1);
	static GCircle Setup(Vec2 centerPos, double radius);

private:

};




#endif