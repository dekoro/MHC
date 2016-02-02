#ifndef _DEVICE_INPUT_INPUT_H_
#define _DEVICE_INPUT_INPUT_H_

#include "GSystem.h"
#include "SystemHub.h"
#include "EnumGKey.h"

class InputState
{
public:
	InputState(int dxPadType);
	~InputState();

	void SetupInputState(int padIndex);
	void Update();
	bool CheckKeyDown(GKey key);
	bool CheckKeyPush(GKey key);
	bool CheckKeyRelease(GKey key);
	bool CheckKeyFree(GKey key);
	bool CheckAnyKeyPush();
	void ChangeKeyConfig(GKey key, int inputKey);
	void ChangeKeyConfig(GKey inputKey[GKEY_NUM]);
	int  GetPadIndex();
	bool GetIsUse();
	void Join();
	void Leave();
	bool CheckJoinSign();

protected:
	void ResetKeyConfig();
	bool IsInput(int preORcurState, GKey key);
	bool IsInput(int preORcurState, int keyCode);

private:
	int padIndex;
	bool isUse;
	int keyConfigList[GKEY_NUM];
	int keyConfigListKeyboard[GKEY_NUM];
	int curState;
	int preState;
	int GetDxPadType();


};
#endif


