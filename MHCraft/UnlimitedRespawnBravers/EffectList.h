#ifndef EFFECT_LIST
#define EFFECT_LIST

#include<memory>
#include<unordered_map>
#include<string>

class BaseEffect;

class EffectList
{
public:
	EffectList();
	~EffectList();

	void AddEffect(std::string key,std::shared_ptr<BaseEffect> effect);
	BaseEffect* GetEffect(std::string key);

private:
	std::unordered_map<std::string,std::shared_ptr<BaseEffect>> effectList;

};


#endif