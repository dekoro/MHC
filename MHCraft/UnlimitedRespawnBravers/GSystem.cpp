#include "GSystem.h"

PlayerColorList PlayerColorList::Setup(unsigned int colorHair, unsigned int colorSkin, unsigned int colorArmer){
	PlayerColorList tmp;
	tmp.colorHair = colorHair;
	tmp.colorSkin = colorSkin;
	tmp.colorArmer = colorArmer;
	return tmp;
}
PlayerColorList PlayerColorList::Setup(int colorHairR, int colorHairG, int colorHairB,
												int colorSkinR, int colorSkinG, int colorSkinB,
												int colorArmerR, int colorArmerG, int colorArmerB){
	return Setup( GetColor(colorHairR	, colorHairG	, colorHairB)
				, GetColor(colorSkinR	, colorSkinG	, colorSkinB)
				, GetColor(colorArmerR	, colorArmerG	, colorArmerB));
}
void PlayerColorList::SetupSelf(unsigned int colorHair, unsigned int colorSkin, unsigned int colorArmer){
	this->colorHair		= colorHair;
	this->colorSkin		= colorSkin;
	this->colorArmer	= colorArmer;
}
void PlayerColorList::SetupSelf(int colorHairR	, int colorHairG	, int colorHairB,
								int colorSkinR	, int colorSkinG	, int colorSkinB,
								int colorArmerR	, int colorArmerG	, int colorArmerB){

	SetupSelf( GetColor(colorHairR	, colorHairG	, colorHairB)
			 , GetColor(colorSkinR	, colorSkinG	, colorSkinB)
			 , GetColor(colorArmerR	, colorArmerG	, colorArmerB));
}

void AnimeData::SetupAnimeData(int XNum, int typeNum, int oneSizeX, int oneSizeY, int skipFrame, int isLoop){
	this->XNum			= XNum;
	this->typeNum		= typeNum;
	this->oneSizeX		= oneSizeX;
	this->oneSizeY		= oneSizeY;
	this->skipFrame		= skipFrame;
	this->isLoop		= isLoop;
	this->isAnimation	= (GetFrameAllNum() > 1);
}

AnimeData AnimeData::Setup(int XNum, int typeNum, int oneSizeX, int oneSizeY, int skipFrame, int isLoop){
	AnimeData tmp;
	tmp.SetupAnimeData(XNum, typeNum, oneSizeX, oneSizeY, skipFrame, isLoop);
	return tmp;
}

CharacterInformation CharacterInformation::Setup(int health, int sp, int attackPower, int pushPower, double speed, double hitRange){
	CharacterInformation prm;
	prm.SetupSelf(health, sp, attackPower, pushPower, speed, hitRange);
	return prm;
}

CharacterInformation* CharacterInformation::SetupSelf(int health, int sp, int attackPower, int pushPower, double speed, double hitRange){
	this->health		= health;
	this->maxHealth		= health;
	this->sp			= sp;
	this->maxSp			= sp;
	this->attackPower	= attackPower;
	this->pushPower		= pushPower;
	this->speed			= speed;
	this->hitRange		= hitRange;
	return this;
}

void FPS::SleepNextFrame(){
	Sleep(CalcSleepTime());
}

void FPS::SetNowCount(){
	preTimeCount = GetNowCount();
}

void FPS::SetNowSecondCount(){
	preSecondCount = GetNowCount();
	sleepCount = GAME_FPS;
}

void FPS::ResetCount(){
	SetNowCount();
	SetNowSecondCount();
}

int FPS::CalcSleepTime(){
	int nextSecondCount = preSecondCount + 1000;
	int nowCount = GetNowCount();
	sleepCount--;
	if (sleepCount <= 0 || nextSecondCount <= nowCount){
		SetNowSecondCount();
	}
	return (int)((float)(nextSecondCount-nowCount)/(sleepCount));
}

HitData::HitData(Vec2 fromPos, int power, int damage, int shooterPlayerNo) :fromPosition(fromPos), knockbackPower(power), damage(damage), shooterPlayerNo(shooterPlayerNo){}

HitData HitData::Setup(Vec2 fromPos, int power, int damage, int shooterPlayerNo){
	return HitData(fromPos, power, damage, shooterPlayerNo);
}

HitData* HitData::SetupSelf(Vec2 fromPos, int power, int damage, int shooterPlayerNo){
	this->fromPosition	= fromPos;
	this->damage			= power;

	return this;
}

HitData HitData::NoHit(){
	return HitData(Vec2::Zero(), -1, -1, -1);
}

bool HitData::operator==(HitData other){
	return (fromPosition == other.fromPosition
		 && damage		 == damage);
}
bool HitData::operator!=(HitData other){
	return (fromPosition != other.fromPosition
		 || damage		 != damage);
}

SceneMediateData SceneMediateData::Setup(SceneName nextScene, int playerIndex){
	SceneMediateData tmp;
	tmp.nextScene	= nextScene;
	tmp.playerIndex	= playerIndex;

	return tmp;
}




