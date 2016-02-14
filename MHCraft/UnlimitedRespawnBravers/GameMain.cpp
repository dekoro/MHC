#include "GameMain.h"

SceneGameMain::SceneGameMain(){
	device			= DeviceManager::GetInstance();
	managers		= Managers::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_GameMain_BackGround);
}

SceneGameMain::~SceneGameMain(){
}

void SceneGameMain::Initialize(SceneMediateData sceneData) {
	AllManagersInitialize();
	for (int i = 0; i < MAX_PLAYER; ++i) {
		managers->Player()->SpawnPlayer(i, Vec2::Setup(150, 150));
	}
}

SceneMediateData SceneGameMain::Update(){
	if (managers->Player()->GetJoinNum() <= 0) { return SceneMediateData::Setup(SCENE_TITLE); }
	managers->Player()->Update();
	managers->Enemy()->Update();
	return SceneMediateData::Setup(SCENE_NOCHANGE);
}

void SceneGameMain::Draw(){
	device->Image()->DrawBackGround(imageBackGround->GetImageHandle());
	AllManagersDraw();
}

void SceneGameMain::Finalize(){
	AllManagersFinalize();
}

//-----private-----

void SceneGameMain::AllManagersInitialize(){
	managers->Player()->Initialize();
	managers->Enemy()->Initialize();
	managers->Damage()->Initialize();
	managers->Item()->Initialize();

}

void SceneGameMain::AllManagersUpdate(){
	managers->Player()->Update();
	managers->Enemy()->Update();
	managers->Damage()->Update();
	managers->Item()->Update();
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
