#include"SelectScene.h"
#include<DxLib.h>
#include"DeviceManager.h"
#include"InputManager.h"

SelectScene::SelectScene() :selecter(4)
{
	this->input = DeviceManager::GetInstance()->Input();
}

SelectScene::~SelectScene()
{
}

void SelectScene::Initialize(SceneMediateData sceneData)
{
	selecter.Initialize();
	this->isEnd = false;
	date = date.Setup(SCENE_SELECT,0);
}

SceneMediateData SelectScene::Update()
{
	selecter.Update();

	if (input->CheckKeyDownAllPad(GKey_Attack))
	{
		date.playerIndex = selecter.GetCurrentNum();

		isEnd = true;
	}

	if (isEnd)
	{
		date.nextScene = SCENE_GAMEMAIN;

	}

	return this->date;
}

void SelectScene::Draw()
{
	DrawFormatString(100, 100, GetColor(24, 255, 34), "%d", selecter.GetCurrentNum());
}

void SelectScene::Finalize()
{

}

