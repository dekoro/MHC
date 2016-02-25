#include"Animation.h"
#include"ErrorCheck.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::AddMotion(std::string motionName, std::vector<int > motion)
{
	CheckAlreadyThere(motionName, this->motions);

	this->motions[motionName] = motion;
}

int Animation::GetMotion(std::string motionName)
{
	if (currentName == motionName)
	{
		return this->currentMotion[this->motionCount];
	}
	else
	{
		ChangeMotion(motionName);
		return this->currentMotion[this->motionCount];
	}
}


void Animation::Initialize()
{
	this->motionCount = 0;
}

void Animation::Update()
{
	this->motionCount = motionCount < this->currentMotion.size()-1 ? ++motionCount : 0;
}

void Animation::ChangeMotion(std::string motionName)
{
	Initialize();
	this->currentMotion = this->motions[motionName];
	this->currentName = motionName;
}