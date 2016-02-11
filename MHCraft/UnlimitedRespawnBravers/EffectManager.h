#ifndef EFFECT_MANAGER
#define EFFECT_MANAGER

#include<unordered_map>
#include<memory>

/*
シェーダには読み込み制限あるためほかにも複数生成されたら困るためにシングルトンにする。

*/

class BaseEffect;

 class EffectManager
{
public:
	~EffectManager();

	BaseEffect* GetEffect(std::string name);

	//エフェクト全部削除
	void RemoveAll();

	//条件削除
	void RemoveCondition(std::string name);

	static EffectManager* GetInstance();

	void AddEffect(std::string name,std::shared_ptr<BaseEffect> effect);

private:
	EffectManager();

private:
	static std::shared_ptr<EffectManager> effectMangaer;
	std::unordered_map<std::string, std::shared_ptr<BaseEffect>> effects;

};

#endif