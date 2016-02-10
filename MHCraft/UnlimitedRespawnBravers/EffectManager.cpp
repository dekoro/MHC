#include"EffectManager.h"
#include"BaseEffect.h"
#include"ErrorCheck.h"
#include"TextureMapping.h"
#include"Cutting.h"

std::shared_ptr<EffectManager> EffectManager::effectMangaer = std::shared_ptr<EffectManager>();

EffectManager::EffectManager()
{
	AddEffect("texmap",std::make_shared<TextureMapping>());
	AddEffect("cut", std::make_shared<Cutting>());
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
#if _DEBUG
	CheckRegiserKey(name,effects);
#endif
	return effects[name].get();
}

void EffectManager::RemoveAll()
{
	effects.clear();
}

void EffectManager::RemoveCondition(std::string name)
{

}

EffectManager* EffectManager::GetInstance()
{
	return	effectMangaer.get();
}