#include "GRectangle.h"

GRectangle::GRectangle(int X, int Y, int width, int height){}

GRectangle GRectangle::Setup(int x, int y, int width, int height){
	GRectangle tmp;
	tmp.X = x;
	tmp.Y = y;
	tmp.width = width;
	tmp.height = height;
	return tmp;
}

GRectangle GRectangle::Setup(Vec2 posCenter, int width, int height){
	GRectangle tmp;
	tmp.X		= posCenter.GetIntX() - width/2;
	tmp.Y		= posCenter.GetIntY() - height/2;
	tmp.width	= width;
	tmp.height	= height;
	return tmp;
}

int GRectangle::GetTop(){
	return Y;
}

int GRectangle::GetBottom(){
	return Y + height;
}
int GRectangle::GetLeft(){
	return X;
}

int GRectangle::GetRight(){
	return X + width;
}

Vec2 GRectangle::GetPositionLeftTop(){
	return Vec2::Setup(GetLeft(), GetTop());
}

Vec2 GRectangle::GetPositionRightTop(){
	return Vec2::Setup(GetRight(), GetTop());
}

Vec2 GRectangle::GetPositionLeftBottom(){
	return Vec2::Setup(GetLeft(), GetBottom());
}

Vec2 GRectangle::GetPositionRightBottom(){
	return Vec2::Setup(GetRight(), GetBottom());
}

Vec2 GRectangle::GetPositionCenter(){
	return Vec2::Setup((float)(X + width/2), (float)(Y + height/2));
}






