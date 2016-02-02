#include"EffectManager.h"
#include"BaseEffect.h"
#include"ErrorCheck.h"


EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
}

void EffectManager::AddEffect(std::string name, std::shared_ptr<BaseEffect> effect)
{
#if _DEBUG
	CheckAlreadyThere(name, effects);//‚·‚Å‚É“o˜^‚³‚ê‚Ä‚¢‚é‚©
#endif

	this->effects[name] = effect;
}

BaseEffect* EffectManager::GetEffect(std::string name)
{
	CheckRegiserKey(name,effects);
	return effects[name].get();
}

void EffectManager::RemoveAll()
{
	effects.clear();
}

void EffectManager::RemoveCondition(std::string name)
{

}