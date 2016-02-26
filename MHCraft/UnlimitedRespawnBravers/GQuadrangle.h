#ifndef _GSYSTEM_GRECTANGLETEST_H_
#define _GSYSTEM_GRECTANGLETEST_H_


#include "SystemHub.h"
class Vec2;


class GQuadrangle {
public:
	double x1 = 0;
	double y1 = 0;
	double x2 = 0;
	double y2 = 0;
	double x3 = 0;
	double y3 = 0;
	double x4 = 0;
	double y4 = 0;

	GQuadrangle(double x1 = 0.0, double y1 = 0.0, double x2 = 0.0, double y2 = 0.0, double x3 = 0.0, double y3 = 0.0, double x4 = 0.0, double y4 = 0.0);
	static GQuadrangle Setup(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);

	static GQuadrangle Setup(Vec2 point1, Vec2 point2, Vec2 point3, Vec2 point4);
	static GQuadrangle Setup(double leftTopX, double leftTopY, double width, double height);
	void Rotate(Vec2 basePoint, int degree);
	void Rotate(Vec2 basePoint, double radian);
	void Rotate(double basePointX, double basePointY, int degree);
	void Rotate(double basePointX, double basePointY, double radian);
	void RotateOnCenter(int degree);
	void RotateOnCenter(double radian);
	void Move(double moveX, double moveY);
	void MoveVector(double length, int degree);
	void MoveVector(double length, double radian);
	void MoveVector(Vec2 velocity);
	void GetCenterPosition(double* outCenterX, double* outCenterY);
	Vec2 GetCenterPosition();

	Vec2 GetPoint1();
	Vec2 GetPoint2();
	Vec2 GetPoint3();
	Vec2 GetPoint4();
		 
private:

};


#endif
