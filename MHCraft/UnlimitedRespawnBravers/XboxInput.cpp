#include "XboxInput.h"

XboxInput::XboxInput(int padNo){
	this->padIndex = padNo;
	Leave();

	GetJoypadXInputState(GetDxPadType(), &preState);
	GetJoypadXInputState(GetDxPadType(), &curState);
}

XboxInput::~XboxInput(){

}

void XboxInput::SetupInputState(int padInput){
	this->padIndex = padIndex;
}

void XboxInput::Update(){
	preState = curState;
	GetJoypadXInputState(GetDxPadType(), &curState);
}


bool XboxInput::CheckKeyDown(GKey key){
	return (IsInput(curState, key));
}

bool XboxInput::CheckKeyPush(GKey key){
	return (!IsInput(preState, key) && IsInput(curState, key));
}

bool XboxInput::CheckKeyRelease(GKey key){
	return (IsInput(preState, key) && !IsInput(curState, key));
}

bool XboxInput::CheckKeyFree(GKey key){
	return (!IsInput(curState, key));
}

bool XboxInput::CheckAnyKeyPush(){
	return (IsInput(curState, -1) && curState.Buttons != preState.Buttons);
}

void XboxInput::ChangeKeyConfig(GKey key, int inputKey){
	keyConfigList[(int)key] = inputKey;
}

void XboxInput::ChangeKeyConfig(GKey inputKey[GKEY_NUM]){
	for (int i = 0; i < GKEY_NUM; i++){
		keyConfigList[i] = inputKey[i];
	}
}

int XboxInput::GetPadIndex(){
	return padIndex;
}

void XboxInput::Join(){
	isUse = true;
}

bool XboxInput::GetIsUse(){
	return isUse;
}

void XboxInput::Leave(){
	ResetKeyConfig();
	isUse = false;
}

bool XboxInput::CheckJoinSign(){
	if (isUse){ return false; }
	if (IsInput(curState, 15)){ return false; }	//十字キーは対応外
	if (!CheckAnyKeyPush()){ return false; }
	return true;
}

//--protected--

void XboxInput::ResetKeyConfig(){
	keyConfigList[GKey_Up] = XINPUT_BUTTON_DPAD_UP;
	keyConfigList[GKey_Down] = XINPUT_BUTTON_DPAD_DOWN;
	keyConfigList[GKey_Left] = XINPUT_BUTTON_DPAD_LEFT;
	keyConfigList[GKey_Right] = XINPUT_BUTTON_DPAD_RIGHT;
	keyConfigList[GKey_Attack] = XINPUT_BUTTON_A;
	keyConfigList[GKey_Skill] = XINPUT_BUTTON_B;
	keyConfigList[GKey_Appeal] = PAD_INPUT_3; 

	keyConfigListKeyboard[GKey_Up] = KEY_INPUT_UP;
	keyConfigListKeyboard[GKey_Down] = KEY_INPUT_DOWN;
	keyConfigListKeyboard[GKey_Left] = KEY_INPUT_LEFT;
	keyConfigListKeyboard[GKey_Right] = KEY_INPUT_RIGHT;
	keyConfigListKeyboard[GKey_Attack] = KEY_INPUT_Z;
	keyConfigListKeyboard[GKey_Skill] = KEY_INPUT_X;
	keyConfigListKeyboard[GKey_Appeal] = KEY_INPUT_C;

}

bool XboxInput::IsInput(XINPUT_STATE preORcurState, GKey key){
	/*
	int keyConfig = keyConfigList[key];
	int isHit = preORcurState & keyConfig;
	return (isHit != 0);
	*/
	return ((preORcurState.Buttons[keyConfigList[key]]) != 0);
}
bool XboxInput::IsInput(XINPUT_STATE preORcurState, int keyCode){
	return ((preORcurState.Buttons[keyCode]) != 0);
}

int XboxInput::GetDxPadType(){
	return DX_INPUT_PAD1 + padIndex;
}

bool XboxInput::CheckLeftTrigger()
{
	return	this->curState.LeftTrigger != 0;
}

bool XboxInput::CheckRightTrigger()
{
	return	this->curState.RightTrigger != 0;
}


