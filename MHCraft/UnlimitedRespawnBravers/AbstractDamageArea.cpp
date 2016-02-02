#include "AbstractDamageArea.h"


AbstractDamageArea::AbstractDamageArea(int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy){
	Setup(stayCount, hitData, isToPlayer, isToEnemy);
}

void AbstractDamageArea::Setup(int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy){
	this->maxStayCount	= stayCount;
	this->stayCount		= stayCount;
	this->hitData		= hitData;
	this->isHitPlayer	= isToPlayer;
	this->isHitEnemy	= isToEnemy;
	this->isDead		= (!isToPlayer && !isToEnemy);		//“G–¡•û‚ ‚½‚è”»’è–³‚¢‚È‚ç‘¦Á‹
}

void AbstractDamageArea::Update(){
	DestructorCount();
}

bool AbstractDamageArea::IsHitPlayer(){
	return isHitPlayer;
}

bool AbstractDamageArea::IsHitEnemy(){
	return isHitEnemy;
}

HitData AbstractDamageArea::GetHitData(){
	return hitData;
}

bool AbstractDamageArea::GetIsDead(){
	return isDead;
}

//-----private-----

void AbstractDamageArea::DestructorCount(){
	if (isDead){ return; }
	if (--stayCount > 0){ return; }
	isDead = true;
}



