#include "UI.h"

UIData UIData::Setup(Vec2 position, int size, string text, int color, bool isDisp){
	UIData tmp;
	tmp.position	= position;
	tmp.size		= size;
	tmp.text		= text;
	tmp.color		= color;
	tmp.isDisp		= isDisp;
	return tmp;
}

bool UIData::operator==(UIData other){
	return(	position	== other.position
		&&	size		== other.size
		&&	text		== other.text
		&&	color		== other.color
		&&	isDisp		== other.isDisp);
}

bool UIData::operator!=(UIData other){
	return(	position	!= other.position
		||	size		!= other.size
		||	text		!= other.text
		||	color		!= other.color
		||	isDisp		!= other.isDisp);
}

UIData UIData::NoData(){
	return UIData::Setup(Vec2::Zero(), 0, "");
}


UI* UI::instance = NULL;

UI::UI(){
	ClearUI();
}

UI::~UI(){
	SAFE_DELETE(instance);
}

UI*	 UI::GetInstance(){
	if (instance == NULL){ instance = new UI(); }
	return instance;
}

void UI::Draw(){
	for (int i = 0; i < UI_MAX; i++){
		if (uiList[i] == UIData::NoData()){ continue; }
		if (!uiList[i].isDisp){ continue; }
		DrawString(uiList[i].position.GetIntX()
				 , uiList[i].position.GetIntY()
				 , uiList[i].text.c_str()
				 , uiList[i].color
				 );
	}
	ClearUI();
}

void UI::AddUI(UIData uiData){
	for (int i = 0; i < UI_MAX; i++){
		if (uiList[i] != UIData::NoData()){ continue; }
		uiList[i] = uiData;
		return;
	}
}

void UI::ClearUI(){
	for (int i = 0; i < UI_MAX; i++){
		uiList[i] = UIData::NoData();
	}
}

















