#ifndef _CHARACTER_LASER_H_
#define _CHARACTER_LASER_H_

#include "SystemHub.h"
#include "ICharacter.h"
#include "DamageAreaQuadrangle.h"
#include "DamageAreaCircle.h"
#include "IHittable.h"

class Vec2;
class DamageAreaManager;
class LaserData;

class Laser: public ICharacter, IHittable
{
public:
	Laser(DamageAreaManager* damageAreaManager);
	~Laser();

	void Initialize();
	void Set(double width, double height, Vec2 shotPosition, double angleDeg, double lengthFromShotPosition, int knockBackPower, int damage, double speed, int liveCount, int shooterNo=-1);
	void Set(double width, double height, Vec2 shotPosition, Vec2 velocity, double lengthFromShotPosition, int knockBackPower, int damage, double speed, int liveCount, int shooterNo = -1);
	void Set(LaserData laserData, int shooterNo = -1);
	void Update();
	void Draw();
	bool GetIsUse();
	void Kill();
	void HitFunction();

private:
	int		liveCounter;
	double	speed;
	bool	isUse;
	Vec2	moveVeclocity;
	double	angleRad;
	DamageAreaManager*		damageAreaManager;
	DamageAreaQuadrangle*	damageArea;

	void	Setup(GQuadrangle damageArea, HitData hitData, Vec2 velocity, float speed, int liveCount);
	void	Move();
	void	CheckDead();
	void	Hit();
};

class LaserData
{
public:
	LaserData(){}
	~LaserData(){}
	static LaserData Setup(double width, double height, Vec2 shotPosition, Vec2 velocity, double lengthFromShotPosition, int knockBackPower, int damage, double speed, int liveCount);

	double	width;
	double	height;
	Vec2	shotPosition;
	Vec2	velocity;
	double	lengthFromShotPosition;
	int		knockBackPower;
	int		damage;
	double	speed;
	int		liveCount;

private:
};
#endif


