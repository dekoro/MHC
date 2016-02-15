#ifndef _SCENEMANAGER_GAMEMAIN_GAMEMAIN_H_
#define _SCENEMANAGER_GAMEMAIN_GAMEMAIN_H_

#include<memory>

#include "GSystemHub.h"
#include "IScenes.h"

#include"Camera.h"
#include"TextureMapping.h"
#include"ScreenLayout.h"
#include"Cutting.h"
#include"Blur.h"

class PlayerManager;
class EnemyManager;
class ItemManager;
class DamageAreaManager;


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
	DeviceManager*		device;
	ImageData*			imageBackGround;
	std::shared_ptr<PlayerManager>		playerManager;
	std::shared_ptr<EnemyManager>		enemyManager;
	std::shared_ptr<DamageAreaManager>	damageAreaManager;
	std::shared_ptr<ItemManager>		itemManager;
	

	TextureMapping texMapEffect;
	Cutting cut;
	Blur blur;

	std::shared_ptr<Camera> camera;
	std::shared_ptr<ScreenLayout> screen;


	void LocalDraw();
	void AllManagersInitialize(int startPlayerIndex);
	void AllManagersUpdate();
	void AllManagersDraw();
	void AllManagersFinalize();
};




#endif