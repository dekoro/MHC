#ifndef _DEVICE_INPUT_KEYBOARD_H_
#define _DEVICE_INPUT_KEYBOARD_H_

//#include "SystemHub.h"
#include "GSystem.h"
#include "EnumGKey.h"
#include "IInput.h"
#include "FlagManager.h"

class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	void Update();

	int GetKeyFalme(int key);

	bool IsKeyDown(int key);

	bool IsDownTrigger(int key);

private:
	const int keyNumber = 256;
	int keyFlame[256];
	char tempKey[256];

};

#endif

