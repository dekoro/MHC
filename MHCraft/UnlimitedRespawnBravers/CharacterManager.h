#ifndef _CHARACTER_CHARACTERMANAGER_H_
#define _CHARACTER_CHARACTERMANAGER_H_

#include "GSystemHub.h"
#include "ICharacter.h"
#include "Enemy.h"

class CharacterManager
{
public:
	CharacterManager();
	~CharacterManager();
	void Initialize();
	void Update();
	void Draw();
	void AddCharacter(ICharacter* character);

private:
	std::vector<ICharacter*> characters;

	void RemoveDeadCharacter();
	void CheckAndRemoveDeadCharacter(int index);
	void RemoveAllCharacter();
	void RemoveCharacter(int index);
	void FunctionAll(void (*func)(int));
};


#endif

