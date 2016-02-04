#include "Title.h"


SceneTitle::SceneTitle(){
	device = DeviceManager::GetInstance();
	imageBackGround = device->Image()->CopyImageData(imageAsset_Title_BackGround);
	postEffect = std::make_shared<PostEffect>(MakeScreen(Window::WIDTH, Window::HEIGHT), &texMapEffect);//ÉeÉXÉg
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

	SetupCamera_Ortho(2000.0f);//ÇQÇcÉJÉÅÉâê›íË
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

	static int g = 100, h = 100;

	//postEffect->Rendaring([&](){

	SetupCamera_Ortho(2000.0f);//ÇQÇcÉJÉÅÉâê›íË

	camera.SetPosition();

	int x;

	GetGraphSize(a, &x, nullptr);

	if (device->Input()->CheckKeyDownAllPad(GKey_Up))
	{
		h += 1;
	}

	DrawBillboard3D(VGet(h, h, 0), 0.5f, 0.5f, x *3, 0.0f, a, TRUE);

	device->Image()->DrawCeter(imageAsset_Title_BackGround, Vec2(h,h));
	//device->Image()->DrawBackGround(imageBackGround->GetImageHandle());
	DrawFlashPushXButton();
	//	});

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