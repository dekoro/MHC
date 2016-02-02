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
	SceneMediateData nextScene;
	nextScene = AllManagersUpdate();
	return nextScene;
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
	managers->Player()->Initialize(startPlayerIndex);
	managers->Enemy()->Initialize();
	managers->Damage()->Initialize();
	managers->Item()->Initialize();

}

SceneMediateData SceneGameMain::AllManagersUpdate(){
	managers->Player()->Update();
	SceneMediateData nextScene = managers->Enemy()->Update();
	managers->Damage()->Update();
	managers->Item()->Update();

	return nextScene;
}

void SceneGameMain::AllManagersDraw(){
	managers->Damage()->Draw();
	managers->Item()->Draw();
	managers->Player()->Draw();
	managers->Enemy()->Draw();
}

void SceneGameMain::AllManagersFinalize(){
	managers->Player()->Finalize();
	managers->Enemy()->Finalize();
	managers->Damage()->Finalize();
	managers->Item()->Finalize();
}
