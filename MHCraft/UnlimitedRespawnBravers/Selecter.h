#ifndef SELECTER
#define SELECTER

class InputManager;

class Selecter
{
public:
	Selecter(int maxNum);
	~Selecter();

	void Initialize();

	void Update();

	int GetCurrentNum();

private:
	int m_CurrentNum;
	int m_MaxNum;
	InputManager* input;
};



#endif