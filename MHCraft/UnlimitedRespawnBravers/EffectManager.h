#ifndef EFFECT_MANAGER
#define EFFECT_MANAGER

#include<unordered_map>
#include<memory>

class BaseEffect;

 class EffectManager
{
public:
	EffectManager();
	~EffectManager();

	void AddEffect(std::string name, std::shared_ptr<BaseEffect> effect);

	BaseEffect* GetEffect(std::string name);

	//�G�t�F�N�g�S���폜
	void RemoveAll();

	//�����폜
	void RemoveCondition(std::string name);

private:
	std::unordered_map<std::string, std::shared_ptr<BaseEffect>> effects;

};

#endif