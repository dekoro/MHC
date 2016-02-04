#include"ChildWindow.h"
#include<assert.h>

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
	assert(!erorr &&"ウィンドウクラスの登録に失敗しました");
}

ChildWindow::~ChildWindow()
{
}

void ChildWindow::Initialize(int cmdShow)
{
	this->hWnd = CreateWindow(
		wc.lpszClassName,
		TEXT("Map"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		wc.hInstance,
		NULL
		);
	ShowWindow(this->hWnd, cmdShow);
	UpdateWindow(hWnd);
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
		if (MessageBox(NULL, TEXT("終了させますか?"), TEXT(""), MB_YESNO | MB_ICONQUESTION) == IDYES)
			PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);;
	}

}