#include "Vec2.h"

Vec2 Vec2::Zero(){
	Vec2 tmp(0, 0);
	return tmp;
}

Vec2 Vec2::One(){
	Vec2 tmp(1.f, 1.f);
	return tmp;
}

Vec2 Vec2::Normalize(Vec2 other){
	if (other == Zero()){ return Vec2::Zero(); }
	other /= other.LengthF();
	return other;
}

Vec2 Vec2::Setup(float X, float Y){
	Vec2 tmp(0, 0);
	tmp.X = X;
	tmp.Y = Y;
	return tmp;
}

double Vec2::Distance(Vec2 position1, Vec2 position2){
	return position1.Distance(position2);
}

float Vec2::DistanceF(Vec2 position1, Vec2 position2){
	return position1.DistanceF(position2);
}

double Vec2::Dot(Vec2 fromPos, Vec2 toPos, Vec2 posTarget){
	Vec2 unitVec = Vec2::Normalize(toPos - fromPos);
	Vec2 targetVec = posTarget - fromPos;
	return (targetVec.X * unitVec.X + targetVec.Y * unitVec.Y);
}


float Vec2::DotF(Vec2 fromPos, Vec2 toPos, Vec2 posTarget){
	return (float)Dot(fromPos, toPos, posTarget);
}

double Vec2::Cross(Vec2 fromPos, Vec2 toPos, Vec2 posTarget){
	Vec2 unitVec = Vec2::Normalize(toPos - fromPos);;
	Vec2 targetVec = posTarget - fromPos;
	return (unitVec.X * targetVec.Y - targetVec.X * unitVec.Y);
}

float Vec2::CrossF(Vec2 fromPos, Vec2 toPos, Vec2 posTarget){
	return (float)Cross(fromPos, toPos, posTarget);
}

double Vec2::Distance(Vec2 other){
	return sqrt(pow((double)(X - other.X), 2) + pow((double)(Y - other.Y), 2));
}


float Vec2::DistanceF(Vec2 other){
	return (float)Distance(other);
}
double Vec2::Length(){
	return Distance(Zero());
}

float Vec2::LengthF(){
	return DistanceF(Zero());
}

Vec2* Vec2::NormalizeSelf(){
	if (*this == Zero()){ return this; }
	*this /= LengthF();
	return this;
}

Vec2* Vec2::SetupSelf(float X, float Y){
	this->X = X;
	this->Y = Y;
	return this;
}

int	Vec2::GetIntX(){
	return (int)X;
}

int	Vec2::GetIntY(){
	return (int)Y;
}

Vec2::Vec2(float x, float y): X(x), Y(y){}

Vec2 * Vec2::operator=(Vec2 other){
	X = other.X;
	Y = other.Y;
	return this;
}

Vec2* Vec2::operator+=(Vec2 other){
	X += other.X;
	Y += other.Y;
	return this;
}

Vec2* Vec2::operator-=(Vec2 other){
	X -= other.X;
	Y -= other.Y;
	return this;
}


Vec2* Vec2::operator*=(Vec2 other){
	X *= other.X;
	Y *= other.Y;
	return this;
}
Vec2* Vec2::operator*=(int other){
	X *= other;
	Y *= other;
	return this;
}
Vec2* Vec2::operator*=(float other){
	X *= other;
	Y *= other;
	return this;
}
Vec2* Vec2::operator*=(double other){
	X *= other;
	Y *= other;
	return this;
}


Vec2* Vec2::operator/=(Vec2 other){
	X = (other.X == 0) ? 0 : X/other.X;
	Y = (other.Y == 0) ? 0 : Y/other.Y;
	return this;
}
Vec2* Vec2::operator/=(int other){
	X = (other == 0) ? 0 : X/other;
	Y = (other == 0) ? 0 : Y/other;
	return this;
}
Vec2* Vec2::operator/=(float other){
	X = (other == 0) ? 0 : X/other;
	Y = (other == 0) ? 0 : Y/other;
	return this;
}
Vec2* Vec2::operator/=(double other){
	X = (other == 0) ? 0 : X/other;
	Y = (other == 0) ? 0 : Y/other;
	return this;
}


Vec2 Vec2::operator+(Vec2 other){
	Vec2 tmp(1.f,1.f);
	tmp.X = X + other.X;
	tmp.Y = Y + other.Y;
	return tmp;
}


Vec2 Vec2::operator-(Vec2 other){
	Vec2 tmp(0, 0);
	tmp.X = X - other.X;
	tmp.Y = Y - other.Y;
	return tmp;
}


Vec2 Vec2::operator*(Vec2 other){
	Vec2 tmp(0, 0);
	tmp.X = X * other.X;
	tmp.Y = Y * other.Y;
	return tmp;
}
Vec2 Vec2::operator*(int other){
	Vec2 tmp(0, 0);
	tmp.X = X * other;
	tmp.Y = Y * other;
	return tmp;
}
Vec2 Vec2::operator*(float other){
	Vec2 tmp(0, 0);
	tmp.X = X * other;
	tmp.Y = Y * other;
	return tmp;
}
Vec2 Vec2::operator*(double other){
	Vec2 tmp(0, 0);
	tmp.X = X * other;
	tmp.Y = Y * other;
	return tmp;
}


Vec2 Vec2::operator/(Vec2 other){
	Vec2 tmp(0, 0);
	tmp.X = X / other.X;
	tmp.Y = Y / other.Y;
	return tmp;
}

Vec2 Vec2::operator/(int other){
	Vec2 tmp(0, 0);
	tmp.X = X / other;
	tmp.Y = Y / other;
	return tmp;
}

Vec2 Vec2::operator/(float other){
	Vec2 tmp(0, 0);
	tmp.X = X / other;
	tmp.Y = Y / other;
	return tmp;
}

Vec2 Vec2::operator/(double other){
	Vec2 tmp(0, 0);
	tmp.X = X / other;
	tmp.Y = Y / other;
	return tmp;
}


bool Vec2::operator==(Vec2 other){
	return (X == other.X
		&& Y == other.Y);
}


bool Vec2::operator!=(Vec2 other){
	return (X != other.X
		|| Y != other.Y);
}






