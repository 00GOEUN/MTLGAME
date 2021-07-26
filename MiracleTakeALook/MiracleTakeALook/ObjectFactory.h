#pragma once
#include "Object.h"

template <typename T>
class ObjectFactory
{
public:
	// x, y ���� ���� ��
	static Object* CreateObject()
	{
		Object* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	// x, y ���� ������ ��
	static Object* CreateObject(float _x, float _y)
	{
		// �� T�� ����� Initialize�� �ҷ���
		Object* pObj = new T;
		pObj->Initialize();

		// x, y ���� �ѱ�
		pObj->SetPosition(_x, _y);

		return pObj;
	}
};


