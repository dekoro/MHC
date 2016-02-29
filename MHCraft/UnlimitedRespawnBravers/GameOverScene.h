#ifndef _SCENEMANAGER_GAMEOVERSCENE_GAMEOVERSCENE_H_
#define _SCENEMANAGER_GAMEOVERSCENE_GAMEOVERSCENE_H_

#include "IScenes.h"
class DeviceManager;
class ImageData;

class GameOverScene: public IScenes
{
public:
	GameOverScene();
	~GameOverScene();

	void				Initialize(SceneMediateData sceneData);
	SceneMediateData	Update();
	void				Draw();
	void				Finalize();

private:

	DeviceManager*		deviceManager;
	ImageData*		imageBackGround;
};

#endif // !_SCENEMANAGER_GAMEOVERSCENE_GAMEOVERSCENE_H_





