#ifndef _GSYSTEM_UI_H_
#define _GSYSTEM_UI_H_

#include "SystemHub.h"
#include "Vec2.h"
#include "Macro.h"

#define UI_MAX 64

class UIData
{
public:
	UIData(){}
	~UIData(){}

	std::string	text;
	Vec2	position;
	int		size;
	int		color;
	bool	isDisp;
	static	UIData Setup(Vec2 position, int size, std::string text, int color = -1, bool isDisp = true);
	static	UIData NoData();

	bool operator==(UIData other);
	bool operator!=(UIData other);
private:

};
class UI
{
public:
	~UI();

	static UI*	GetInstance();
	void		Draw();
	void		AddUI(UIData uiData);

private:
	static UI* instance;
	UIData uiList[UI_MAX];

	UI();
	void		ClearUI();

};
#endif



