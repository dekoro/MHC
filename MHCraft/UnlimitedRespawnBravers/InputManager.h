#ifndef _DEVICE_INPUT_INPUTMANAGER_H_
#define _DEVICE_INPUT_INPUTMANAGER_H_

#include "GSystem.h"
#include "Macro.h"
#include "InputState.h"

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

private:
	InputState*	inputStateList[MAX_PLAYER];
	void		SetupGamePadList();
	void		FinalizeGamePadList();
//	int JoinGamePad();
};



#endif




