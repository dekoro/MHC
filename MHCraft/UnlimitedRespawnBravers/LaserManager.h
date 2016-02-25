#ifndef _CHARACTER_LASER_LASERMANAGER_H_
#define _CHARACTER_LASER_LASERMANAGER_H_

#include "SystemHub.h"
using namespace std;

class Laser;


class LaserManager{
public:
	LaserManager();
	~LaserManager();

	void Initialize();
	void Update();
	void Draw();
	void AddLaser(shared_ptr<Laser> laser);

private:
	vector<shared_ptr<Laser>> lasers;
	void DeleteEndLaser();
	void ClearAllLaser();

};









#endif
