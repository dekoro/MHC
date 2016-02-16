#ifndef _GSYSTEM_DEBUG_H_
#define _GSYSTEM_DEBUG_H_

#include "SystemHub.h"
#include "Macro.h"

class Debug
{
public:
	Debug(){}
	~Debug(){}
	static void CheckDebugMode();
	static void Alert(std::string startMessage);

	static void DrawString(int x, int y, char* string, unsigned int color);
	//static void PrintStringLine(std::string str);
	//static void ClearPrint();

	//void DrawImage(int x, int y, int z, int imageData);
	//void DrawImage(int x, int y, int z, int imageData, int imageIndex);
	//void DrawImageCenterCriteria(int cx, int cy, int z, int imageData);
	//void DrawImageCenterCriteria(int cx, int cy, int z, int imageData, int imageIndex);

	//void DrawImageOnGame(int x, int y, int z, int imageData);
	//void DrawImageOnGame(int x, int y, int z, int imageData, int imageIndex);
	//void DrawImageCenterCriteriaOnGame(int cx, int cy, int z, int imageData);
	//void DrawImageCenterCriteriaOnGame(int cx, int cy, int z, int imageData, int imageIndex);

	//void DrawImageBackGround(int imageData);

	static void DrawSimpleRectangle(GRectangle rectangle, int color = 0, bool fill = true);
	static void DrawSimpleRectangle(int left, int top, int right, int bottom, int color = 0, bool fill = true);
	static void DrawSimpleCircle(GCircle circle, int color = 0);
	static void DrawSimpleCircle(int cX, int cY, int radius, int color = 0);
	static void DrawSimpleLine(Vec2 position1, Vec2 position2, int color = 0);
	static void DrawSimpleLine(int X1, int Y1, int X2, int Y2, int color = 0);
	static void DrawSimpleArrow(Vec2 posStart, Vec2 posEnd, int color = 0);
	static void DrawSimpleArrow(int fromX, int fromY, int toX, int toY, int color = 0);

private:
	static bool isDebugMode;
};

#endif
