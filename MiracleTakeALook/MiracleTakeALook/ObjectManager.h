#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	int Pick;
	int BoxMax; // �ڽ� ��
	static ObjectManager* m_pInstance;
public:
	static ObjectManager* GetInstance()
	{
		// m_pInstance�� ���� �� �� ������Ʈ�Ŵ����� ����� ����
		if (m_pInstance == NULL)
			m_pInstance = new ObjectManager;
		return m_pInstance;
	}
private:
	int pEnemyID;
	Object* pPlayer; // �÷��̾�
	Object* ObjectList[OBJID_MAX][128];  // ������Ʈ����Ʈ[2][128] : 2���� �迭�� ����
	int EnemyCount; //���� ��
	Object* BoxList[8];

public:
	Object* GetPlayer() const { return pPlayer; } // �÷��̾�
	void SetPick(const int& _pPick){ Pick = _pPick;}
	void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; } // �Է��� �޾ƿ��� player �Լ��� ���� ��

	int GetEnemyID() const { return pEnemyID; }
	void SetEnemyID(const int& _pEnemyID) { pEnemyID = _pEnemyID; }

	void AddObject(Object* _pObject);

public:
	void Initialize();
	void Update();
	void Render();
	void Release();
public:
	void FureBullet();
	void FureBullet2();
	void CreateEnemy(); // ���� ����
private:
	ObjectManager();
public:
	~ObjectManager();
};

