#include "Debug.h"

bool Debug::isDebugMode = false;

void Debug::CheckDebugMode(){
#if _DEBUG
	isDebugMode = true;
#endif
}

void Debug::Alert(std::string startMessage){
	FAST_RETURN_VOID(!isDebugMode);
	MessageBox(NULL, TEXT(startMessage.c_str()), TEXT("ERROR"), MB_OK);
}

void Debug::DrawString(int x, int y, char* string, unsigned int color){
	FAST_RETURN_VOID(!isDebugMode);
	DrawString(x, y, string, color);
}

void Debug::DrawSimpleRectangle(GRectangle rectangle, int color, bool fill){
	DrawSimpleRectangle(rectangle.GetLeft(), rectangle.GetTop(), rectangle.GetRight(), rectangle.GetBottom(), color, fill);
}

void Debug::DrawSimpleRectangle(int left, int top, int right, int bottom, int color, bool fill){
	FAST_RETURN_VOID(!isDebugMode);
	DrawBox(left, top, right, bottom, color, fill);
}

void Debug::DrawSimpleCircle(GCircle circle, int color){
	DrawSimpleCircle(circle.posCenter.GetIntX(), circle.posCenter.GetIntY(), (int)circle.radius, color);
}

void Debug::DrawSimpleCircle(int cX, int cY, int radius, int color){
	FAST_RETURN_VOID(!isDebugMode);
	DrawCircle(cX, cY, radius, color);
}

void Debug::DrawSimpleLine(Vec2 position1, Vec2 position2, int color){
	DrawSimpleLine(position1.GetIntX(), position1.GetIntY(), position2.GetIntX(), position2.GetIntY(), color);
}

void Debug::DrawSimpleLine(int X1, int Y1, int X2, int Y2, int color){
	FAST_RETURN_VOID(!isDebugMode);
	DrawLine(X1, Y1, X2, Y2, color);
}

void Debug::DrawSimpleArrow(Vec2 posStart, Vec2 posEnd, int color){
	DrawSimpleArrow(posStart.GetIntX(), posStart.GetIntY(), posEnd.GetIntX(), posEnd.GetIntY(), color);

}

void Debug::DrawSimpleArrow(int fromX, int fromY, int toX, int toY, int color){
	FAST_RETURN_VOID(!isDebugMode);
	DrawSimpleLine(fromX, fromY, toX, toY, color);
	DrawSimpleCircle(toX, toY, 5, color);
}


//---private---



