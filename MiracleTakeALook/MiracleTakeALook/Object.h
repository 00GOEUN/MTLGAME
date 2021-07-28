#pragma once
#include "Headers.h"
class Object
{
protected:
	int Hp;
	int Damage;

	int EnemyNum; // Enemy �迭 ����
	int Horizontal; // �����̴� ����


	Transform TransInfo;
	string strKey;

	char* Texture[3][13]; // 12��ŭ �迭�� �����ϴµ� �� 12��??
	bool Active; // �̰� ����? Ȱ��?
	string m_strKey;
	int m_KeyCode;
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public: //  ����!!! ���ı�!!! ����!!!!!!! �𸣰ڴٰ�!!!
	Transform GetTransform() const { return TransInfo; }

	Vector3 GetPosition() const { return TransInfo.Position; }
	void SetPosition(const float& _x, const float& _y) { TransInfo.Position.x = _x; TransInfo.Position.y = _y; }

	Vector3 GetScale() const { return TransInfo.Scale; }

	bool GetActive() const { return Active; }
	void SetActive(const bool& _Active) { Active = _Active; }


	string GetKey() { return m_strKey; }
	void SetKey(const bool& _strKey) { m_strKey = _strKey; }


	int GetKeyCode() const { return m_KeyCode; }
	void SetKeyCode(const bool& _KeyCode) { m_KeyCode = _KeyCode; }

	void SetEnemyNum(const int& _EnemyNum) { EnemyNum = _EnemyNum;  }

	int GetHorizontal() const { return Horizontal; }
	void SetHorizontal(const int& _Horizontal) { Horizontal = _Horizontal; }
public:
	Object();
	virtual ~Object();
}; 

