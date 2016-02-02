#ifndef _DEVICE_INPUT_KEYBOARD_H_
#define _DEVICE_INPUT_KEYBOARD_H_

//#include "SystemHub.h"
#include "GSystem.h"
#include "EnumGKey.h"
#include "IInput.h"
#include "FlagManager.h"

class Keyboard : public IInput
{
public:
	Keyboard(int PlayerNo);
	~Keyboard();

private:
	unsigned int keyConfig[GKEY_NUM];
	unsigned int GetInputState();
};

#endif

