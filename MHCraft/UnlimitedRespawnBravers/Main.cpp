
#include "SceneManager.h"
#include"ChildWindow.h"

#include<time.h>
#include<assert.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cCmdShow){
	bool windowMode = TRUE;
	ChangeWindowMode(windowMode);
	SetWindowText("UnlimitedRespawnBravers -oα- HALLOWEEN EDITION");
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);

	SetUseDirect3DVersion(DX_DIRECT3D_9EX);

	ChildWindow childWindow(TEXT("Map"), hInstance);

	//childWindow.Initialize(cCmdShow);//ウィンドウの初期化Dxintを呼ぶ前に使う

	if (DxLib_Init() == -1){ return -1; }
	Debug::CheckDebugMode();
	DeviceManager*	deviceManager = DeviceManager::GetInstance();
	SceneManager*	sceneManager = new SceneManager();
	FPS*			fps = new FPS();
	MSG msg;

	SetAlwaysRunFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	//SetScreenFlipTargetWindow(childWindow.GetHWnd());//描画先を子ウィンドウにする

	//SetScreenFlipTargetWindow(NULL);

	int a = 0;


	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		///ここから更新

		clock_t strt = clock();//スタート

		deviceManager->Input()->Update();
		deviceManager->Image()->Update();
		sceneManager->Update();
		///ここまで更新

		DrawFillBox(0, 0, 1280, 720, GetColor(32, 32, 32));

		//ここから描画
		//	a++;
		//	if (a % 2 == 0)
		//{
		//			SetScreenFlipTargetWindow(childWindow.GetHWnd());//描画先を子ウィンドウにする
		//}
		//	else
		//{
		//			SetScreenFlipTargetWindow(NULL);//描画先を親ウィンドウにする
		//}
		sceneManager->Draw();

		clock_t end = clock();//終わりの時間

		double a = end - strt;

		assert(a < 200 && "すごい時間かかってる");

		///ここまで描画
		//	fps->SleepNextFrame();
		//Debug::ClearPrint();
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			if (windowMode)
			{
				if (MessageBox(NULL, TEXT("終了させますか?"), TEXT(""), MB_YESNO | MB_ICONQUESTION) == IDYES)
				{
					break;
				}
			}
			//else
			//{
			//	windowMode = TRUE;
			//	ChangeWindowMode(TRUE);
			//}
		}

		if (PeekMessage(&msg, childWindow.GetHWnd(), 0, 0, PM_NOREMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	SAFE_DELETE(sceneManager);
	SAFE_DELETE(fps);
	DxLib_End();
	return 0;
}