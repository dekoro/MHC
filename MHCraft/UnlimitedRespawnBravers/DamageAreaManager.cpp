#include "DamageAreaManager.h"
#include "DamageAreaCircle.h"
#include "DamageAreaRectangle.h"

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
}

void DamageAreaManager::Draw(){
	for each(AbstractDamageArea* da in damageAreaList){
		da->Draw();
	}
}

void DamageAreaManager::Finalize(){
	ClearDamageArea();
}

void DamageAreaManager::AddDamageAreaCircle(GCircle hitArea, int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy){
	damageAreaList.push_back(new DamageAreaCircle(hitArea, stayCount, hitData, isToPlayer, isToEnemy));
}

void DamageAreaManager::AddDamageAreaRectangle(GRectangle hitArea, int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy){
	damageAreaList.push_back(new DamageAreaRectangle(hitArea, stayCount, hitData, isToPlayer, isToEnemy));
}


HitData DamageAreaManager::CheckAllHitCircle(GCircle target, bool isTargetPlayer, bool isTargetEnemy){
	HitData tmpHit;
	if (damageAreaList.empty()){ return HitData::NoHit(); }
	for each(AbstractDamageArea* dmg in damageAreaList){
		tmpHit = dmg->IsHitAndDamage(target);
		if(tmpHit != HitData::NoHit()){
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







