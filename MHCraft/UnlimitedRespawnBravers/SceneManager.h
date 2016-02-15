#ifndef _SCENEMANAGER_SCENEMANAGER_H_
#define _SCENEMANAGER_SCENEMANAGER_H_

#include "HeaderHub.h"
#include "UI.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void Initialize();
	void Update();
	void Draw();

private:
	std::map<SceneName, IScenes*> sceneMap;
	SceneName curScene;

	void ChangeScene(SceneMediateData nextSceneName);
	void RemoveSceneMap(SceneName sceneName);
	void ClearSceneMap();
};



#endif