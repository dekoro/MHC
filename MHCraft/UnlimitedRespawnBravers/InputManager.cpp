#include "InputManager.h"

InputManager::InputManager(){
	SetupGamePadList();
}

InputManager::~InputManager(){
	FinalizeGamePadList();
}

void InputManager::Update(){
	for (int i = 0; i < MAX_PLAYER; i++){
		inputStateList[i]->Update();
	}
	key.Update();
}

InputState* InputManager::GetInputState(int padNo){
	return inputStateList[padNo];
}

bool InputManager::CheckKeyDownAllPad(GKey key){
	for (int i = 0; i < MAX_PLAYER; i++){
		if (inputStateList[i]->CheckKeyDown(key)){
			return true;
		}

		if (this->key.IsKeyDown(inputStateList[i]->keyConfigListKeyboard[key])){
			return true;
		}
	}
	return false;
}


//ƒgƒŠƒK[”»’è
bool InputManager::CheckKeyPushAllPad(GKey key){
	for (int i = 0; i < MAX_PLAYER; i++){
		if (inputStateList[i]->CheckKeyPush(key)){
			return true;
		}
		if (this->key.IsDownTrigger(inputStateList[i]->keyConfigListKeyboard[key])){
			return true;
		}
	}
	return false;
}

bool InputManager::CheckKeyReleaseAllPad(GKey key){
	for (int i = 0; i < MAX_PLAYER; i++){
		if (inputStateList[i]->CheckKeyRelease(key)){
			return true;
		}
	}

	return false;
}

bool InputManager::CheckKeyFreeAllPad(GKey key){
	for (int i = 0; i < MAX_PLAYER; i++){
		if (inputStateList[i]->CheckKeyFree(key)){
			return true;
		}
	}
	return false;
}

void InputManager::LeaveGamePad(int padNo){
	inputStateList[padNo]->Leave();
}



//---private---

void InputManager::SetupGamePadList(){
	for (int i = 0; i < MAX_PLAYER; i++){
		inputStateList[i] = new InputState(i);
	}
}

void InputManager::FinalizeGamePadList(){
	for (int i = 0; i < MAX_PLAYER; i++){
		SAFE_DELETE(inputStateList[i]);
	}
}





