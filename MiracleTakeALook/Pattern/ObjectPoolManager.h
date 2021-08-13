#pragma once
#include "Headers.h"

class Object;
class ObjectPoolManager
{
private:
	int Key;
	Transform TransInfo;

private:
	static ObjectPoolManager* Instance;
public:
	static ObjectPoolManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectPoolManager;
		return Instance;
	}
private:
	//** ���� ����� ������Ʈ (������ �� ������Ʈ ����Ʈ)
	list<Object*> EnableList;

	//** ����� ��ģ ������Ʈ ����Ʈ (������ ���� ����)
	list<Object*> DesableList;
public:
	void Intialize();
	void Output(float _x, float _y, string _str);
	
public:
	ObjectPoolManager();
	~ObjectPoolManager();
};