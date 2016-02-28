#ifndef SELECT_SCENE
#define SELECT_SCENE

#include"IScenes.h"
#include"Selecter.h"
#include"GSystem.h"

class InputManager;

class SelectScene : public IScenes
{
public:
	SelectScene();
	~SelectScene();

	void				Initialize(SceneMediateData sceneData)override;
	SceneMediateData	Update() override;
	void				Draw() override;
	void				Finalize() override;


private:
	Selecter selecter;
	SceneMediateData date;
	InputManager* input;
	bool isEnd;
};


#endif