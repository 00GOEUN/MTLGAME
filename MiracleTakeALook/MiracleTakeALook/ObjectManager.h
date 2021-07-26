#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	int Pick;
	int BoxMax; // 박스 수
	static ObjectManager* m_pInstance;
public:
	static ObjectManager* GetInstance()
	{
		// m_pInstance가 없을 때 새 오브젝트매니저를 만들고 리턴
		if (m_pInstance == NULL)
			m_pInstance = new ObjectManager;
		return m_pInstance;
	}
private:
	int pEnemyID;
	Object* pPlayer; // 플레이어
	Object* ObjectList[OBJID_MAX][128];  // 오브젝트리스트[2][128] : 2차원 배열로 생성
	int EnemyCount; //몬스터 수
	Object* BoxList[8];

public:
	Object* GetPlayer() const { return pPlayer; } // 플레이어
	void SetPick(const int& _pPick){ Pick = _pPick;}
	void SetPlayer(Object* _pPlayer) { pPlayer = _pPlayer; } // 입력을 받아오면 player 함수에 넣을 것

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
	void CreateEnemy(); // 몬스터 생성
private:
	ObjectManager();
public:
	~ObjectManager();
};

