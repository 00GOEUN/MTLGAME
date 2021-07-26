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

	if (GetAsyncKeyState(VK_LEFT)) // 왼쪽
	{
		m_ulKey |= KEYID_LEFT;
	}
	if (GetAsyncKeyState(VK_RIGHT)) // 오른쪽
	{
		m_ulKey |= KEYID_RIGHT;
	}
	if (GetAsyncKeyState(VK_SPACE)) // 점프
	{
		m_ulKey |= KEYID_SPACE;
	}

	if (GetAsyncKeyState('A')) // 기본공격
	{
		m_ulKey |= KEYID_AKEY;
	}
	if (GetAsyncKeyState('S')) // 스킬공격
	{
		m_ulKey |= KEYID_SKEY;
	}
	if (GetAsyncKeyState(VK_UP)) // 위
	{
		m_ulKey |= KEYID_ENTER;
	}
	if (GetAsyncKeyState(VK_DOWN)) // 아래
	{
		m_ulKey |= KEYID_ENTER;
	}
	if (GetAsyncKeyState(VK_RETURN)) // 선택
	{
		m_ulKey |= KEYID_ENTER;
	}
}