#include "AbstractDamageArea.h"

AbstractDamageArea::AbstractDamageArea(int stayCount, bool isToPlayer, bool isToEnemy){
	Setup(stayCount, isToPlayer, isToEnemy);
}


void AbstractDamageArea::Setup(int stayCount, bool isToPlayer, bool isToEnemy){
	this->maxStayCount			= stayCount;
	this->stayCount				= stayCount;
	this->isHittableToPlayer	= isToPlayer;
	this->isHittableToEnemy		= isToEnemy;
	this->isDead				= (!isToPlayer && !isToEnemy);		//敵味方あたり判定無いなら即消去
}

void AbstractDamageArea::Update(){
	DestructorCount();
}

bool AbstractDamageArea::IsHittableToPlayer(){
	return isHittableToPlayer;
}

bool AbstractDamageArea::IsHittableToEnemy(){
	return isHittableToEnemy;
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



