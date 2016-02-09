#ifndef CAMERA_MANAGER
#define CAMERA_MANAGER

#include<vector>
#include<memory>

class Camera;

/*
カメラはプレイヤーの数用意するためそれを管理するクラス。
*/

class CameraManager
{
public:
	CameraManager();
	~CameraManager();

	void AddCamera(std::shared_ptr<Camera> camera);

	void Update();

	void SetCamerasPosition();

private:
	std::vector<std::shared_ptr<Camera>> cameras;
};


#endif