#include "InputState.h"

InputState::InputState(int padNo){
	this->padIndex	= padNo;
	Leave();
	preState = 0;
	curState = 0;
}

InputState::~InputState(){

}

void InputState::SetupInputState(int padInput){
	this->padIndex = padIndex;
}

void InputState::Update(){
	preState = curState;
	curState = GetJoypadInputState(GetDxPadType(padIndex));
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
	return (IsInput(curState, -1) && curState != preState);
}

void InputState::ChangeKeyConfig(GKey key, int inputKey){
	keyConfigList[(int)key] = inputKey;
}

void InputState::ChangeKeyConfig(GKey inputKey[GKEY_NUM]){
	for (int i = 0; i < GKEY_NUM; i++){
		keyConfigList[i] = inputKey[i];
	}
}

Vec2 InputState::GetMoveVector(){
	if (moveStickState == Vec2::Zero()) { return Vec2::Zero();  }
	return moveStickState;
}

Vec2 InputState::GetAttackVector(){
	if (attackStickState == Vec2::Zero()) { return Vec2::Zero(); }
	return attackStickState;
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

//--protected--

void InputState::ResetKeyConfig(){
	keyConfigList[GKey_Up]		= PAD_INPUT_UP;
	keyConfigList[GKey_Down]	= PAD_INPUT_DOWN;
	keyConfigList[GKey_Left]	= PAD_INPUT_LEFT;
	keyConfigList[GKey_Right]	= PAD_INPUT_RIGHT;
	keyConfigList[GKey_Attack]	= PAD_INPUT_1;
	keyConfigList[GKey_Skill]	= PAD_INPUT_2;
	keyConfigList[GKey_Appeal]	= PAD_INPUT_3;

	keyConfigListKeyboard[GKey_Up]		= KEY_INPUT_UP;
	keyConfigListKeyboard[GKey_Down]	= KEY_INPUT_DOWN;
	keyConfigListKeyboard[GKey_Left]	= KEY_INPUT_LEFT;
	keyConfigListKeyboard[GKey_Right]	= KEY_INPUT_RIGHT;
	keyConfigListKeyboard[GKey_Attack]	= KEY_INPUT_Z;
	keyConfigListKeyboard[GKey_Skill]	= KEY_INPUT_X;
	keyConfigListKeyboard[GKey_Appeal]	= KEY_INPUT_C;

}

bool InputState::IsInput(int preORcurState, GKey key){
	/*
	int keyConfig = keyConfigList[key];
	int isHit = preORcurState & keyConfig;
	return (isHit != 0);
	*/
	return ((preORcurState & keyConfigList[key]) != 0);
}
bool InputState::IsInput(int preORcurState, int keyCode){
	return ((preORcurState & keyCode) != 0);
}

int InputState::GetDxPadType(int padIndex){
	return DX_INPUT_PAD1 + padIndex;
}

Vec2 InputState::GetLeftStickState(int padNo) {
	int inputPadNo = InputState::GetDxPadType(padNo);
	XINPUT_STATE	inputState;
	int isError = GetJoypadXInputState(inputPadNo, &inputState);
	if (isError == -1) { return Vec2::Zero(); }

	return  GMath::GetStickStateToVec2(inputState.ThumbLX, inputState.ThumbLY);
}

Vec2 InputState::GetRightStickState(int padNo) {
	int inputPadNo = InputState::GetDxPadType(padNo);
	XINPUT_STATE	inputState;
	int isError = GetJoypadXInputState(inputPadNo, &inputState);
	if (isError == -1) { return Vec2::Zero(); }

	return  GMath::GetStickStateToVec2(inputState.ThumbRX, inputState.ThumbRY);
}

Vec2 InputState::GetMoveKeyState()
{
	Debug::Alert(STR("実装されていない\"InputState::GetMoveKeyState()\"を使用しようとしました。", ""));
	return Vec2::Zero();
}

Vec2 InputState::GetMouseState()
{
	Debug::Alert(STR("実装されていない\"InputState::GetMouseState()\"を使用しようとしました。", ""));
	return Vec2::Zero();
}





