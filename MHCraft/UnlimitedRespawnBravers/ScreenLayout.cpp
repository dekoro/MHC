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

	for (auto s : Screens)
	{
		s->Initialize();
	}
}

void ScreenLayout::Rendaring(std::function<void()> Draw)
{
	for (int i = 0; i <= layOut; ++i)
	{
		this->Screens[(e_ScreenLayout)i]->Rendaring(Draw);
	}
}