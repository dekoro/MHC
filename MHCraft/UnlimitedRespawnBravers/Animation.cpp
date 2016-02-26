#include"Animation.h"
#include"ErrorCheck.h"

Animation::Animation(int intarval) :intarval(intarval)
{
	Initialize();
}

Animation::~Animation()
{
}

void Animation::AddMotion(e_Motion motionName, std::vector<int > motion, bool isLoop)
{
	CheckAlreadyThere(motionName, this->motions);

	this->motions[motionName].motions = motion;
	this->motions[motionName].isLoop = isLoop;
}

int Animation::GetMotion()
{
	return this->currentMotion.motions[this->motionCount];
}


void Animation::Initialize()
{
	this->motionCount = 0;
	intarvalCount = 0;
	this->isEnd = false;
}

void Animation::Update()
{
	intarvalCount = intarvalCount < intarval ? ++intarvalCount : 0;

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
}

bool Animation::IsEnd()
{
	return isEnd;
}