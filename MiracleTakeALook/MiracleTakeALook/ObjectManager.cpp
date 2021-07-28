#include "ObjectManager.h"
#include "ObjectFactory.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "Pig.h"
#include "Rabbit.h"
#include "Dog.h"
#include "Bullet.h"
#include "SkillBullet.h"
#include "Stage1Box1.h"
#include "Stage1Box2.h"
#include "Stage1Box3.h"
#include "Stage2Box1.h"
#include "Stage2Box2.h"
#include "Stage2Box3.h"
#include "Stage2Box4.h"
#include "Stage2Box5.h"

#include "Floor.h"
#include "Player.h"


ObjectManager* ObjectManager::m_pInstance = NULL;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}
void ObjectManager::AddObject(Object* _pObject)
{
	//** 지금 전달받은 매개변수의 키값을 확인한다.
	//** 만약 기존에 키값이 존재 하지 않는다면 end() 를 반환 함.
	map<string, list<Object*>>::iterator iter = ObjectList.find(_pObject->m_strKey());

	//** iter가 ObjectList.end()와 같다면 기존에 키값이 존재하지 않음.
	//** 만약 존재하지 않는다면....
	if (iter == ObjectList.end())
	{
		//** map에 넣을 리스트를 생성.
		list<Object*> TempList;

		//** 생성한 리스트에 전달받은 오브젝트를 추가.
		TempList.push_back(_pObject);

		//** 오브젝트를 추가한 리스트를 오브젝트의 키값으로 map에 추가. 
		ObjectList.insert(make_pair(_pObject->m_strKey(), TempList));
	}

	//** 만약 기존에 동일한 키값이 존재 한다면....
	else
		//** 동일한 키값에 있는 리스트에 바로 추가해준다.
		iter->second.push_back(_pObject);
}

void ObjectManager::Initialize()
{
	BoxList[0] = new Floor;
	BoxList[0]->Initialize();
	switch (pEnemyID)
	{
	case ENEMYID_PIG:
		BoxList[1] = new Stage1Box1;
		BoxList[1]->Initialize();
		BoxList[2] = new Stage1Box2;
		BoxList[2]->Initialize();
		BoxList[3] = new Stage1Box3;
		BoxList[3]->Initialize();
		BoxMax = 4;
		//for (int i = 0; i < 128; i++)
		//	ObjectList[OBJID_ENEMY][i] = ObjectFactory<Pig>::CreateObject();
		for (int i = 0; i < 4; i++)
			ObjectManager::GetInstance()->AddObject(
				ObjectFactory<Bullet>::CreateObject());

		break;
	case ENEMYID_RABBIT:
		BoxList[1] = new Stage2Box1;
		BoxList[1]->Initialize();
		BoxList[2] = new Stage2Box2;
		BoxList[2]->Initialize();
		BoxList[3] = new Stage2Box3;
		BoxList[3]->Initialize();
		BoxList[4] = new Stage2Box4;
		BoxList[4]->Initialize();
		BoxList[5] = new Stage2Box5;
		BoxList[5]->Initialize();
		BoxMax = 6;
		//for (int i = 0; i < 128; i++)
		//	ObjectList[OBJID_ENEMY][i] = ObjectFactory<Rabbit>::CreateObject();
		for (int i = 0; i < 5; i++)
			ObjectManager::GetInstance()->AddObject(
				ObjectFactory<Rabbit>::CreateObject());
		break;
	case ENEMYID_DOG:
		BoxMax = 1;
		//for (int i = 0; i < 128; i++)
		//	ObjectList[OBJID_ENEMY][i] = ObjectFactory<Dog>::CreateObject();
		break;
	}


	// 128 만큼 x, y 값을 넣어줌
	for (int i = 0; i < 128; i++)
	{
		//ObjectList[OBJID_ENEMY][i] = ObjectFactory<Pig>::CreateObject();
		//ObjectList[OBJID_ENEMY][i] = ObjectFactory<Rabbit>::CreateObject();
		//ObjectList[OBJID_ENEMY][i] = ObjectFactory<Dog>::CreateObject();
		//ObjectList[OBJID_BULLET][i] = ObjectFactory<Bullet>::CreateObject();
		//ObjectList[OBJID_SKBULLET][i] = ObjectFactory<SkillBullet>::CreateObject();
		//AddObject(ObjectFactory<Bullet>::CreateObject());
		//AddObject(ObjectFactory<SkillBullet>::CreateObject());
		ObjectManager::GetInstance()->AddObject(
			ObjectFactory<Bullet>::CreateObject());
		ObjectManager::GetInstance()->AddObject(
			ObjectFactory<SkillBullet>::CreateObject());
	}



	EnemyCount = 0; // 몬스터 수 0 초기화
}

