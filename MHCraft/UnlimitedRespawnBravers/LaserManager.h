#ifndef _CHARACTER_LASER_LASERMANAGER_H_
#define _CHARACTER_LASER_LASERMANAGER_H_

#include "SystemHub.h"
#include "GSystem.h"

using namespace std;

class Laser;
class LaserData;
class DamageAreaManager;

class LaserManager{
public:
	LaserManager(DamageAreaManager* damageAreaManager);
	~LaserManager();

	void Initialize();
	void Update();
	void Draw();
	void AddLaser(LaserData laserData, int shooterNo);

private:
	shared_ptr<Laser> lasers[MAX_LASER_NUM];
	DamageAreaManager* damageAreaManager;
	void	ClearAllLaser();
	int		GetEmptyNum();
};









#endif
