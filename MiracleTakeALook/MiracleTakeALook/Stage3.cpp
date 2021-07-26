#include "Stage3.h"
#include "Player.h"
#include "BackGround.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "Pick.h"
#include "Wall.h"
#include "PlayerHP.h"
#include "Stage1Box1.h"

Stage3::Stage3()
{
}

Stage3::~Stage3()
{
	Release();
}

void Stage3::Initialize()
{
	ObjectManager::GetInstance()->SetEnemyID(ENEMYID_DOG);
	// m_pPlayer를 새 Player로 초기화
	Object* pPlayer = new Player;
	pPlayer->Initialize();

	ObjectManager::GetInstance()->Initialize();
	ObjectManager::GetInstance()->SetPlayer(pPlayer);

	m_pBackGround = new BackGround;
	m_pBackGround->Initialize();

	// 스테이지1 UI
	m_pStage = new Wall;
	m_pStage->Initialize();


	// 플레이어 HP
	m_pPlayerHp = new PlayerHP;
	m_pPlayerHp->Initialize();

	m_pPlayerHp->SetPosition(
		3.0f,
		1.0f);

	// 공격 선택 UI 초기화
	for (int i = 0; i < 2; i++)
	{
		m_pPick[i] = new Pick;
		m_pPick[i]->Initialize();

		// 공격 UI 출력 위치
		m_pPick[i]->SetPosition(
			float((14 * (i + 1)) + 2) - 13,
			(float)4);
		((Pick*)m_pPick[i])->SetIndex(i);
	}
	Choice = 0; // 선택 0 초기화
	((Player*)m_pPick)->SetIndex(Choice); // 0으로 시작
	((Pick*)m_pPick[Choice])->SetColor(15); // UI 컬러

	ObjectManager::GetInstance()->CreateEnemy(); // 몬스터 생성
}

void Stage3::Update()
{
	m_pBackGround->Update();



	for (int i = 0; i < 2; i++)
	{
		m_pPick[i]->Update();
	}

	m_pStage->Update();

	//m_pBox1->Update();

	m_pPlayerHp->Update();


	ULONG ulKey = InputManager::GetInstance()->GetKey();
	Object* pPlayer = ObjectManager::GetInstance()->GetPlayer();

	// A: 기본 공격 시
	if (ulKey & KEYID_AKEY)
	{
		Choice = Choice;
		((Player*)pPlayer)->SetIndex(Choice);
		((Pick*)m_pPick[Choice])->SetColor(5); // 스킬 공격
		((Pick*)m_pPick[!Choice])->SetColor(15); // 기본 공격


	}
	// S: 스킬 공격 시
	if (ulKey & KEYID_SKEY)
	{
		Choice = Choice;
		((Player*)pPlayer)->SetIndex(Choice);
		((Pick*)m_pPick[Choice])->SetColor(15); // 스킬 공격
		((Pick*)m_pPick[!Choice])->SetColor(5); // 기본 공격
	}
	// 바꿔라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	ObjectManager::GetInstance()->Update();
}

void Stage3::Render()
{
	m_pBackGround->Render();

	m_pStage->Render();
	for (int i = 0; i < 2; i++)
	{
		m_pPick[i]->Render();
	}

	m_pPlayerHp->Render();

	ObjectManager::GetInstance()->Render();
}

void Stage3::Release()
{
	SAFE_RELEASE(m_pBackGround);

	SAFE_RELEASE(m_pStage);

	SAFE_RELEASE(m_pPlayerHp);

	for (int i = 0; i < 2; i++)
		SAFE_RELEASE(m_pPick[i]);

	ObjectManager::GetInstance()->Release();
}
