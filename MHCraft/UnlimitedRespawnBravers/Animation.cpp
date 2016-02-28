#include"Animation.h"
#include"ErrorCheck.h"

Animation::Animation() 
{
	Initialize();
}

Animation::~Animation()
{
}

void Animation::AddMotion(e_Motion motionName, std::vector<int > motion, int intarval,bool isLoop)
{
	CheckAlreadyThere(motionName, this->motions);

	this->motions[motionName].motions = motion;
	this->motions[motionName].isLoop = isLoop;
	this->motions[motionName].intarval = intarval;
}

int Animation::GetMotion()
{
	return this->currentMotion.motions[this->motionCount];
}


void Animation::Initialize()
{
	this->motionCount = 0;
	this->intarvalCount = 0;
	this->isEnd = false;
}

void Animation::Update()
{
	intarvalCount = intarvalCount < currentMotion.intarval ? ++intarvalCount : 0;

	if (intarvalCount != 0) return;

	if (currentMotion.isLoop)
		this->motionCount = motionCount < this->currentMotion.motions.size() - 1 ? ++motionCount : 0;
	else
	{
		this->motionCount = motionCount < this->currentMotion.motions.size() - 1 ? ++motionCount : isEnd = true;
	}
}

void Animation::ChangeMotion(e_Motion motionName)
{
	Initialize();
	this->currentMotion.motions = this->motions[motionName].motions;
	currentMotion.currentName = motionName;
	currentMotion.isLoop = motions[motionName].isLoop;
	currentMotion.intarval = motions[motionName].intarval;
}

bool Animation::IsEnd()
{
	return isEnd;
}