#ifndef _CHARACTER_IATTACKABLE_H_
#define _CHARACTER_IATTACKABLE_H_

#include "GSystemHub.h"

class IAttackable
{
public:
	IAttackable(){}
	~IAttackable(){}



protected:
	int power;
	ATTACK_TYPE attackType;

private:
	
};



#endif



