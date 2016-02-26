#include "AbstractDamageArea.h"
#include "Vec2.h"
#include "GRectangle.h"
#include "GCircle.h"
#include "Debug.h"
#include "GSystem.h"


AbstractDamageArea::AbstractDamageArea(int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy){
	Setup(stayCount, hitData, isToPlayer, isToEnemy);
}


void AbstractDamageArea::Setup(int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy){
	this->maxStayCount			= stayCount;
	this->stayCount				= stayCount;
	this->hitData				= hitData;
	this->isHittableToPlayer	= isToPlayer;
	this->isHittableToEnemy		= isToEnemy;
	this->isDead				= (!isToPlayer && !isToEnemy);		//“G–¡•û‚ ‚½‚è”»’è–³‚¢‚È‚ç‘¦Á‹
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

HitData AbstractDamageArea::GetHitData(){
	return hitData;
}

void AbstractDamageArea::Kill(){
	isDead = true;
}

//-----private-----

void AbstractDamageArea::DestructorCount(){
	if (isDead){ return; }
	if (--stayCount > 0){ return; }
	isDead = true;
}



