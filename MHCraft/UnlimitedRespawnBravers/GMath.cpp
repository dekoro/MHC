#include "GMath.h"
#include "GSystem.h"
#include "GRectangle.h"
#include "GCircle.h"
#include "Debug.h"
#include "Vec2.h"
#include "GQuadrangle.h"

GMath::GMath(){

}

GMath::~GMath(){

}

bool GMath::Inner(int value, int min, int max){
	return (min <= value && max > value);
}

template<typename T>
T GMath::Clamp(T value, T min, T max){
	if (value < min) { return min; }
	if (value > max) { return max; }
	return value;
}

template<typename T>
static int GMath::GetCountMaxSize(T dataType, int oneLoopSize){
	return ((int)sizeof(dataType)* 8 / oneLoopSize)*oneLoopSize;
}
double GMath::ChangeDegToRad(double angleDeg){
	return angleDeg * PI / 180;
}

double GMath::ChangeRadToDeg(double angleRad){
	return angleRad * 180 / PI;
}

double GMath::CalcAngleRad(Vec2 fromPos, Vec2 toPos){
	return atan2(toPos.Y - fromPos.Y, toPos.X - fromPos.X);
}

bool GMath::CheckHitCircleToCircle(GCircle circle1, GCircle circle2){
	return CheckHitCircleToCircle(circle1.posCenter, circle1.radius, circle2.posCenter, circle2.radius);
}

bool GMath::CheckHitCircleToCircle(Vec2 posCenter1, int radius1, Vec2 posCenter2, int radius2){
	return CheckHitCircleToCircle(posCenter1, (double)radius1, posCenter2, (double)radius2);
}

bool GMath::CheckHitCircleToCircle(Vec2 posCenter1, double radius1, Vec2 posCenter2, double radius2){
	return (posCenter1.Distance(posCenter2) <= (radius1+radius2));
}



bool GMath::CheckHitCircleToRectangle(GCircle circle, GRectangle rectangle){
	Vec2	posLT	= rectangle.GetPositionLeftTop();
	Vec2	posRB	= rectangle.GetPositionRightBottom();
	Vec2	posC	= circle.posCenter;
	double	radC	= circle.radius;

	GCircle	circleOverRectangle	= GCircle::Setup(rectangle.GetPositionCenter(), posLT.Distance(posRB)/2);
	if (!GMath::CheckHitCircleToCircle(circle, circleOverRectangle)){ return false; }

	Vec2	posRT	= rectangle.GetPositionRightTop();
	Vec2	posLB	= rectangle.GetPositionLeftBottom();

	if (Vec2::Cross(rectangle.GetPositionRightTop()		, rectangle.GetPositionLeftTop()		, circle.posCenter) > circle.radius){ return false; }
	if (Vec2::Cross(rectangle.GetPositionLeftTop()		, rectangle.GetPositionLeftBottom()		, circle.posCenter) > circle.radius){ return false; }
	if (Vec2::Cross(rectangle.GetPositionLeftBottom()	, rectangle.GetPositionRightBottom()	, circle.posCenter) > circle.radius){ return false; }
	if (Vec2::Cross(rectangle.GetPositionRightBottom()	, rectangle.GetPositionRightTop()		, circle.posCenter) > circle.radius){ return false; }
	return true;
}

bool GMath::CheckHitCircleToRectangle(Vec2 posCenterCircle, double radiusCirle, Vec2 posRectangleTL, Vec2 posRectangleBR){
	int rectWidth	= posRectangleBR.GetIntX() - posRectangleTL.GetIntX();
	int rectHeight	= posRectangleTL.GetIntY() - posRectangleBR.GetIntY();
	return CheckHitCircleToRectangle(GCircle::Setup(posCenterCircle, radiusCirle), GRectangle::Setup(posRectangleTL.GetIntX(), posRectangleTL.GetIntY(), rectWidth, rectHeight));
}

bool GMath::CheckHitCircleToRectangle(Vec2 posCenterCircle, double radiusCirle, GRectangle rectangle){
	return CheckHitCircleToRectangle(GCircle::Setup(posCenterCircle, radiusCirle), rectangle);
}

