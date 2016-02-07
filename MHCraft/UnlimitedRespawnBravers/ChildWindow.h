#ifndef CHILD_WINDOW
#define CHILD_WINDOW
#include<Windows.h>

class ChildWindow
{
public:
	ChildWindow(PSTR  className, HINSTANCE hInst);
	~ChildWindow();

	void Initialize(int cmdShow);

	static HRESULT CALLBACK WindProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);

	void Draw();

	HWND GetHWnd();

private:
	WNDCLASS wc;
	HWND hWnd;


};


#endif