#include"EffectManager.h"
#include"BaseEffect.h"
#include"ErrorCheck.h"
#include"TextureMapping.h"
#include"Cutting.h"


std::shared_ptr<EffectManager> EffectManager::effectMangaer = std::shared_ptr<EffectManager>(new EffectManager());

EffectManager::EffectManager()
{

}

EffectManager::~EffectManager()
{
}

void EffectManager::AddEffect(std::string name, std::string path)
{
#if _DEBUG
	CheckAlreadyThere(name, effects);//‚·‚Å‚É“o˜^‚³‚ê‚Ä‚¢‚é‚©
#endif

	this->effects[name] = LoadPixelShader(path.c_str());
}

int EffectManager::GetEffect(std::string name)
{
#if _DEBUG
	CheckRegiserKey(name,effects);
#endif
	return effects[name];
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