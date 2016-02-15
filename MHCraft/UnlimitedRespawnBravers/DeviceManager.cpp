#include "DeviceManager.h"

DeviceManager* DeviceManager::instance = NULL;

DeviceManager::~DeviceManager(){
	SAFE_DELETE(inputManager);
	SAFE_DELETE(imageRenderer);
	SAFE_DELETE(soundRenderer);
	SAFE_DELETE(instance);
	Debug::Alert("DviceManagerのデストラクタがコールされました。");
}

DeviceManager*	DeviceManager::GetInstance(){
	if (instance == NULL){ instance = new DeviceManager(); }
	return instance;
}

InputManager*	DeviceManager::Input(){
	return inputManager;
}

ImageRenderer*	DeviceManager::Image(){
	return imageRenderer;
}

SoundRenderer*	DeviceManager::Sound(){
	return soundRenderer;
}

//---private---
DeviceManager::DeviceManager(){
	inputManager	= new InputManager();
	imageRenderer	= new ImageRenderer();
	soundRenderer	= new SoundRenderer();
}

