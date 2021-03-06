#ifndef _SCENEMANAGER_GAMEMAIN_GAMEMAIN_H_
#define _SCENEMANAGER_GAMEMAIN_GAMEMAIN_H_

#include "GSystemHub.h"
#include "GMath.h"
#include "IScenes.h"
#include "Managers.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"

class SceneGameMain: public IScenes
{
public:
	SceneGameMain();
	~SceneGameMain();
	void				Initialize(SceneMediateData sceneData);
	SceneMediateData	Update();
	void				Draw();
	void				Finalize();

private:
	DeviceManager*	device;
	Managers*		managers;
	ImageData*		imageBackGround;

	void AllManagersInitialize(int startPlayerIndex);
	SceneMediateData AllManagersUpdate();
	void AllManagersDraw();
	void AllManagersFinalize();
};




#endif