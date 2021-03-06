#ifndef _SCENEMANAGER_TITLE_TITLE_H_
#define _SCENEMANAGER_TITLE_TITLE_H_
#include "HeaderHub.h"
#include "IScenes.h"

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

	int		CheckControllPadNo();
	void	CountdownNextScene();
	void	DrawFlashPushXButton();


};


#endif