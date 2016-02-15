#ifndef POST_EFFECT
#define POST_EFFECT

#include<functional>
#include<DxLib.h>
#include"e_ScreenLayout.h"
#include<functional>
#include"EffectList.h"
#include"Camera.h"


/*
�|�X�g�G�t�F�N�g
���̃N���X�P�ɂ��P�̃Q�[����ʁB
�S�ɉ�ʕ�������ꍇ�͂S��������B

�R���X�g���N�^�Ŏ󂯎��G�t�F�N�g�́A�s�N�Z���V�F�[�_���܂݂��e�N�X�`���}�b�s���O�����镨�B
�����̃G�t�F�N�g�ɂ���ĉ�ʂɗ^����G�t�F�N�g��ς���B
*/



class BaseEffect;

class PostEffect
{
public:
	//�G�t�F�N�g�͌�ŃV���O���g���ɂ���K�v�����肻���B
	PostEffect(Player* player);
	PostEffect(Player* player,e_ScreenLayout lauOut, e_ScreenNumber);//�X�N���[���̔ԍ������̂܂܃J�����̃C���v�b�g�Ɋ��蓖�Ă�
	virtual ~PostEffect();

	void Initialize();//�V�[�����V�F�[�_�̓ǂݍ��݂��I����Ă�����s����

	void Rendaring(std::function<void()> Draw, float scale);

private:
	void VertexErch(std::function<void(int x)> action);


private:
	int hGraphics;
	BaseEffect* effect;
	EffectList effetList;
	VERTEX2DSHADER vertex[4];
	Camera camera;
	unsigned int color;
};

#endif