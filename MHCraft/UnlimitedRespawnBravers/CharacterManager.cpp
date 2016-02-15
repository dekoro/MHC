#include "CharacterManager.h"

CharacterManager::CharacterManager(){
	const int defaultFactorSpace = 64;
	characters.resize(sizeof(ICharacter*)*defaultFactorSpace);
}

CharacterManager::~CharacterManager(){
	RemoveAllCharacter();
}

void CharacterManager::Initialize(){
	for(ICharacter* ch: characters){
		ch->Initialize();
	}
}

void CharacterManager::Update(){
	for (ICharacter* ch : characters) {
		ch->Update();
	}
}

void CharacterManager::Draw(){
	for (ICharacter* ch : characters) {
		ch->Draw();
	}
}

void CharacterManager::AddCharacter(ICharacter* character){
	characters.push_back(character);
}

//---private---
void CharacterManager::RemoveDeadCharacter(){
	int end = characters.end() - characters.begin();
	for (int i=0; i < end; i++){
		CheckAndRemoveDeadCharacter(i);
	}
//	FunctionAll(&CheckAndRemoveDeadCharacter);
}

void CharacterManager::CheckAndRemoveDeadCharacter(int index){
	FAST_RETURN_VOID(!characters[index]->GetIsDead());
	RemoveCharacter(index);
}

void CharacterManager::RemoveAllCharacter(){
	int end = characters.end() - characters.begin();
	for (int i=0; i < end; i++){
		RemoveCharacter(i);
	}
}
void CharacterManager::RemoveCharacter(int index){
	FAST_RETURN_AND_ERROR_VOID(characters[index] == NULL, "キャラクタベクタに指定されたインデックスが存在しません。");
	SAFE_DELETE(characters[index]);
	characters.erase(characters.begin()+index);
}

void CharacterManager::FunctionAll(void(*func)(int)){
	int end = characters.end() - characters.begin();
	for (int i=0; i < end; i++){
		func(i);
	}
}