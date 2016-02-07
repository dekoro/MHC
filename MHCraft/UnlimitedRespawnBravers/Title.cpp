#include "Title.h"


SceneTitle::SceneTitle(){
	device = DeviceManager::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_Title_BackGround);
	//	postEffect = std::make_shared<PostEffect>(&texMapEffect);//テスト
	this->screen = std::make_shared<ScreenLayout>(e_Single, &texMapEffect);
	SetCameraNearFar(1, 1000);

}

SceneTitle::~SceneTitle(){

}

void SceneTitle::Initialize(SceneMediateData sceneData){
	device->Sound()->Play(Music_Title_BGM);
	nextSceneCount = 30;
	enterPlayerIndex = -1;
	counter = 0;
	isEnd = false;
	//SetCameraPositionAndTarget_UpVecY(VGet(500,0, -50), VGet(0, 0, 0));

	//SetupCamera_Ortho(2000.0f);//２Ｄカメラ設定
}

SceneMediateData SceneTitle::Update(){
	SceneMediateData sceneData = SceneMediateData::Setup(SCENE_TITLE);
	if (enterPlayerIndex == -1){
		enterPlayerIndex = CheckControllPadNo();;
	}
	if (nextSceneCount <= 0){
		sceneData.playerIndex = enterPlayerIndex;
		sceneData.nextScene = SCENE_GAMEMAIN;
	}
	if (device->Input()->CheckKeyPushAllPad(GKey_Attack)) isEnd = true;
	if (isEnd)
	{
		CountdownNextScene();
	}
	counter++;
	return sceneData;

}

void SceneTitle::Draw(){

	screen->Rendaring([&](){LocalDraw(); });
	//LocalDraw();
}

void SceneTitle::LocalDraw()
{
	static int x = 0, y = 0;
	if (device->GetInstance()->Input()->CheckKeyDownAllPad(GKey_Up))
	{
		y += 1;
	}
	if (device->GetInstance()->Input()->CheckKeyDownAllPad(GKey_Down))
	{
		y -= 1;
	}
	if (device->GetInstance()->Input()->CheckKeyDownAllPad(GKey_Right))
	{
		x += 1;
	}
	if (device->GetInstance()->Input()->CheckKeyDownAllPad(GKey_Left))
	{
		x -= 1;
	}


	camera.SetPosition();

	device->Image()->DrawCeter(imageAsset_Title_BackGround, Vec2(x, y));
	//device->Image()->DrawBackGround(imageBackGround->GetImageHandle());
	//DrawGraph(0, 0, imageBackGround->GetImageHandle(), TRUE);
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