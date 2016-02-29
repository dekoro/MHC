#include "GameClearScene.h"
#include "DeviceManager.h"
#include "ImageData.h"

GameClearScene::GameClearScene(){
	deviceManager = DeviceManager::GetInstance();
	imageBackGround = deviceManager->Image()->CopyImageData(imageAsset_GameClear_BackGround);
}

GameClearScene::~GameClearScene(){

}

void GameClearScene::Initialize(SceneMediateData sceneData){
}

SceneMediateData GameClearScene::Update(){
	if (deviceManager->Input()->CheckKeyPushAllPad(GKey_Attack)){
		return SceneMediateData::Setup(SceneName::SCENE_TITLE);
	}
	return SceneMediateData::Setup(SceneName::SCENE_CLEAR);
}

void GameClearScene::Draw(){
	DrawGraph(0, 0, imageBackGround->GetImageHandle(), TRUE);
}

void GameClearScene::Finalize(){

}










