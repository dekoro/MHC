#ifndef _DEVICE_INPUT_INPUT_H_
#define _DEVICE_INPUT_INPUT_H_

#include "GSystem.h"
#include "EnumGKey.h"
#include "Debug.h"

class InputState
{
public:
	InputState(int dxPadType);
	~InputState();

	void		SetupInputState(int padIndex);
	void		Update();
	bool		CheckKeyDown(GKey key);
	bool		CheckKeyPush(GKey key);
	bool		CheckKeyRelease(GKey key);
	bool		CheckKeyFree(GKey key);
	bool		CheckAnyKeyPush();
	void		ChangeKeyConfig(GKey key, int inputKey);
	void		ChangeKeyConfig(GKey inputKey[GKEY_NUM]);
	Vec2		GetMoveVector();
	Vec2		GetAttackVector();
	int			GetPadIndex();
	bool		GetIsUse();
	void		Join();
	void		Leave();
	bool		CheckJoinSign();
	static int	GetDxPadType(int padIndex);
	int			keyConfigListKeyboard[GKEY_NUM];
	Vec2		GetLeftStickState(int padNo);
	Vec2		GetRightStickState(int padNo);
	Vec2		GetMoveKeyState();
	Vec2		GetMouseState();

protected:
	void ResetKeyConfig();
	bool IsInput(int preORcurState, GKey key);
	bool IsInput(int preORcurState, int keyCode);

private:
	int				padIndex;
	bool			isUse;
	int				keyConfigList[GKEY_NUM];
	int				curState;
	int				preState;
	XINPUT_STATE	preXInputState;
	Vec2			moveStickState;
	Vec2			attackStickState;
};
#endif


