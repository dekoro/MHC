#ifndef CAMERA
#define CAMERA

#include<DxLib.h>
#include"GMath.h"

class Player;

/*
うけとったプレイヤーのポジションを中心にカメラは更新する。
SetPosition()は描画先を変更するたびに呼ばないとリセットされてしまうので注意
*/

class Camera
{
public:
#if _DEBUG
	Camera()
	{
		position = VGet(0,0,0);
		this->scale = 2000.f;
	};
#endif
	Camera(Player* player,int padNum);
	~Camera();

	void Initialize();

	//カメラの拡縮をセット
	void SetScale(float scale);

	void Update();

	void SetPosition();//カメラのポジションをセットする

private:
	Player* player;//こいつからポジションをもらいカメラの中心座標にする
	int padNum;//どのプレイヤーが操作するカメラか識別するため

	VECTOR position;//視点
	float scale ;//拡大縮小率


};


#endif