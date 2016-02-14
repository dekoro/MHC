#include "Managers.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"
#include "DamageAreaManager.h"


Managers* Managers::instance = NULL;

Managers::~Managers(){
	SAFE_DELETE(players);
	SAFE_DELETE(enemys);
	SAFE_DELETE(items);
	SAFE_DELETE(damages);
}

Managers* Managers::GetInstance(){
	if (instance == NULL){ instance = new Managers(); }
	return instance;
}

PlayerManager*	Managers::Player(){
	return players;
}

EnemyManager*	Managers::Enemy(){
	return enemys;
}

ItemManager*	Managers::Item(){
	return items;
}

DamageAreaManager* Managers::Damage(){
	return damages;
}


//---private---
Managers::Managers(){
	players		= new PlayerManager();
	enemys		= new EnemyManager();
	items		= new ItemManager();
	damages		= new DamageAreaManager();
}






