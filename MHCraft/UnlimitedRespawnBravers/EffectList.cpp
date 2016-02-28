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
	CheckAlreadyThere(key,this->effectList);//���łɂ��邩�`�F�b�N

	effectList[key] = effect;
}

BaseEffect* EffectList::GetEffect(std::string key)
{
	CheckRegiserKey(key,effectList);//���邩�`�F�b�N
	return this->effectList[key].get();
}