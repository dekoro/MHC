#ifndef _GSYSTEM_GSYSTEM_H_
#define _GSYSTEM_GSYSTEM_H_

#define DISPLAY_SIZE_W		1280
#define DISPLAY_SIZE_H		720
#define MAX_PLAYER			4
#define GKEY_NUM			7
#define KEYBOARD_NUM		256
#define ANIME_FRAME_NUM		128
#define	GAME_FPS			60
#define PI					3.14159265359

#define PLAYER_ATTACK_STOP_COUNT		0
#define PLAYER_DAMAGE_INVINCIBLE_COUNT	120
#define PLAYER_DAMAGE_STOP_COUNT		30

#define MAX_LASER_NUM			512

#define DEFAULT_PLAYER_HEALTH	10
#define DEFAULT_PLAYER_SP		10
#define DEFAULT_PLAYER_SPEED	5

#define CONTROLLER_STICK_LOWER_LIMIT		0.2
#define CONTROLLER_STICK_HIGHER_LIMIT		0.8

#define FIELD_SIZE 600

#define FIELD_MIN_Y	-FIELD_SIZE
#define FIELD_MIN_X	-FIELD_SIZE
#define FIELD_MAX_Y	 FIELD_SIZE
#define FIELD_MAX_X	 FIELD_SIZE
//#define USE_PAD_MAX 4


#include "SystemHub.h"
#include "Vec2.h"
#include "GMath.h"

enum SceneName {
	SCENE_TITLE,
	SCENE_GAMEMAIN,
	SCENE_SELECT,
	SCENE_CLEAR,
	SCENE_GAMEOVER
};

struct Window {
	const static int WIDTH = 1280;
	const static int HEIGHT = 720;
	const static int COLOR_BIT = 32;
};

const int defaultKeyConfigPad[GKEY_NUM] = {
	PAD_INPUT_UP,
	PAD_INPUT_DOWN,
	PAD_INPUT_LEFT,
	PAD_INPUT_RIGHT,
	PAD_INPUT_1,
	PAD_INPUT_2,
	PAD_INPUT_3
};

const int defaultKeyConfigKeyboard[GKEY_NUM] = {
	KEY_INPUT_UP,
	KEY_INPUT_DOWN,
	KEY_INPUT_LEFT,
	KEY_INPUT_RIGHT,
	KEY_INPUT_Z,
	KEY_INPUT_X,
	KEY_INPUT_C,
};

class PlayerColorList {
public:
	PlayerColorList() {}
	unsigned int colorHair;
	unsigned int colorSkin;
	unsigned int colorArmer;
	unsigned int colorFrame;

	static PlayerColorList Setup(unsigned int colorHair, unsigned int colorSkin, unsigned int colorArmer);
	static PlayerColorList Setup(int colorHairR, int colorHairG, int colorHairB, int colorSkinR, int colorSkinG, int colorSkinB, int colorArmerR, int colorArmerG, int colorArmerB);

	void SetupSelf(unsigned int colorHair, unsigned int colorSkin, unsigned int colorArmer);
	void SetupSelf(int colorHairR, int colorHairG, int colorHairB, int colorSkinR, int colorSkinG, int colorSkinB, int colorArmerR, int colorArmerG, int colorArmerB);

};

class AnimeData {
public:
	AnimeData() {}
	int		XNum;
	int		typeNum;
	int		oneSizeX;
	int		oneSizeY;
	int		skipFrame;
	bool	isLoop;
	bool	isAnimation;


	void				SetupAnimeData(int XNum, int typeNum, int oneSizeX, int oneSizeY, int skipFrame, int isLoop);
	int					GetFrameAllNum() { return (XNum * typeNum > 0) ? XNum*typeNum : 1; }
	static AnimeData	Setup(int XNum, int typeNum, int oneSizeX, int oneSizeY, int skipFrame, int isLoop);
};

class CharacterInformation
{
public:
	CharacterInformation() {}
	int		health;
	int		maxHealth;
	int		sp;
	int		maxSp;
	int		attackPower;
	int		pushPower;
	double	speed;
	double	hitRange;

	static CharacterInformation Setup(int health, int sp, int attackPower, int pushPower, double speed, double hitRange);
	CharacterInformation* SetupSelf(int health, int sp, int attackPower, int pushPower, double speed, double hitRange);
};

class FPS {
public:
	FPS() { ResetCount(); }
	~FPS() {}
	void SleepNextFrame();

private:
	int preSecondCount;
	int preTimeCount;
	int sleepCount;
	void SetNowCount();
	void SetNowSecondCount();
	void ResetCount();
	int CalcSleepTime();
};

class HitData
{
public:
	HitData() {}
	HitData(Vec2 fromPos, int power, int damage, int shooterPlayerNo = -1);
	~HitData() {}
	Vec2	fromPosition;
	double	hitRange;
	int		damage;
	int		knockbackPower;
	int shooterPlayerNo;

	static HitData	Setup(Vec2 fromPos, int power, int damage, int shooterPlayerNo = -1);
	HitData*		SetupSelf(Vec2 fromPos, int power, int damage, int shooterPlayerNo = -1);
	static HitData	NoHit();

	bool operator==(HitData other);
	bool operator!=(HitData other);

private:

};

class SceneMediateData {
public:
	SceneName	nextScene;
	int			playerIndex;

	static SceneMediateData Setup(SceneName nextScene, int playerIndex = -1);
private:
};

#endif

