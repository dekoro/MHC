#include"CameraManager.h"
#include"Camera.h"

CameraManager::CameraManager()
{
}

CameraManager::~CameraManager()
{
}

void CameraManager::AddCamera(std::shared_ptr<Camera> camera)
{
	this->cameras.push_back(camera);
}

void CameraManager::Update()
{
	for (auto camera:cameras)
	{
		camera->Update();
	}
}

void CameraManager::SetCamerasPosition()
{
	for (auto camera: cameras)
	{
		camera->SetPosition();
	}
}
