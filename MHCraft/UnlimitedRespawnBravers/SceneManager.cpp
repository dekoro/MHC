#include "SceneManager.h"
#include"GameMain.h"
#include"SelectScene.h"

SceneManager::SceneManager(){
	SceneMediateData startupSceneData = SceneMediateData::Setup(SCENE_SELECT);

	sceneMap.insert(map<SceneName, IScenes*>::value_type(SCENE_TITLE	, new SceneTitle()));
	sceneMap.insert(map<SceneName, IScenes*>::value_type(SCENE_SELECT, new SelectScene()));
	sceneMap.insert(map<SceneName, IScenes*>::value_type(SCENE_GAMEMAIN	, new SceneGameMain()));

	sceneMap[startupSceneData.nextScene]->Initialize(startupSceneData);
	ChangeScene(startupSceneData);
}

SceneManager::~SceneManager(){
	ClearSceneMap();
}

void SceneManager::Initialize(){

}

void SceneManager::Update(){
	SceneMediateData nextSceneData;
	nextSceneData = sceneMap[curScene]->Update();
	ChangeScene(nextSceneData);
}

void SceneManager::Draw(){
	sceneMap[curScene]->Draw();
	UI::GetInstance()->Draw();
}

void SceneManager::ChangeScene(SceneMediateData nextSceneData){
	if (curScene == nextSceneData.nextScene){ return; }
	sceneMap[curScene]->Finalize();

	sceneMap[nextSceneData.nextScene]->Initialize(nextSceneData);
	curScene = nextSceneData.nextScene;
}

void SceneManager::RemoveSceneMap(SceneName sceneName){
	SAFE_DELETE(sceneMap[sceneName]);
	sceneMap.erase(sceneName);
}

void SceneManager::ClearSceneMap(){
	RemoveSceneMap(SCENE_TITLE);
	RemoveSceneMap(SCENE_GAMEMAIN);
}











