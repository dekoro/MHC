#include"ScreenLayout.h"


ScreenLayout::ScreenLayout(e_ScreenLayout layOut, BaseEffect* effect) :layOut(layOut)
{
	switch (layOut)
	{
	case e_Single:
		this->Screens.push_back(std::make_shared<PostEffect>(effect,layOut,e_First));
		break;
	case e_Double:
		for (int i = 0; i <= e_Double; ++i)
		{
			this->Screens.push_back(std::make_shared<PostEffect>(effect, layOut, (e_ScreenNumber)i));
		}
		break;
	case e_Triple:
		for (int i = 0; i <= e_Triple; ++i)
		{
			this->Screens.push_back(std::make_shared<PostEffect>(effect, layOut, (e_ScreenNumber)i));
		}
		break;
	case e_Quad:
		for (int i = 0; i <= e_Quad; ++i)
		{
			this->Screens.push_back(std::make_shared<PostEffect>(effect, layOut, (e_ScreenNumber)i));
		}
		break;
	default:
		break;
	}

}

ScreenLayout::~ScreenLayout()
{
}

void ScreenLayout::Rendaring(std::function<void()> Draw)
{
	for (int i = 0; i <= layOut; ++i)
	{
		this->Screens[(e_ScreenLayout)i]->Rendaring(Draw);
	}
}