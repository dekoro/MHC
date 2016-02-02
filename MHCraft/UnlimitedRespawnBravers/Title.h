#ifndef _SCENEMANAGER_TITLE_TITLE_H_
#define _SCENEMANAGER_TITLE_TITLE_H_
#include "HeaderHub.h"
#include "IScenes.h"
#include"TextureMapping.h"
#include"PostEffect.h"
#include<memory>

class SceneTitle : public IScenes
{
public:
	SceneTitle();
	~SceneTitle();

	void				Initialize(SceneMediateData sceneData);
	SceneMediateData	Update();
	void				Draw() ;
	void				Finalize();
	ImageData*			imageBackGround;
	int					counter;

private:
	DeviceManager* device;
	int		nextSceneCount;
	int		enterPlayerIndex;
	bool isEnd;
	int		CheckControllPadNo();
	void	CountdownNextScene();
	void	DrawFlashPushXButton();

	std::shared_ptr<PostEffect> postEffect;
	TextureMapping texMapEffect;

	int x = 0,y = 0;


};


#endif