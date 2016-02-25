#ifndef _SCENEMANAGER_GAMEMAIN_GAMEMAIN_H_
#define _SCENEMANAGER_GAMEMAIN_GAMEMAIN_H_

#include "GSystemHub.h"
#include "GMath.h"
#include "IScenes.h"
#include "Managers.h"
#include "PlayerManager.h"
#include "EnemyManager.h"
#include "ItemManager.h"

#include<memory>
#include"Camera.h"
#include"TextureMapping.h"
#include"ScreenLayout.h"
#include"Cutting.h"
#include"Blur.h"
#include"Stage.h"
#include"TextLoader.h"
#include"Animation.h"


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
	
	//テスト
	Animation anime;
	

	//テスト
	std::shared_ptr<BaseEffect> blur;
	std::shared_ptr<Cutting> cut;
	std::shared_ptr<ScreenLayout> screen;
	std::shared_ptr<Stage> stage;


	void LocalDraw();
	void AllManagersInitialize(int startPlayerIndex);
	SceneMediateData AllManagersUpdate();
	void AllManagersDraw();
	void AllManagersFinalize();
	void ShaderLoad();
	void SHaderDalete();
};




#endif