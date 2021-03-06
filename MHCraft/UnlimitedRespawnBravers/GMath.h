#ifndef _GSYSTEM_GMATH_H_
#define _GSYSTEM_GMATH_H_

#include "SystemHub.h"
#include "GSystem.h"
#include "Vec2.h"
#include "GRectangle.h"
#include "GCircle.h"
#include "Debug.h"
class GMath
{
public:
	GMath();
	~GMath();

	static int Sum(int a, int b);
	template<typename T> static int GetCountMaxSize(T dataType, int oneLoopSize);
	static double	ChangeDegToRad(double angleDeg);
	static double	ChangeRadToDeg(double angleRad);
	static double	CalcAngleRad(Vec2 fromPos, Vec2 toPos);
	static bool		CheckHitCircleToCircle(GCircle circle1, GCircle circle2);
	static bool		CheckHitCircleToCircle(Vec2 posCenter1, int radius1		, Vec2 posCenter2, int radius2);
	static bool		CheckHitCircleToCircle(Vec2 posCenter1, double radius1	, Vec2 posCenter2, double radius2);
	static bool		CheckHitCircleToRectangle(GCircle circle, GRectangle rectangle);
	static bool		CheckHitCircleToRectangle(Vec2 posCenterCircle, double radiusCirle	, Vec2 posRectangleTL, Vec2 posRectangleBR);
	static bool		CheckHitCircleToRectangle(Vec2 posCenterCircle, double radiusCirle	, GRectangle rectangle);
	static bool		CheckHitCircleToPoint(GCircle circle, Vec2 posPoint);
	static bool		CheckHitCircleToPoint(Vec2 posCenterCircle, double radius, Vec2 posPoint);

	static bool		CheckHitRectangleToPoint(GRectangle rectangle, Vec2 point);
	static bool		CheckHitRectangleToRectangle(GRectangle rect1, GRectangle rect2);
	static bool		CheckHitRectangleToRectangle(Vec2 pos1TL, Vec2 pos1BR, Vec2 pos2TL, Vec2 pos2BR);

private:

};


#endif