
#include "SceneManager.h"
#include"ChildWindow.h"

#include<time.h>
#include<assert.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int cCmdShow){
	bool windowMode = TRUE;
	ChangeWindowMode(windowMode);
	SetWindowText("UnlimitedRespawnBravers -o��- HALLOWEEN EDITION");
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);

	SetUseDirect3DVersion(DX_DIRECT3D_9EX);

	ChildWindow childWindow(TEXT("Map"), hInstance);

	//childWindow.Initialize(cCmdShow);//�E�B���h�E�̏�����Dxint���ĂԑO�Ɏg��

	if (DxLib_Init() == -1){ return -1; }
	Debug::CheckDebugMode();
	DeviceManager*	deviceManager = DeviceManager::GetInstance();
	SceneManager*	sceneManager = new SceneManager();
	FPS*			fps = new FPS();
	MSG msg;

	SetAlwaysRunFlag(TRUE);
	SetDrawScreen(DX_SCREEN_BACK);
	//SetScreenFlipTargetWindow(childWindow.GetHWnd());//�`�����q�E�B���h�E�ɂ���

	//SetScreenFlipTargetWindow(NULL);

	int a = 0;


	while (!ProcessMessage() && !ScreenFlip() && !ClearDrawScreen()){
		///��������X�V

		clock_t strt = clock();//�X�^�[�g

		deviceManager->Input()->Update();
		deviceManager->Image()->Update();
		sceneManager->Update();
		///�����܂ōX�V

		DrawFillBox(0, 0, 1280, 720, GetColor(32, 32, 32));

		//��������`��
		//	a++;
		//	if (a % 2 == 0)
		//{
		//			SetScreenFlipTargetWindow(childWindow.GetHWnd());//�`�����q�E�B���h�E�ɂ���
		//}
		//	else
		//{
		//			SetScreenFlipTargetWindow(NULL);//�`����e�E�B���h�E�ɂ���
		//}
		sceneManager->Draw();

		clock_t end = clock();//�I���̎���

		double a = end - strt;

		assert(a < 200 && "���������Ԃ������Ă�");

		///�����܂ŕ`��
		//	fps->SleepNextFrame();
		//Debug::ClearPrint();
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			if (windowMode)
			{
				if (MessageBox(NULL, TEXT("�I�������܂���?"), TEXT(""), MB_YESNO | MB_ICONQUESTION) == IDYES)
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