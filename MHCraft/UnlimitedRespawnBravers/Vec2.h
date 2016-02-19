#ifndef _GSYSTEM_VEC2_H_
#define _GSYSTEM_VEC2_H_

#include "SystemHub.h"
class Vec2{
public:
	float X;
	float Y;
	Vec2(float x=0.0f, float y=0.0f);

	static	Vec2	Zero();
	static	Vec2	One();
	static  Vec2	Normalize(Vec2 other);
	static	Vec2	Setup(float X, float Y);
	static	double	Distance(Vec2 position1, Vec2 position2);
	static	float	DistanceF(Vec2 position1, Vec2 position2);
	static	double	Dot(Vec2 fromPos, Vec2 toPos, Vec2 posTarget);
	static	float	DotF(Vec2 fromPos, Vec2 toPos, Vec2 posTarget);
	static	double	Cross(Vec2 fromPos, Vec2 toPos, Vec2 posTarget);
	static	float	CrossF(Vec2 fromPos, Vec2 toPos, Vec2 posTarget);

	double	Distance(Vec2 other);
	float	DistanceF(Vec2 other);
	double	Length();
	float	LengthF();
	Vec2*	NormalizeSelf();
	Vec2*	SetupSelf(float X, float Y);
	int		GetIntX();
	int		GetIntY();


	Vec2*	operator=(Vec2 other);
	Vec2*	operator+=(Vec2 other);
	Vec2*	operator-=(Vec2 other);
	Vec2*	operator*=(Vec2 other);
	Vec2*	operator*=(int other);
	Vec2*	operator*=(float other);
	Vec2*	operator*=(double other);
	Vec2*	operator/=(Vec2 other);
	Vec2*	operator/=(int other);
	Vec2*	operator/=(float other);
	Vec2*	operator/=(double other);
	Vec2	operator+(Vec2 other);
	Vec2	operator-(Vec2 other);
	Vec2	operator*(Vec2 other);
	Vec2	operator*(int other);
	Vec2	operator*(float other);
	Vec2	operator*(double other);
	Vec2	operator/(Vec2 other);
	Vec2	operator/(int other);
	Vec2	operator/(float other);
	Vec2	operator/(double other);
	bool	operator==(Vec2 other);
	bool	operator!=(Vec2 other);

private:

};


#endif