#ifndef _SCENEMANAGER_GAMECLEARSCENE_GAMECLEARSCENE_H_
#define _SCENEMANAGER_GAMECLEARSCENE_GAMECLEARSCENE_H_

#include "IScenes.h"
class DeviceManager;
class ImageData;

class GameClearScene: public IScenes
{
public:
	GameClearScene();
	~GameClearScene();

	void				Initialize(SceneMediateData sceneData);
	SceneMediateData	Update();
	void				Draw();
	void				Finalize();

private:
	DeviceManager*	deviceManager;
	ImageData*		imageBackGround;
};


#endif