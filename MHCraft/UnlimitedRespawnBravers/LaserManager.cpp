#include "LaserManager.h"
#include "Laser.h"
#include "DamageAreaManager.h"

LaserManager::LaserManager(DamageAreaManager* damageAreaManager){
	this->damageAreaManager = damageAreaManager;
}
LaserManager::~LaserManager(){
	ClearAllLaser();
}

void LaserManager::Initialize(){
	for (int i=0; i<MAX_LASER_NUM; ++i){
		lasers[i] = make_shared<Laser>(damageAreaManager);
	}

}
void LaserManager::Update(){
	for (shared_ptr<Laser> ls : lasers){
		if (!ls->GetIsUse()){ continue; }
		ls->Update();
	}
}
void LaserManager::Draw(){
	for (shared_ptr<Laser> ls : lasers){
		if (!ls->GetIsUse()){ continue; }
		ls->Draw();
	}
}
void LaserManager::AddLaser(LaserData laserData){
	int emptyNo = GetEmptyNum();
	if (emptyNo == -1){ return; }
	lasers[emptyNo]->Set(laserData);
}

void LaserManager::ClearAllLaser(){
	for (shared_ptr<Laser> ls : lasers){
		if (!ls->GetIsUse()){ continue; }
		ls->Kill();
	}
}
int LaserManager::GetEmptyNum(){
	for (int i = 0; i < MAX_LASER_NUM; ++i){
		if (!lasers[i]->GetIsUse()){ return i; }
	}
	return -1;
}


