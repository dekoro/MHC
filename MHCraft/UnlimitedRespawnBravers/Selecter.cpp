#include"Selecter.h"
#include"DeviceManager.h"
#include"InputManager.h"

Selecter::Selecter(int maxNum)
{
	this->m_MaxNum = maxNum;
	this->input = DeviceManager::GetInstance()->Input();
}


Selecter::~Selecter()
{
}

void Selecter::Initialize()
{
	this->m_CurrentNum = 0;
}

void Selecter::Update()
{
	if (input->CheckKeyPushAllPad(GKey_Down))
	{
		this->m_CurrentNum = ++m_CurrentNum % m_MaxNum;
	}

	if (input->CheckKeyPushAllPad(GKey_Up))
	{
		this->m_CurrentNum = (m_CurrentNum + (m_MaxNum - 1)) % m_MaxNum;
	}
}

int Selecter::GetCurrentNum()
{
	return m_CurrentNum;
}