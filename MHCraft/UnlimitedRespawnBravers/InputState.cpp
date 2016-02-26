#include "InputState.h"

InputState::InputState(int padNo){
	this->padIndex = padNo;
	Leave();

	GetJoypadXInputState(GetDxPadType(), &preState);
	GetJoypadXInputState(GetDxPadType(), &curState);
}

InputState::~InputState(){

}

void InputState::SetupInputState(int padInput){
	this->padIndex = padIndex;
}

void InputState::Update(){
	preState = curState;
	GetJoypadXInputState(GetDxPadType(), &curState);
	leftStickState = GetLeftStickState();
	rightStickState = GetRightStickState();
}


bool InputState::CheckKeyDown(GKey key){
	return (IsInput(curState, key));
}

bool InputState::CheckKeyPush(GKey key){
	return (!IsInput(preState, key) && IsInput(curState, key));
}

bool InputState::CheckKeyRelease(GKey key){
	return (IsInput(preState, key) && !IsInput(curState, key));
}

bool InputState::CheckKeyFree(GKey key){
	return (!IsInput(curState, key));
}

bool InputState::CheckAnyKeyPush(){
	return (IsInput(curState, -1) && curState.Buttons != preState.Buttons);
}

void InputState::ChangeKeyConfig(GKey key, int inputKey){
	keyConfigList[(int)key] = inputKey;
}

void InputState::ChangeKeyConfig(GKey inputKey[GKEY_NUM]){
	for (int i = 0; i < GKEY_NUM; i++){
		keyConfigList[i] = inputKey[i];
	}
}

int InputState::GetPadIndex(){
	return padIndex;
}

void InputState::Join(){
	isUse = true;
}

bool InputState::GetIsUse(){
	return isUse;
}

void InputState::Leave(){
	ResetKeyConfig();
	isUse = false;
}

bool InputState::CheckJoinSign(){
	if (isUse){ return false; }
	if (IsInput(curState, 15)){ return false; }	//十字キーは対応外
	if (!CheckAnyKeyPush()){ return false; }
	return true;
}

Vec2 InputState::GetLeftStickState() {
	int inputPadNo = InputState::GetDxPadType();
	XINPUT_STATE	inputState;
	int isError = GetJoypadXInputState(inputPadNo, &inputState);
	if (isError == -1) { return Vec2::Zero(); }

	return  GMath::GetStickStateToVec2(inputState.ThumbLX, inputState.ThumbLY);
}

Vec2 InputState::GetRightStickState() {
	int inputPadNo = InputState::GetDxPadType();
	XINPUT_STATE	inputState;
	int isError = GetJoypadXInputState(inputPadNo, &inputState);
	if (isError == -1) { return Vec2::Zero(); }

	return  GMath::GetStickStateToVec2(inputState.ThumbRX, inputState.ThumbRY);
}

Vec2 InputState::GetLeftStickLeanVector(){
	if (leftStickState == Vec2::Zero()) { return Vec2::Zero(); }
	return leftStickState;
}

Vec2 InputState::GetRightStickLeanVector(){
	if (rightStickState == Vec2::Zero()) { return Vec2::Zero(); }
	return rightStickState;
}


//--protected--

void InputState::ResetKeyConfig(){
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

bool InputState::IsInput(XINPUT_STATE preORcurState, GKey key){
	/*
	int keyConfig = keyConfigList[key];
	int isHit = preORcurState & keyConfig;
	return (isHit != 0);
	*/
	return ((preORcurState.Buttons[keyConfigList[key]]) != 0);
}
bool InputState::IsInput(XINPUT_STATE preORcurState, int keyCode){
	return ((preORcurState.Buttons[keyCode]) != 0);
}

int InputState::GetDxPadType(){
	return DX_INPUT_PAD1 + padIndex;
}

bool InputState::CheckLeftTrigger()
{
	return	this->curState.LeftTrigger != 0;
}

bool InputState::CheckRightTrigger()
{
	return	this->curState.RightTrigger != 0;
}


