#ifndef POST_EFFECT
#define POST_EFFECT

#include<functional>
#include<DxLib.h>

/*
�|�X�g�G�t�F�N�g�Ɏg���`��^�[�Q�b�g��1��
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
	int hGraphics;//���̈�̃n���h���������ȃ|�X�g�G�t�F�N�g�Ŏg���܂킷
	BaseEffect* effect;
	VERTEX2DSHADER vertex[4];
};

#endif