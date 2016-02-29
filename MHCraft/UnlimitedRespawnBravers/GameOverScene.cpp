#include "GameOverScene.h"
#include "DeviceManager.h"
#include "ImageData.h"



GameOverScene::GameOverScene(){
	deviceManager = DeviceManager::GetInstance();
	imageBackGround = deviceManager->Image()->CopyImageData(imageAsset_GameOver_BackGround);
	
}
GameOverScene::~GameOverScene(){}

void GameOverScene::Initialize(SceneMediateData sceneData){}
SceneMediateData GameOverScene::Update(){
	if (deviceManager->Input()->CheckKeyPushAllPad(GKey_Attack)){
		return SceneMediateData::Setup(SceneName::SCENE_TITLE);
	}
	return SceneMediateData::Setup(SceneName::SCENE_GAMEOVER);
}
void GameOverScene::Draw(){
	DrawGraph(0, 0, imageBackGround->GetImageHandle(), TRUE);
}
void GameOverScene::Finalize(){}