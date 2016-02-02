#ifndef _DEVICE_DEVICEMANAGER_H_
#define _DEVICE_DEVICEMANAGER_H_

#include "GSystemHub.h"
#include "InputManager.h"
#include "ImageRenderer.h"
#include "MusicRenderer.h"
#include "SoundRenderer.h"

class DeviceManager
{
public:
	~DeviceManager();
	static DeviceManager*	GetInstance();
	InputManager*	Input();
	ImageRenderer*	Image();
	SoundRenderer*	Sound();

private:
	static DeviceManager*	instance;
	InputManager*	inputManager;
	ImageRenderer*	imageRenderer;
	SoundRenderer*	soundRenderer;

	DeviceManager();
	DeviceManager(const DeviceManager& other) = delete;
	DeviceManager& operator = (const DeviceManager& other) = delete;



};

#endif


