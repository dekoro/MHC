#ifndef _CHARACTER_CHARACTER_H_
#define _CHARACTER_CHARACTER_H_

#include "GSystemHub.h"
#include "ImageRenderer.h"

class ICharacter
{
public:
	ICharacter(){}
	~ICharacter(){}

	virtual void Initialize()	= 0;
	virtual void Update()		= 0;
	virtual void Draw()			= 0;
	virtual bool GetIsDead(){ return isDead; }
	virtual Vec2 GetPosition(){ return position; };
protected:
	Vec2	position;
	bool	isDead;

private:

};



#endif