bool GMath::CheckHitCircleToQuadrangle(GCircle circle, GQuadrangle quadrangle){
	Vec2	posLT = quadrangle.GetPoint1();
	Vec2	posRB = quadrangle.GetPoint3();
	Vec2	posC = circle.posCenter;
	double	radC = circle.radius;

	GCircle	circleOverRectangle = GCircle::Setup(quadrangle.GetCenterPosition(), posLT.Distance(posRB) / 2);
	if (!GMath::CheckHitCircleToCircle(circle, circleOverRectangle)) { return false; }

	Vec2	posRT = quadrangle.GetPoint2();
	Vec2	posLB = quadrangle.GetPoint4();

	if (Vec2::Cross(posRT, posLT, circle.posCenter) > circle.radius) { return false; }
	if (Vec2::Cross(posLT, posLB, circle.posCenter) > circle.radius) { return false; }
	if (Vec2::Cross(posLB, posRB, circle.posCenter) > circle.radius) { return false; }
	if (Vec2::Cross(posRB, posRT, circle.posCenter) > circle.radius) { return false; }
	return true;

}


bool GMath::CheckHitCircleToPoint(GCircle circle, Vec2 posPoint){
	return (Vec2::Distance(circle.posCenter, posPoint) <= circle.radius);
}

bool GMath::CheckHitCircleToPoint(Vec2 posCenterCircle, double radius, Vec2 posPoint){
	GCircle circle = GCircle::Setup(posCenterCircle, radius);
	return CheckHitCircleToPoint(circle, posPoint);
}

bool GMath::CheckHitRectangleToPoint(GRectangle rectangle, Vec2 point){
	if (rectangle.GetLeft()		> point.X){ return false; }
	if (rectangle.GetRight()	< point.X){ return false; }
	if (rectangle.GetTop()		> point.Y){ return false; }
	if (rectangle.GetBottom()	< point.Y){ return false; }
	return true;
}

bool GMath::CheckHitRectangleToRectangle(GRectangle rect1, GRectangle rect2){
	if (rect1.GetLeft()		> rect2.GetRight())	 { return false; }
	if (rect1.GetRight()	< rect2.GetLeft())	 { return false; }
	if (rect1.GetTop()		> rect2.GetBottom()) { return false; }
	if (rect1.GetBottom()	< rect2.GetTop())	 { return false; }
	return true;
}

bool GMath::CheckHitRectangleToRectangle(Vec2 pos1TL, Vec2 pos1BR, Vec2 pos2TL, Vec2 pos2BR){
	GRectangle rect1(pos1TL.Y, pos1BR.Y, pos1TL.X, pos1BR.X);
	GRectangle rect2(pos2TL.Y, pos2BR.Y, pos2TL.X, pos2BR.X);
	return CheckHitRectangleToRectangle(rect1, rect2);
}


Vec2 GMath::GetStickStateToVec2(short ThumbX, short ThumbY) {
	float stateX = CutNearAndFarByZero((float)ThumbX / SHRT_MAX, CONTROLLER_STICK_LOWER_LIMIT, CONTROLLER_STICK_HIGHER_LIMIT);
	float stateY = CutNearAndFarByZero((float)ThumbY / SHRT_MAX, CONTROLLER_STICK_LOWER_LIMIT, CONTROLLER_STICK_HIGHER_LIMIT);
	Vec2 state = Vec2::Setup(stateX, stateY);
	state.NormalizeSelf();
	return state;
}

float GMath::CutHighAndLow(float value, float high, float low, float start, float end){
	if (value < low)	{ return start;	}
	if (value > high)	{ return end;	}
	return value;
}

float GMath::CutNearAndFarByZero(float value, float nearByZero, float farByZero, float end){
	if (value == 0) { return 0; }
	float	absValue = abs(value);
	bool	isPlus	 = (value > 0);
	float	cutted	 = CutHighAndLow(absValue, farByZero, nearByZero, 0, end);
	return	cutted * (-1+2*isPlus);
}
