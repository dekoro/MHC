#ifndef _DEVICE_INPUT_ENUMGKEY_H_
#define _DEVICE_INPUT_ENUMGKEY_H_

#include"SystemHub.h"

enum GKey{
	GKey_Up,
	GKey_Down,
	GKey_Left,
	GKey_Right,
	GKey_Attack,
	GKey_Skill,
	GKey_Appeal
};

enum GKeyType{
	GKeyType_None,
	GKeyType_GamePad,
	GKeyType_Keyboard,
	GKeyType_NumPad
};

const unsigned int defaultGamePad[GKEY_NUM] = {
	PAD_INPUT_UP,
	PAD_INPUT_DOWN,
	PAD_INPUT_LEFT,
	PAD_INPUT_RIGHT,
	PAD_INPUT_1,
	PAD_INPUT_2,
	PAD_INPUT_3
};

const unsigned int defaultKeyboard1[GKEY_NUM] = {
	KEY_INPUT_W,
	KEY_INPUT_S,
	KEY_INPUT_A,
	KEY_INPUT_D,
	KEY_INPUT_Z,
	KEY_INPUT_X,
	KEY_INPUT_C
};

const unsigned int defaultKeyboard2[GKEY_NUM] = {
	KEY_INPUT_I,
	KEY_INPUT_K,
	KEY_INPUT_J,
	KEY_INPUT_L,
	KEY_INPUT_N,
	KEY_INPUT_M,
	KEY_INPUT_COMMA
};

const unsigned int defaultNumPad[GKEY_NUM] = {
	KEY_INPUT_NUMPAD8,
	KEY_INPUT_NUMPAD5,
	KEY_INPUT_NUMPAD4,
	KEY_INPUT_NUMPAD6,
	KEY_INPUT_NUMPAD1,
	KEY_INPUT_NUMPAD2,
	KEY_INPUT_NUMPAD3
};


#endif
