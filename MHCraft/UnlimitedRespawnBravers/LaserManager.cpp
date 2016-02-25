#include "LaserManager.h"
#include "Laser.h"

LaserManager::LaserManager(){
//	const int defaultFactorSpace = 64;
//	lasers.resize(sizeof(Laser*)*defaultFactorSpace);
}
LaserManager::~LaserManager(){
	ClearAllLaser();
}

void LaserManager::Initialize(){}
void LaserManager::Update(){
	for (shared_ptr<Laser> ls : lasers){
		ls->Update();
	}
}
void LaserManager::Draw(){
	for (shared_ptr<Laser> ls : lasers){
		ls->Draw();
	}
}
void LaserManager::AddLaser(shared_ptr<Laser> laser){
	lasers.push_back(laser);
}
void LaserManager::DeleteEndLaser(){}
void LaserManager::ClearAllLaser(){}


