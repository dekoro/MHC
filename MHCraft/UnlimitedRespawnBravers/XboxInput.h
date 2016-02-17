#ifndef XBOX_INPUT
#define XBOX_INPUT

#include "GSystem.h"
#include "SystemHub.h"
#include "EnumGKey.h"

class XboxInput
{
public:
	XboxInput(int dxPadType);
	~XboxInput();

	void SetupInputState(int padIndex);
	void Update();
	bool CheckKeyDown(GKey key);
	bool CheckKeyPush(GKey key);
	bool CheckKeyRelease(GKey key);
	bool CheckKeyFree(GKey key);
	bool CheckAnyKeyPush();
	bool CheckLeftTrigger();
	bool CheckRightTrigger();
	void ChangeKeyConfig(GKey key, int inputKey);
	void ChangeKeyConfig(GKey inputKey[GKEY_NUM]);
	int  GetPadIndex();
	bool GetIsUse();
	void Join();
	void Leave();
	bool CheckJoinSign();


	int keyConfigListKeyboard[GKEY_NUM];
protected:
	void ResetKeyConfig();
	bool IsInput(XINPUT_STATE preORcurState, GKey key);
	bool IsInput(XINPUT_STATE preORcurState, int keyCode);

private:
	int padIndex;
	bool isUse;
	int keyConfigList[GKEY_NUM];
	XINPUT_STATE curState;
	XINPUT_STATE preState;
	int GetDxPadType();


};
#endif


