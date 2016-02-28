#ifndef SCREEN_LAYOUT
#define SCREEN_LAYOUT

#include"PostEffect.h"
#include"e_ScreenLayout.h"
#include<memory>
#include<vector>


/*
	�R���X�g���N�^�Ŏ󂯎������������ʂ𐶐�����
*/

class PlayerManager;

class ScreenLayout
{
public:
	ScreenLayout(e_ScreenLayout layOut);
	~ScreenLayout();

	void Initialize(PlayerManager* players);

	//������:�ǂ��̃X�N���[���ɕ`�悷�邩 ������:�`�悷�鏈���̊֐��|�C���^
	void Rendaring(std::function<void()> Draw);

	//���炷�����x�N�g���@���炷�� �ύX����X�N���[���̔ԍ�(0�`3)
	void SetUseBlurConst(Vec2 direction, float shit, e_ScreenNumber screenNum);//�u���[�ɒ萔��n��

	void SetUseTexMapConst(bool b, e_ScreenNumber screenNum);

private:
	void ChangeToScreenShader(std::string name, e_ScreenNumber screenNum);

private:
	std::vector<std::shared_ptr<PostEffect>> Screens;
	e_ScreenLayout layOut;

};

#endif