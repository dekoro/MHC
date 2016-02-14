#ifndef EFFECT_MANAGER
#define EFFECT_MANAGER

#include<unordered_map>
#include<memory>

/*
�V�F�[�_�ɂ͓ǂݍ��ݐ������邽�߂ق��ɂ������������ꂽ�獢�邽�߂ɃV���O���g���ɂ���B

�����ŃV�F�[�_�̓ǂݍ��݂ƍ폜���Ǘ�����

*/

class BaseEffect;

 class EffectManager
{
public:
	~EffectManager();

	int GetEffect(std::string name);

	//�G�t�F�N�g�S���폜
	void RemoveAll();

	//�����폜
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