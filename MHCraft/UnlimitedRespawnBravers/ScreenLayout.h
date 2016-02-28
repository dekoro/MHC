#ifndef SCREEN_LAYOUT
#define SCREEN_LAYOUT

#include"PostEffect.h"
#include"e_ScreenLayout.h"
#include<memory>
#include<vector>


/*
	コンストラクタで受け取った数だけ画面を生成する
*/

class PlayerManager;

class ScreenLayout
{
public:
	ScreenLayout(e_ScreenLayout layOut);
	~ScreenLayout();

	void Initialize(PlayerManager* players);

	//第一引数:どこのスクリーンに描画するか 第二引数:描画する処理の関数ポインタ
	void Rendaring(std::function<void()> Draw);

	//ずらす方向ベクトル　ずらす寮 変更するスクリーンの番号(0～3)
	void SetUseBlurConst(Vec2 direction, float shit, e_ScreenNumber screenNum);//ブラーに定数を渡す

	void SetUseTexMapConst(bool b, e_ScreenNumber screenNum);

private:
	void ChangeToScreenShader(std::string name, e_ScreenNumber screenNum);

private:
	std::vector<std::shared_ptr<PostEffect>> Screens;
	e_ScreenLayout layOut;

};

#endif