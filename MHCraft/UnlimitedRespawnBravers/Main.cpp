
#include "SceneManager.h"
#include"ChildWindow.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cCmdShow){

	ChangeWindowMode(TRUE);	
	SetWindowText("UnlimitedRespawnBravers -o��- HALLOWEEN EDITION");
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);

	SetUseDirect3DVersion(DX_DIRECT3D_9EX);

	ChildWindow childWindow(TEXT("Map"), hInstance);

	childWindow.Initialize(cCmdShow);//�E�B���h�E�̏�����Dxint���ĂԑO�Ɏg��

	if (DxLib_Init() == -1){ return -1; }
	Debug::CheckDebugMode();
	DeviceManager*	deviceManager	= DeviceManager::GetInstance();
	SceneManager*	sceneManager	= new SceneManager();
	FPS*			fps				= new FPS();
	MSG msg;
	
	SetAlwaysRunFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
//	SetScreenFlipTargetWindow(childWindow.GetHWnd());//�`�����q�E�B���h�E�ɂ���

	//SetScreenFlipTargetWindow(NULL);

	int a = 0;

	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		///��������X�V
		deviceManager->Input()->Update();
		deviceManager->Image()->Update();
		sceneManager->Update();
		///�����܂ōX�V

		DrawFillBox(0, 0, 1280, 720, GetColor(32, 32, 32));

		///��������`��
		a++;
		if (a % 2 == 0)
		{
			SetScreenFlipTargetWindow(childWindow.GetHWnd());//�`�����q�E�B���h�E�ɂ���
		}
		else
		{
			SetScreenFlipTargetWindow(NULL);//�`�����q�E�B���h�E�ɂ���
		}
		sceneManager->Draw();

		///�����܂ŕ`��
	//	fps->SleepNextFrame();
		//Debug::ClearPrint();
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			if (MessageBox(NULL, TEXT("�I�������܂���?"),TEXT(""), MB_YESNO | MB_ICONQUESTION) == IDYES)
				break;
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