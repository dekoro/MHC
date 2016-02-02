#ifndef POST_EFFECT
#define POST_EFFECT

#include<functional>
#include<DxLib.h>

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
	PostEffect(int hGraphics, BaseEffect* effect);
	virtual ~PostEffect();

	void Rendaring(std::function<void()> Draw);
	
private:


private:
	int hGraphics;
	BaseEffect* effect;
	VERTEX2DSHADER vertex[4];
};

#endif