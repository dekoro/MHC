
#include "SceneManager.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cCmdShow){

	ChangeWindowMode(TRUE);	
	SetWindowText("UnlimitedRespawnBravers -o��- HALLOWEEN EDITION");
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);

	if (DxLib_Init() == -1){ return -1; }
	Debug::CheckDebugMode();
	DeviceManager*	deviceManager	= DeviceManager::GetInstance();
	SceneManager*	sceneManager	= new SceneManager();
	FPS*			fps				= new FPS();

	SetAlwaysRunFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);

	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		///��������X�V
		deviceManager->Input()->Update();
		deviceManager->Image()->Update();
		sceneManager->Update();
		///�����܂ōX�V

		DrawFillBox(0, 0, 1280, 720, GetColor(32, 32, 32));

		///��������`��
		sceneManager->Draw();

		///�����܂ŕ`��
	//	fps->SleepNextFrame();
		//Debug::ClearPrint();
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			if (MessageBox(NULL, TEXT("�I�������܂���?"),TEXT(""), MB_YESNO | MB_ICONQUESTION) == IDYES)
				break;
		}
	}

	SAFE_DELETE(sceneManager);
	SAFE_DELETE(fps);
	DxLib_End();
	return 0;
}