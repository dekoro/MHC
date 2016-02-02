
#include "SceneManager.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cCmdShow){

	ChangeWindowMode(TRUE);	
	SetWindowText("UnlimitedRespawnBravers -oƒ¿- HALLOWEEN EDITION");
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);

	if (DxLib_Init() == -1){ return -1; }
	Debug::CheckDebugMode();
	DeviceManager*	deviceManager	= DeviceManager::GetInstance();
	SceneManager*	sceneManager	= new SceneManager();
	FPS*			fps				= new FPS();
	SetDrawScreen(DX_SCREEN_BACK);


	while (true){
		if (ProcessMessage() == -1){ break; }
		///‚±‚±‚©‚çXV
		deviceManager->Input()->Update();
		deviceManager->Image()->Update();
		sceneManager->Update();
		///‚±‚±‚Ü‚ÅXV

		ClearDrawScreen();
		DrawFillBox(0, 0, 1280, 720, GetColor(32, 32, 32));

		///‚±‚±‚©‚ç•`‰æ
		sceneManager->Draw();

		///‚±‚±‚Ü‚Å•`‰æ
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