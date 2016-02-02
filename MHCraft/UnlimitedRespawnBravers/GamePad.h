#ifndef _DEVICE_INPUT_GAMEPAD_H_
#define _DEVICE_INPUT_GAMEPAD_H_

#include "GSystemHub.h"
#include "IInput.h"

class GamePad : public IInput
{
public:
	GamePad();
	~GamePad();
	

private:
	unsigned int keyConfig[GKEY_NUM];
};

#endif