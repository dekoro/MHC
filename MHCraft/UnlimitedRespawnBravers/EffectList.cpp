#include"EffectList.h"
#include"ErrorCheck.h"

EffectList::EffectList()
{
}

EffectList::~EffectList()
{
}

void EffectList::AddEffect(std::string key, std::shared_ptr<BaseEffect> effect)
{
	CheckAlreadyThere(key,this->effectList);//すでにあるかチェック

	effectList[key] = effect;
}

BaseEffect* EffectList::GetEffect(std::string key)
{
	CheckRegiserKey(key,effectList);//あるかチェック
	return this->effectList[key].get();
}