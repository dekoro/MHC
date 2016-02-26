#ifndef _DEVICE_INPUT_INPUTMANAGER_H_
#define _DEVICE_INPUT_INPUTMANAGER_H_

#include "GSystem.h"
#include "Macro.h"
#include "InputState.h"
#include"Keyboard.h"

class InputManager
{
public:
	InputManager();
	~InputManager();

	void		Update();
	InputState*	GetInputState(int padNo);
	bool		CheckKeyDownAllPad(GKey key);
	bool		CheckKeyPushAllPad(GKey key);
	bool		CheckKeyReleaseAllPad(GKey key);
	bool		CheckKeyFreeAllPad(GKey key);
	void		LeaveGamePad(int padNo);
	bool		CheckAnyKeyPush();

private:
	InputState*	inputStateList[USE_PAD_MAX];
	void		SetupGamePadList();
	void		FinalizeGamePadList();
	Keyboard key;
//	int JoinGamePad();
};



#endif