void ObjectManager::Update()
{
	//// 몬스터 수가 0이면 몬스터 생성 // 다음 스테이지로 가게 변경해야함ㅎㅎ
	//if (EnemyCount <= 0)
	//	SceneManager::GetInstance()->SetScene(SCENEID_WIN);
	//
	//	// CreateEnemy();


	

	//** 라인 충돌
	for (int i = 0; i < BoxMax; i++)
	{
		if (((Player*)pPlayer)->GetJumpDown())
		{
			if (CollisionManager::CollisionLine(pPlayer->GetTransform(), BoxList[i]->GetTransform()))
			{
				if ( (pPlayer->GetPosition().y + pPlayer->GetScale().y) >= BoxList[i]->GetPosition().y)
				{
					if (BoxList[i]->GetKey() == "Ground")
					{
						pPlayer->SetPosition(
							pPlayer->GetPosition().x,
							(BoxList[i]->GetPosition().y - pPlayer->GetScale().y - 1));
						((Player*)pPlayer)->SetJump(false);
					}
				}
			}
			else
			{
				((Player*)pPlayer)->SetJumpDown(true);
			}
		}
	}
	



	


	// 2번 반복
	for (int i = 0; i < OBJID_MAX; i++)
	{
		// 128번 반복
		for (int j = 0; j < 128; j++)
		{
			int iResult = 0; // ?
			if (ObjectList[i][j]->GetActive()) 
				iResult = ObjectList[i][j]->Update();
			if (iResult == 1)
				ObjectList[i][j]->SetActive(false);
			if (iResult == -1)
				--EnemyCount; // 몬스터 수 -1

		}
	}

	// 모르겠음 타겟? ㅁㄹ
	for (int i = 0; i < 128; i++)
	{
		if (ObjectList[OBJID_ENEMY][i]->GetActive())
		{
			((Bullet*)ObjectList[OBJID_BULLET][i])->SetTarget(
				ObjectList[OBJID_ENEMY][0]);
			((SkillBullet*)ObjectList[OBJID_SKBULLET][i])->SetTarget(
				ObjectList[OBJID_ENEMY][0]);
			break;
		}
	}

	for (int i = 0; i < 128; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			if (ObjectList[OBJID_ENEMY][i]->GetActive())
			{
				if (ObjectList[OBJID_BULLET][j]->GetActive())
				{
					// true일 경우 : 몬스터가 공격에 닿았을 경우
					if (CollisionManager::CollisionRact(
						ObjectList[OBJID_ENEMY][i]->GetTransform(),
						ObjectList[OBJID_BULLET][j]->GetTransform()))
					{



						ObjectList[OBJID_ENEMY][i]->SetActive(false);
						ObjectList[OBJID_BULLET][j]->SetActive(false);
						--EnemyCount; // 몬스터 수 -1
					}
				}
				if (ObjectList[OBJID_SKBULLET][j]->GetActive())
				{
					// true일 경우 : 몬스터가 공격에 닿았을 경우
					if (CollisionManager::CollisionRact(
						ObjectList[OBJID_ENEMY][i]->GetTransform(),
						ObjectList[OBJID_SKBULLET][j]->GetTransform()))
					{

						ObjectList[OBJID_ENEMY][i]->SetActive(false);
						ObjectList[OBJID_SKBULLET][j]->SetActive(false);
						--EnemyCount; // 몬스터 수 -1
					}
				}
			}
		}
	}
	pPlayer->Update();
	
	if (EnemyCount <= 0)
	{
		switch (pEnemyID)
		{
		case ENEMYID_PIG:
			SceneManager::GetInstance()->SetScene(SCENEID_STAGE2);
			break;
		case ENEMYID_RABBIT:
			SceneManager::GetInstance()->SetScene(SCENEID_STAGE3);
			break;
		case ENEMYID_DOG:
			SceneManager::GetInstance()->SetScene(SCENEID_WIN);
			break;
		}
	}
	if (GetAsyncKeyState(VK_ESCAPE))
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
}

