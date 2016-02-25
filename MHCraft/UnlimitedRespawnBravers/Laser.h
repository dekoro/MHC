#ifndef _CHARACTER_LASER_H_
#define _CHARACTER_LASER_H_

#include "SystemHub.h"
#include "ICharacter.h"
#include "DamageAreaQuadrangle.h"
#include "DamageAreaCircle.h"

class Vec2;
class DamageAreaManager;

class Laser: public ICharacter
{
public:
	Laser(DamageAreaManager* damageAreaManager, double width, double height, Vec2 shotPosition, double angleDeg, double lengthFromShotPosition, int knockBackPower, int damage, double speed);
	Laser(DamageAreaManager* damageAreaManager, double width, double height, Vec2 shotPosition, Vec2 velocity, double lengthFromShotPosition, int knockBackPower, int damage, double speed);
	~Laser();

	void Initialize();
	void Update();
	void Draw();
	bool GetIsDead();

private:
	double	speed;
	Vec2	moveVeclocity;
	bool	isDead();
	DamageAreaQuadrangle* damageArea;

	void	Setup(DamageAreaManager* damageAreaManager, GQuadrangle damageArea, HitData hitData, Vec2 velocity, float speed);
	void	Move();
};

#endif


