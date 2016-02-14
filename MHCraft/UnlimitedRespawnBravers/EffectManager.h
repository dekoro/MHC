#ifndef EFFECT_MANAGER
#define EFFECT_MANAGER

#include<unordered_map>
#include<memory>

/*
シェーダには読み込み制限あるためほかにも複数生成されたら困るためにシングルトンにする。

ここでシェーダの読み込みと削除を管理する

*/

class BaseEffect;

 class EffectManager
{
public:
	~EffectManager();

	int GetEffect(std::string name);

	//エフェクト全部削除
	void RemoveAll();

	//条件削除
	void RemoveCondition(std::string name);

	static EffectManager* GetInstance();

	void AddEffect(std::string name, std::string path);

	EffectManager();
private:


private:
	static std::shared_ptr<EffectManager> effectMangaer;
	std::unordered_map<std::string, int> effects;

};

#endif