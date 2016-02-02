#include "Keyboard.h"

Keyboard::Keyboard(int PlayerNo){
	GKeyType_Keyboard;
}

Keyboard::~Keyboard(){

}

//--private--

unsigned int Keyboard::GetInputState(){
	unsigned int tmpInput = 0;
	unsigned int *pTmpInput = 0;
	char Buf[KEYBOARD_NUM];

#ifndef WAKANNE_SKIP
	GetHitKeyStateAll(Buf);
	for (int i = 0; i < GKEY_NUM; i++){
		FlagManager<unsigned int>::GetAllFlags(&tmpInput);
	//	FlagManager<unsigned int>::PrintFlag();
	}
#endif
	return (unsigned int)tmpInput;
}