
#include "SceneManager.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cCmdShow){

	ChangeWindowMode(TRUE);	
	SetWindowText("UnlimitedRespawnBravers -oα- HALLOWEEN EDITION");
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);

	if (DxLib_Init() == -1){ return -1; }
	Debug::CheckDebugMode();
	DeviceManager*	deviceManager	= DeviceManager::GetInstance();
	SceneManager*	sceneManager	= new SceneManager();
	FPS*			fps				= new FPS();
	SetDrawScreen(DX_SCREEN_BACK);


	while (true){
		if (ProcessMessage() == -1){ break; }
		///ここから更新
		deviceManager->Input()->Update();
		deviceManager->Image()->Update();
		sceneManager->Update();
		///ここまで更新

		ClearDrawScreen();
		DrawFillBox(0, 0, 1280, 720, GetColor(32, 32, 32));

		///ここから描画
		sceneManager->Draw();

		///ここまで描画
	//	fps->SleepNextFrame();
	//	Debug::ClearPrint();
		ScreenFlip();
		if (CheckHitKey(KEY_INPUT_ESCAPE)){ break; }
	}

	SAFE_DELETE(sceneManager);
	SAFE_DELETE(fps);
	DxLib_End();
	return 0;
}