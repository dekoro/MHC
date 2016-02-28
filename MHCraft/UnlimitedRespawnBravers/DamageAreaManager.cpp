#include "DamageAreaManager.h"
#include "DamageAreaCircle.h"
#include "DamageAreaRectangle.h"
#include "DamageAreaQuadrangle.h"
#include "IHittable.h"

DamageAreaManager::DamageAreaManager(){
}

DamageAreaManager::~DamageAreaManager(){
}

void DamageAreaManager::Initialize(){
	damageAreaList.clear();
}

void DamageAreaManager::Update(){
	for(AbstractDamageArea* da : damageAreaList){
		da->Update();
	}
	RefleshDamageArea();
}

void DamageAreaManager::Draw(){
	for each(AbstractDamageArea* da in damageAreaList){
		da->Draw();
	}
}

void DamageAreaManager::Finalize(){
	ClearDamageArea();
}

DamageAreaCircle* DamageAreaManager::AddDamageAreaCircle(GCircle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter){
	DamageAreaCircle* damageAreaCircle = new DamageAreaCircle(hitArea, hitData, stayCount, isToPlayer, isToEnemy, hitter);
	damageAreaList.push_back(damageAreaCircle);
	return damageAreaCircle;
}

DamageAreaRectangle* DamageAreaManager::AddDamageAreaRectangle(GRectangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter){
	DamageAreaRectangle* damageAreaRectangle = new DamageAreaRectangle(hitArea, hitData, stayCount, isToPlayer, isToEnemy, hitter);
	damageAreaList.push_back(damageAreaRectangle);
	return damageAreaRectangle;
}

DamageAreaQuadrangle*	DamageAreaManager::AddDamageAreaQuadrangle(GQuadrangle hitArea, HitData hitData, int stayCount, bool isToPlayer, bool isToEnemy, IHittable* hitter){
	DamageAreaQuadrangle* damageAreaQuadrangle = new DamageAreaQuadrangle(hitArea, hitData, stayCount, isToPlayer, isToEnemy, hitter);
	damageAreaList.push_back(damageAreaQuadrangle);
	return damageAreaQuadrangle;
}


HitData DamageAreaManager::CheckAllHitRectangle(GRectangle target, bool isTargetPlayer, bool isTargetEnemy){
	HitData tmpHit = HitData::NoHit();
	if (damageAreaList.empty()) { return HitData::NoHit(); }
	for each(AbstractDamageArea* dmg in damageAreaList) {
		tmpHit = dmg->CheckIsHitAndDamage(target);
		if (tmpHit != HitData::NoHit()) {
			return  tmpHit;
		}
	}
	return HitData::NoHit();
}

HitData DamageAreaManager::CheckAllHitCircle(GCircle target, bool isTargetPlayer, bool isTargetEnemy){
	HitData tmpHit = HitData::NoHit();
	if (damageAreaList.empty()){ return HitData::NoHit(); }
	for (AbstractDamageArea* dmg: damageAreaList){
		tmpHit = dmg->CheckIsHitAndDamage(target);
		if (tmpHit != HitData::NoHit()){
			dmg->HitProcess();
			return  tmpHit;
		}

	}
	return HitData::NoHit();
}

void DamageAreaManager::RefleshDamageArea(){
	if (damageAreaList.empty()){ return; }
	bool isNoRemove = true;
	do{
		isNoRemove = true;
		int index = 0;
		for each(AbstractDamageArea* dmg in damageAreaList){
			if (!dmg->GetIsDead()){
				index++;
				continue;
			}
			RemoveDamageArea(index);
			isNoRemove = true;
			break;
		}
	} while (!isNoRemove);
}

//-----private-----

void DamageAreaManager::RemoveDamageArea(int index){
	if ((int)damageAreaList.size() < index){ return; }
	SAFE_DELETE(damageAreaList[index]);
	damageAreaList.erase(damageAreaList.begin() + index);
}

void DamageAreaManager::ClearDamageArea(){
	while (!damageAreaList.empty()){
		RemoveDamageArea(0);
	}
}







