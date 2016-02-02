#include "GCircle.h"

GCircle::GCircle(Vec2 centerPos, double radius){
	this->posCenter	= centerPos;
	this->radius	= radius;
}

GCircle GCircle::Setup(Vec2 centerPos, double radius){
	GCircle tmp;
	tmp.posCenter	= centerPos;
	tmp.radius		= radius;
	return tmp;
}





