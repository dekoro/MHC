#include "AbstractDamageArea.h"
<<<<<<< HEAD
#include "Vec2.h"
#include "GRectangle.h"
#include "GCircle.h"
#include "Debug.h"
#include "GSystem.h"
#include "IHittable.h"


AbstractDamageArea::AbstractDamageArea(int stayCount, HitData hitData, bool isToPlayer, bool isToEnemy, IHittable* hitter){
	this->hitter = hitter;
	Setup(stayCount, hitData, isToPlayer, isToEnemy);
=======

AbstractDamageArea::AbstractDamageArea(int stayCount, bool isToPlayer, bool isToEnemy){
	Setup(stayCount, isToPlayer, isToEnemy);
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40
}


void AbstractDamageArea::Setup(int stayCount, bool isToPlayer, bool isToEnemy){
	this->maxStayCount			= stayCount;
	this->stayCount				= stayCount;
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

<<<<<<< HEAD
HitData AbstractDamageArea::GetHitData(){
	return hitData;
}

void AbstractDamageArea::HitProcess(){
	if (hitter == NULL){ return; }
	hitter->HitFunction();
}

void AbstractDamageArea::Kill(){
	isDead = true;
}

=======
>>>>>>> dd6161f1f6dd4edff83a4142ec6e3a66898c1b40
//-----private-----

void AbstractDamageArea::DestructorCount(){
	if (isDead){ return; }
	if (--stayCount > 0){ return; }
	isDead = true;
}



