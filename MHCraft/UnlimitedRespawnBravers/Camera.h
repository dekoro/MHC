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
	Camera(){};
	Camera(Player* player);
	~Camera();

	//カメラの拡縮をセット
	//void SetScale(VECTOR scale);

	//カメラのポジションをセット
	//void SetMove(Vec2 pos);

	void Update();

	void SetPosition();//カメラのポジションをセットする

private:
	Player* player;//こいつからポジションをもらいカメラの中心座標にする

	VECTOR lookPos;//視点
	VECTOR scale ;//拡大縮小率


};


#endif