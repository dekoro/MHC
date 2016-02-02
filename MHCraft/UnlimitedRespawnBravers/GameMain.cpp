#include "GameMain.h"

SceneGameMain::SceneGameMain(){
	device			= DeviceManager::GetInstance();
	managers		= Managers::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_GameMain_BackGround);
}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData){
	AllManagersInitialize(sceneData.playerIndex);
}

SceneMediateData SceneGameMain::Update(){
	//SceneMediateData nextScene;
	//nextScene = AllManagersUpdate();
	//Ç∆ÇËÇ‹ÉVÅ[ÉìêÿÇËë÷Ç¶ÇµÇ»Ç¢ÇÊÇ§Ç…å≈íË
	SceneMediateData a;
	a.nextScene = SCENE_GAMEMAIN;
	a.playerIndex = 0;
	return a;
}

void SceneGameMain::Draw(){
	device->Image()->DrawBackGround(imageBackGround->GetImageHandle());
	AllManagersDraw();
}

void SceneGameMain::Finalize(){
	AllManagersFinalize();
}

//-----private-----

void SceneGameMain::AllManagersInitialize(int startPlayerIndex){


}

SceneMediateData SceneGameMain::AllManagersUpdate(){
	//ìKìñÇ…èëÇ¢ÇΩ
	SceneMediateData a;
	a.nextScene = SCENE_GAMEMAIN;
	a.playerIndex = 0;


	return a;
}

void SceneGameMain::AllManagersDraw(){
	DrawBox(0,0,100,100,GetColor(255,100,255),FALSE);
}

void SceneGameMain::AllManagersFinalize(){

}
