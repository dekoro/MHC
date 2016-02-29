#include"ScreenLayout.h"
#include"PlayerManager.h"


ScreenLayout::ScreenLayout(e_ScreenLayout layOut) :layOut(layOut)
{

}

ScreenLayout::~ScreenLayout()
{
}

void ScreenLayout::Initialize(PlayerManager* players)
{
	switch (layOut)
	{
	case e_Single:
		this->Screens.push_back(std::make_shared<PostEffect>(players->GetPlayerData(0)));
		break;
	case e_Double:
		for (int i = 0; i <= e_Double; ++i)
		{
			this->Screens.push_back(std::make_shared<PostEffect>(players->GetPlayerData(i), layOut, (e_ScreenNumber)i));
		}
		break;
	case e_Triple:
		for (int i = 0; i <= e_Triple; ++i)
		{
			this->Screens.push_back(std::make_shared<PostEffect>(players->GetPlayerData(i), layOut, (e_ScreenNumber)i));
		}
		break;
	case e_Quad:
		for (int i = 0; i <= e_Quad; ++i)
		{
			this->Screens.push_back(std::make_shared<PostEffect>(players->GetPlayerData(i), layOut, (e_ScreenNumber)i));
		}
		break;
	default:
		break;
	}

	this->screenNum = layOut;

	for (auto s : Screens)
	{
		s->Initialize();
	}
}

void ScreenLayout::SetUseBlurConst(Vec2 direction, float shift, e_ScreenNumber screenNum)
{
	ChangeToScreenShader("Blur", screenNum);
	Screens[screenNum]->SetUseBlurConst(direction,shift);
}

void ScreenLayout::SetUseTexMapConst(bool b, e_ScreenNumber screenNum)
{
	ChangeToScreenShader("Normal", screenNum);
	Screens[screenNum]->SetUseTexMapConst(b);
}

void ScreenLayout::ZoomStart (e_ScreenNumber screenNum)
{
	ChangeToScreenShader("Zoom", screenNum);
	Screens[screenNum]->ZoomStart();
}


void ScreenLayout::Rendaring(std::function<void()> Draw)
{
	for (int i = 0; i <= layOut; ++i)
	{
		this->Screens[i]->Rendaring(Draw);
	}
}

void ScreenLayout::ChangeToScreenShader(std::string name, e_ScreenNumber screenNum)
{
	this->Screens[screenNum]->ChangeShader(name);
}

int ScreenLayout::GetScreenNum()
{
	return screenNum + 1;
}