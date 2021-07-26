#pragma once
#include "Object.h"

template <typename T>
class ObjectFactory
{
public:
	// x, y 값이 없을 때
	static Object* CreateObject()
	{
		Object* pObj = new T;
		pObj->Initialize();

		return pObj;
	}

	// x, y 값이 들어왔을 때
	static Object* CreateObject(float _x, float _y)
	{
		// 새 T를 만들고 Initialize를 불러옴
		Object* pObj = new T;
		pObj->Initialize();

		// x, y 값을 넘김
		pObj->SetPosition(_x, _y);

		return pObj;
	}
};


