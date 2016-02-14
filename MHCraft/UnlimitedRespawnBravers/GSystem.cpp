#include "GSystem.h"


void AnimeData::SetupAnimeData(int XNum, int typeNum, int oneSizeX, int oneSizeY, int skipFrame, bool isLoop){
	this->XNum			= XNum;
	this->typeNum		= typeNum;
	this->oneSizeX		= oneSizeX;
	this->oneSizeY		= oneSizeY;
	this->skipFrame		= skipFrame;
	this->isLoop		= isLoop;
	this->isAnimation	= (GetFrameAllNum() > 1);
}

AnimeData AnimeData::Setup(int XNum, int typeNum, int oneSizeX, int oneSizeY, int skipFrame, bool isLoop){
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

HitData::HitData(Vec2 fromPos, int power, int damage):fromPosition(fromPos), knockbackPower(power), damage(damage){}

HitData HitData::Setup(Vec2 fromPos, int power, int damage){
	return HitData(fromPos, power, damage);
}

HitData* HitData::SetupSelf(Vec2 fromPos , int power, int damage){
	this->fromPosition	= fromPos;
	this->damage			= power;

	return this;
}

HitData HitData::NoHit(){
	return HitData(Vec2::Zero(), -1, -1);
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




