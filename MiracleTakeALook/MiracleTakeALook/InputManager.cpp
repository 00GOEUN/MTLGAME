#include "InputManager.h"

InputManager* InputManager::m_plnstance = NULL;


InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::CheckKey()
{
	m_ulKey = 0;

	if (GetAsyncKeyState(VK_LEFT)) // ����
	{
		m_ulKey |= KEYID_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT)) // ������
	{
		m_ulKey |= KEYID_RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE)) // ����
	{
		m_ulKey |= KEYID_SPACE;
	}

	if (GetAsyncKeyState('A')) // �⺻����
	{
		m_ulKey |= KEYID_AKEY;
	}
	if (GetAsyncKeyState('S')) // ��ų����
	{
		m_ulKey |= KEYID_SKEY;
	}
	if (GetAsyncKeyState(VK_UP)) // ��
	{
		m_ulKey |= KEYID_ENTER;
	}
	if (GetAsyncKeyState(VK_DOWN)) // �Ʒ�
	{
		m_ulKey |= KEYID_ENTER;
	}
	if (GetAsyncKeyState(VK_RETURN)) // ����
	{
		m_ulKey |= KEYID_ENTER;
	}
}