#ifndef _GSYSTEM_RECTANGLE_H_
#define _GSYSTEM_RECTANGLE_H_

#include "SystemHub.h"
#include "Vec2.h"

class GRectangle{
public:
	int X;
	int Y;
	int width;
	int height;

	GRectangle(int X=0, int Y=0, int width=0, int height=0);
	static GRectangle Setup(int X, int Y, int width, int height);
	static GRectangle Setup(Vec2 posCenter, int width, int height);

	int GetTop();
	int GetBottom();
	int GetLeft();
	int GetRight();
	Vec2 GetPositionLeftTop();
	Vec2 GetPositionRightTop();
	Vec2 GetPositionLeftBottom();
	Vec2 GetPositionRightBottom();
	Vec2 GetPositionCenter();
};

#endif