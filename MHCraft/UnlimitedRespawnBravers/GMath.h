#ifndef _GSYSTEM_GMATH_H_
#define _GSYSTEM_GMATH_H_

#include "SystemHub.h"

class Vec2;
class GCircle;
class GRectangle;
class GQuadrangle;


class GMath
{
public:
	GMath();
	~GMath();

	static bool Inner(int value, int min, int max);
	template<typename T> static T Clamp(T value, T min, T max);
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
	static bool		CheckHitCircleToQuadrangle(GCircle circle, GQuadrangle quadrangle);
	static bool		CheckHitCircleToPoint(GCircle circle, Vec2 posPoint);
	static bool		CheckHitCircleToPoint(Vec2 posCenterCircle, double radius, Vec2 posPoint);

	static bool		CheckHitRectangleToPoint(GRectangle rectangle, Vec2 point);
	static bool		CheckHitRectangleToRectangle(GRectangle rect1, GRectangle rect2);
	static bool		CheckHitRectangleToRectangle(Vec2 pos1TL, Vec2 pos1BR, Vec2 pos2TL, Vec2 pos2BR);
	static Vec2		GetStickStateToVec2(short ThumbX, short ThumbY);
	static float	CutHighAndLow(float value, float high, float low, float start = 0, float end = 1);
	static float	CutNearAndFarByZero(float value, float nearByZero, float farByZero, float end = 1);
private:

};


#endif