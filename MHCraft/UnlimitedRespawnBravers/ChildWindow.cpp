#include"ChildWindow.h"
#include<assert.h>
#include<DxLib.h>
#include"GSystem.h"

ChildWindow::ChildWindow(PSTR className, HINSTANCE hInst)
{
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = this->WindProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInst;
	wc.hIcon = NULL;
	wc.hCursor = NULL;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = className;
	bool erorr = RegisterClass(&this->wc) == FALSE;
	assert(!erorr &&"�E�B���h�E�N���X�̓o�^�Ɏ��s���܂���");
}

ChildWindow::~ChildWindow()
{
}

//��Ŗ��O���N���G�C�g�E�B���h�E�ɕύX
void ChildWindow::Initialize(int cmdShow)
{
	HWND tenpWnd = CreateWindow(
		wc.lpszClassName,
		TEXT("Map"),
		WS_OVERLAPPED | WS_SYSMENU,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		wc.hInstance,
		NULL
		);

	RECT wRect, cRect;//�E�B���h�E�S�̂̋�`
	int wx, wy;//�E�B���h�E�S��XY
	int cx, cy;//�N���C�A���g�w�x

	GetWindowRect(tenpWnd, &wRect);//�E�B���h�E�S�̂̑傫��
	wx = wRect.right - wRect.left;
	wy = wRect.bottom - wRect.top;

	GetClientRect(tenpWnd, &cRect);
	cx = cRect.right - cRect.left;
	cy = cRect.bottom - cRect.top;

	wx -= cx;
	wy -= cy;

	this->hWnd = CreateWindow(
		wc.lpszClassName,
		TEXT("Map"),
		WS_OVERLAPPED | WS_SYSMENU,
		0,
		0,
		Window::WIDTH + wx,
		Window::HEIGHT+ wy,
		NULL,
		NULL,
		wc.hInstance,
		NULL
		);
	GetWindowRect(hWnd, &wRect);//

	ShowWindow(this->hWnd, cmdShow);
	UpdateWindow(hWnd);

	int a = SetUserChildWindow(hWnd);
}

HWND ChildWindow::GetHWnd()
{
	return this->hWnd;
}

HRESULT ChildWindow::WindProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		if (MessageBox(NULL, TEXT("�I�������܂���?"), TEXT(""), MB_YESNO | MB_ICONQUESTION) == IDYES)
			PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);;
	}


}