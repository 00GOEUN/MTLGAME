#pragma once
#include "Headers.h"

class InputManager
{
private:
	static InputManager* m_plnstance;
public:
	static InputManager* GetInstance()
	{
		if (m_plnstance == NULL)
			m_plnstance = new InputManager;
		return m_plnstance;
	}
private:
	ULONG m_ulKey;
public:
	ULONG GetKey() const { return m_ulKey; }
	void CheckKey();
private:
	InputManager();
public:
	~InputManager();

};

