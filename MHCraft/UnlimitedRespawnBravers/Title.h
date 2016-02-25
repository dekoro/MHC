#ifndef _SCENEMANAGER_TITLE_TITLE_H_
#define _SCENEMANAGER_TITLE_TITLE_H_
#include "HeaderHub.h"
#include "IScenes.h"
#include "GQuadrangle.h"
#include "GCircle.h"
#include "GRectangle.h"

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
	DeviceManager*	device;
	int		nextSceneCount;
	int		enterPlayerIndex;
	bool	isEnd;
	int		CheckControllPadNo();
	void	CountdownNextScene();
	void	DrawFlashPushXButton();
	
	void LocalDraw();

};


#endif