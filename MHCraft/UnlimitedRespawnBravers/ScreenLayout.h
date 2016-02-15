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


private:
	std::vector<std::shared_ptr<PostEffect>> Screens;
	e_ScreenLayout layOut;

};

#endif