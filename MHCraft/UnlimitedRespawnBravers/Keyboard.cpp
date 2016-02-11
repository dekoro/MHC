#include "Keyboard.h"

Keyboard::Keyboard(){

}

Keyboard::~Keyboard(){

}

void Keyboard::Update(){

	GetHitKeyStateAll(this->tempKey);

	for (int i = 0; i < keyNumber; i++)
	{
		if (tempKey[i] != 0)
		{
			this->keyFlame[i]++;
		}
		else
		{
			this->keyFlame[i] = 0;
		}
	}
}


int Keyboard::GetKeyFalme(int Key)
{
	return this->keyFlame[Key];
}

bool Keyboard::IsDownTrigger(int Key)
{
	return this->keyFlame[Key] == 1;
}

bool Keyboard::IsKeyDown(int key)
{
	return this->keyFlame[key] != 0;
}