void ObjectManager::Render()
{
	//** 오브젝트를 보이게 할지 안보이게 할지 결정.
	for (int i = 0; i < BoxMax; i++)
	{
		if (BoxList[i]->GetActive())
			BoxList[i]->Render();

	}


	
	for (int i = 0; i < OBJID_MAX; i++)
	{
		for (int j = 0; j < 128; j++)
		{
			if (ObjectList[i][j]->GetActive())
				ObjectList[i][j]->Render();
		}
	}
	pPlayer->Render();
}

void ObjectManager::Release()
{
	int i = 0;

	SAFE_RELEASE(pPlayer);

	for (i = 0; i < BoxMax; i++)
	{
		SAFE_RELEASE(BoxList[i]);
	}

	for (i = 0; i < OBJID_MAX; i++)
	{
		for (int j = 0; j < 128; j++)
			SAFE_RELEASE(ObjectList[i][j]);
	}
}

void ObjectManager::FureBullet()
{
	for (int i = 0; i < 128; i++)
	{
		if (!ObjectList[OBJID_BULLET][i]->GetActive())
		{
			ObjectList[OBJID_BULLET][i]->SetActive(true);

			ObjectList[OBJID_BULLET][i]->SetPosition(
				pPlayer->GetPosition().x + 13, // 왜 6
				pPlayer->GetPosition().y + 3); // 왜 -1

			if (ObjectList[OBJID_ENEMY][0]->GetActive())
			{
				((Bullet*)ObjectList[OBJID_BULLET][i])->SetTarget(
					ObjectList[OBJID_ENEMY][0]);
				break;
			}
			break;
		}
	}
}

void ObjectManager::FureBullet2()
{
	for (int i = 0; i < 128; i++)
	{
		if (!ObjectList[OBJID_SKBULLET][i]->GetActive())
		{
			ObjectList[OBJID_SKBULLET][i]->SetActive(true);

			ObjectList[OBJID_SKBULLET][i]->SetPosition(
				pPlayer->GetPosition().x + 13, // 왜 6
				pPlayer->GetPosition().y + 2); // 왜 -1

			if (ObjectList[OBJID_ENEMY][0]->GetActive())
			{
				((SkillBullet*)ObjectList[OBJID_SKBULLET][i])->SetTarget(
					ObjectList[OBJID_ENEMY][0]);
				break;
			}
			break;
		}
	}
}


