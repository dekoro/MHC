#include "Title.h"

SceneTitle::SceneTitle(){
	device			= DeviceManager::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_Title_BackGround);
}

SceneTitle::~SceneTitle(){

}

void SceneTitle::Initialize(SceneMediateData sceneData){
	device->Sound()->Play(Music_Title_BGM);
	nextSceneCount = 30;
	enterPlayerIndex = -1;
	counter = 0;
}

SceneMediateData SceneTitle::Update(){
	SceneMediateData sceneData	= SceneMediateData::Setup(SCENE_TITLE);
	if (enterPlayerIndex == -1){
		enterPlayerIndex = CheckControllPadNo();;
	}
	if (nextSceneCount<=0){
		sceneData.playerIndex	= enterPlayerIndex;
		sceneData.nextScene		= SCENE_GAMEMAIN;
	}
	CountdownNextScene();
	counter++;
	return sceneData;
}

void SceneTitle::Draw(){
	
	device->Image()->DrawBackGround(imageBackGround->GetImageHandle());
	DrawFlashPushXButton();
}

void SceneTitle::Finalize(){
	device->Sound()->Stop(Music_Title_BGM);
}

int SceneTitle::CheckControllPadNo(){
	for (int i = 0; i < USE_PAD_MAX; i++){
		if (device->Input()->GetInputState(i)->CheckKeyPush(GKey_Attack)){
			return i;
		}
	}
	return -1;
}

void SceneTitle::CountdownNextScene(){
	if (enterPlayerIndex == -1){ return; }
	if (nextSceneCount == 30){
		device->Sound()->Play(SE_Decision);
	}
	nextSceneCount--;
}

void SceneTitle::DrawFlashPushXButton(){
	if (nextSceneCount == 30 && counter % 90 < 45){ return; }
	if (nextSceneCount % 8 < 4){ return; }
	Vec2 posInfo = Vec2::Setup((float)Window::WIDTH / 2, 450);
	device->Image()->DrawCeter(imageAsset_Title_PushButton, posInfo);
}