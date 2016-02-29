#ifndef _SCENEMANAGER_GAMEMAIN_GAMEMAIN_H_
#define _SCENEMANAGER_GAMEMAIN_GAMEMAIN_H_

#include "GSystemHub.h"
#include "GMath.h"
#include "IScenes.h"

#include<memory>
#include"Camera.h"
#include"TextureMapping.h"
#include"ScreenLayout.h"
#include"Cutting.h"
#include"Blur.h"
#include"Stage.h"
#include"TextLoader.h"


class CharacterManager;
class PlayerManager;
class EnemyManager;
class ItemManager;
class DamageAreaManager;
class LaserManager;


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
	ImageData*		imageBackGround;
	bool nowStart;
	
	std::shared_ptr<ScreenLayout> screen;
	std::shared_ptr<Stage> stage;


	std::shared_ptr<LaserManager>		laserManager;
	std::shared_ptr<PlayerManager>		playerManager;
	std::shared_ptr<EnemyManager>		enemyManager;
	std::shared_ptr<DamageAreaManager>	damageAreaManager;
	std::shared_ptr<ItemManager>		itemManager;


	void LocalDraw();
	void AllManagersInitialize(int startPlayerIndex);
	void AllManagersUpdate();
	void AllManagersDraw();
	void AllManagersFinalize();
	void ShaderLoad();
	void SHaderDalete();
	void FadeIn();
};




#endif