void ObjectManager::CreateEnemy()
{
	switch (pEnemyID)
	{
	case ENEMYID_PIG:
		for (int i = 0; i < 2; i++)
		{
			ObjectList[OBJID_ENEMY][i]->SetPosition(45.0f + (i * 35.f), 25.0f); // 27 : 2
			ObjectList[OBJID_ENEMY][i]->SetActive(true);
			++EnemyCount; // 몬스터 +1
		}
		for (int i = 2; i < 4; i++)
		{
			if (i < 3)
			{
				ObjectList[OBJID_ENEMY][i]->SetPosition(55.0f, 15.0f); // 17:1  ,14:1
				ObjectList[OBJID_ENEMY][i]->SetActive(true);
				++EnemyCount; // 몬스터 +1	
			}
			else
			{
				ObjectList[OBJID_ENEMY][i]->SetPosition(95.0f, 12.0f); // 17:1  ,14:1
				ObjectList[OBJID_ENEMY][i]->SetActive(true);
				++EnemyCount; // 몬스터 +1
			}
		}




		((Pig*)ObjectList[OBJID_ENEMY][0])->SetRightPos(105.0f);
		((Pig*)ObjectList[OBJID_ENEMY][0])->SetLeftPos(40.0f);

		((Pig*)ObjectList[OBJID_ENEMY][1])->SetRightPos(105.0f);
		((Pig*)ObjectList[OBJID_ENEMY][1])->SetLeftPos(40.0f);

		((Pig*)ObjectList[OBJID_ENEMY][2])->SetRightPos(65.0f);
		((Pig*)ObjectList[OBJID_ENEMY][2])->SetLeftPos(48.0f);

		((Pig*)ObjectList[OBJID_ENEMY][3])->SetRightPos(105.0f);
		((Pig*)ObjectList[OBJID_ENEMY][3])->SetLeftPos(92.0f);

		break;
	case ENEMYID_RABBIT:
		for (int i = 0; i < 3; i++)
		{
			ObjectList[OBJID_ENEMY][i]->SetPosition(15.0f + (i * 35.f), 24.0f); // 27 : 2
			ObjectList[OBJID_ENEMY][i]->SetActive(true);

			++EnemyCount; // 몬스터 +1

		}
		for (int i = 3; i <5; i++)
		{
			if (i < 4)
			{
				ObjectList[OBJID_ENEMY][i]->SetPosition(70.0f, 16.0f); // 17:1  ,14:1
				ObjectList[OBJID_ENEMY][i]->SetActive(true);
				++EnemyCount; // 몬스터 +1	
			}
			else
			{
				ObjectList[OBJID_ENEMY][i]->SetPosition(100.0f, 8.0f); // 17:1  ,14:1
				ObjectList[OBJID_ENEMY][i]->SetActive(true);
				++EnemyCount; // 몬스터 +1
			}
		}

		((Rabbit*)ObjectList[OBJID_ENEMY][0])->SetRightPos(23.0f);
		((Rabbit*)ObjectList[OBJID_ENEMY][0])->SetLeftPos(2.0f);

		((Rabbit*)ObjectList[OBJID_ENEMY][1])->SetRightPos(108.0f);
		((Rabbit*)ObjectList[OBJID_ENEMY][1])->SetLeftPos(45.0f);

		((Rabbit*)ObjectList[OBJID_ENEMY][2])->SetRightPos(108.0f);
		((Rabbit*)ObjectList[OBJID_ENEMY][2])->SetLeftPos(45.0f);

		((Rabbit*)ObjectList[OBJID_ENEMY][3])->SetRightPos(90.0f);
		((Rabbit*)ObjectList[OBJID_ENEMY][3])->SetLeftPos(60.0f);

		((Rabbit*)ObjectList[OBJID_ENEMY][4])->SetRightPos(108.0f);
		((Rabbit*)ObjectList[OBJID_ENEMY][4])->SetLeftPos(75.0f);

		break;

	case ENEMYID_DOG:
		
		
		ObjectList[OBJID_ENEMY][0]->SetPosition(70.0f, 15.0f); // 27 : 2
		ObjectList[OBJID_ENEMY][0]->SetActive(true);

		++EnemyCount; // 몬스터 +1

		
		break;
	}

	//for (int i = 0; i < 1; i++)
	//{
	//ObjectList[OBJID_ENEMY][i]->SetPosition(35.0f +( 1 * 35.f), 15.0f ); // 27 : 2
	//ObjectList[OBJID_ENEMY][i]->SetActive(true);
	//
	//++EnemyCount; // 몬스터 +1
	//
	//}
	//for (int i = 2; i < 4; i++)
	//{
	//	if (i<3)
	//	{
	//		ObjectList[OBJID_ENEMY][i]->SetPosition(70.0f, 15.0f); // 17:1  ,14:1
	//		ObjectList[OBJID_ENEMY][i]->SetActive(true);
	//		++EnemyCount; // 몬스터 +1	
	//	}
	//	else
	//	{
	//		ObjectList[OBJID_ENEMY][i]->SetPosition(105.0f, 12.0f); // 17:1  ,14:1
	//		ObjectList[OBJID_ENEMY][i]->SetActive(true);
	//		++EnemyCount; // 몬스터 +1
	//	}
	//}
	
}


