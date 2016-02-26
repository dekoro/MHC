#include "GQuadrangle.h"
#include "GMath.h"
#include "Vec2.h"
#include "Debug.h"


GQuadrangle::GQuadrangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
}

GQuadrangle GQuadrangle::Setup(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	GQuadrangle tmp;
	tmp.x1 = x1;
	tmp.y1 = y1;
	tmp.x2 = x2;
	tmp.y2 = y2;
	tmp.x3 = x3;
	tmp.y3 = y3;
	tmp.x4 = x4;
	tmp.y4 = y4;
	return tmp;
}

GQuadrangle GQuadrangle::Setup(Vec2 point1, Vec2 point2, Vec2 point3, Vec2 point4) {
	return Setup(	point1.X, point1.Y,
					point2.X, point2.Y,
					point3.X, point3.Y,
					point4.X, point4.Y);
}

GQuadrangle GQuadrangle::Setup(double leftTopX, double leftTopY, double width, double height) {
	return Setup(leftTopX, leftTopY,
		leftTopX + width, leftTopY,
		leftTopX + width, leftTopY + height,
		leftTopX, leftTopY + height);
}


void GQuadrangle::Rotate(Vec2 basePoint, int degree) {
	Rotate((double)basePoint.X, (double)basePoint.Y, degree);
}

void GQuadrangle::Rotate(Vec2 basePoint, double radian) {
	Rotate((double)basePoint.X, (double)basePoint.Y, radian);
}

void GQuadrangle::Rotate(double basePointX, double basePointY, int degree) {
	Rotate(basePointX, basePointY, GMath::ChangeDegToRad(degree));
}

void GQuadrangle::Rotate(double basePointX, double basePointY, double radian) {
	double zeroBaseX1 = x1 - basePointX;
	double zeroBaseY1 = y1 - basePointY;
	double zeroBaseX2 = x2 - basePointX;
	double zeroBaseY2 = y2 - basePointY;
	double zeroBaseX3 = x3 - basePointX;
	double zeroBaseY3 = y3 - basePointY;
	double zeroBaseX4 = x4 - basePointX;
	double zeroBaseY4 = y4 - basePointY;

	double zeroBaseRotatedX1 = zeroBaseX1 * cos(radian) - zeroBaseY1 * sin(radian);
	double zeroBaseRotatedY1 = zeroBaseX1 * sin(radian) + zeroBaseY1 * cos(radian);
	double zeroBaseRotatedX2 = zeroBaseX2 * cos(radian) - zeroBaseY2 * sin(radian);
	double zeroBaseRotatedY2 = zeroBaseX2 * sin(radian) + zeroBaseY2 * cos(radian);
	double zeroBaseRotatedX3 = zeroBaseX3 * cos(radian) - zeroBaseY3 * sin(radian);
	double zeroBaseRotatedY3 = zeroBaseX3 * sin(radian) + zeroBaseY3 * cos(radian);
	double zeroBaseRotatedX4 = zeroBaseX4 * cos(radian) - zeroBaseY4 * sin(radian);
	double zeroBaseRotatedY4 = zeroBaseX4 * sin(radian) + zeroBaseY4 * cos(radian);

	x1 = zeroBaseRotatedX1 + basePointX;
	y1 = zeroBaseRotatedY1 + basePointY;
	x2 = zeroBaseRotatedX2 + basePointX;
	y2 = zeroBaseRotatedY2 + basePointY;
	x3 = zeroBaseRotatedX3 + basePointX;
	y3 = zeroBaseRotatedY3 + basePointY;
	x4 = zeroBaseRotatedX4 + basePointX;
	y4 = zeroBaseRotatedY4 + basePointY;
}

void GQuadrangle::RotateOnCenter(int degree){
	RotateOnCenter(GMath::ChangeDegToRad((double)degree));
}

void GQuadrangle::RotateOnCenter(double radian){
	double centerX = 0;
	double centerY = 0;
	GetCenterPosition(&centerX, &centerY);
	Rotate(centerX, centerY, radian);
}

void GQuadrangle::Move(double moveX, double moveY){
	x1 += moveX;
	y1 += moveY;
	x2 += moveX;
	y2 += moveY;
	x3 += moveX;
	y3 += moveY;
	x4 += moveX;
	y4 += moveY;
}

void GQuadrangle::MoveVector(double length, int degree){
	MoveVector(length, GMath::ChangeDegToRad((double)degree));
}

void GQuadrangle::MoveVector(double length, double radian){
	double moveX = length * cos(radian);
	double moveY = length * sin(radian);

	Move(moveX, moveY);
}

void GQuadrangle::MoveVector(Vec2 velocity){
	Move(velocity.X, velocity.Y);
}

void GQuadrangle::GetCenterPosition(double* outCenterX, double* outCenterY){
	double closs = (x3 - x1) * (y4 - y2) - (y3 - y1) * (x4 - x2);
	if (closs == 0) { return; }
	double dR = ((y4 - y2) * (x2 - x1) - (x4 - x2) * (y2 - y1)) / closs;

	*outCenterX = x1 + (x3 - x1)*dR;
	*outCenterY = y1 + (y3 - y1)*dR;
}

Vec2 GQuadrangle::GetCenterPosition(){
	double closs = (x3 - x1) * (y4 - y2) - (y3 - y1) * (x4 - x2);
	if (closs == 0) { return Vec2::Zero(); }
	double dR = ((y4 - y2) * (x2 - x1) - (x4 - x2) * (y2 - y1)) / closs;

	return Vec2::Setup(x1 + (x3 - x1)*dR, y1 + (y3 - y1)*dR);
}

Vec2 GQuadrangle::GetPoint1(){
	return Vec2::Setup((float)x1, (float)y1);
}

Vec2 GQuadrangle::GetPoint2(){
	return Vec2::Setup((float)x2, (float)y2);
}

Vec2 GQuadrangle::GetPoint3(){
	return Vec2::Setup((float)x3, (float)y3);
}

Vec2 GQuadrangle::GetPoint4(){
	return Vec2::Setup((float)x4, (float)y4);
}



