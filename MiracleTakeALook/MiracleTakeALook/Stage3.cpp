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
	// m_pPlayer�� �� Player�� �ʱ�ȭ
	Object* pPlayer = new Player;
	pPlayer->Initialize();

	ObjectManager::GetInstance()->Initialize();
	ObjectManager::GetInstance()->SetPlayer(pPlayer);

	m_pBackGround = new BackGround;
	m_pBackGround->Initialize();

	// ��������1 UI
	m_pStage = new Wall;
	m_pStage->Initialize();


	// �÷��̾� HP
	m_pPlayerHp = new PlayerHP;
	m_pPlayerHp->Initialize();

	m_pPlayerHp->SetPosition(
		3.0f,
		1.0f);

	// ���� ���� UI �ʱ�ȭ
	for (int i = 0; i < 2; i++)
	{
		m_pPick[i] = new Pick;
		m_pPick[i]->Initialize();

		// ���� UI ��� ��ġ
		m_pPick[i]->SetPosition(
			float((14 * (i + 1)) + 2) - 13,
			(float)4);
		((Pick*)m_pPick[i])->SetIndex(i);
	}
	Choice = 0; // ���� 0 �ʱ�ȭ
	((Player*)m_pPick)->SetIndex(Choice); // 0���� ����
	((Pick*)m_pPick[Choice])->SetColor(15); // UI �÷�

	ObjectManager::GetInstance()->CreateEnemy(); // ���� ����
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

	// A: �⺻ ���� ��
	if (ulKey & KEYID_AKEY)
	{
		Choice = Choice;
		((Player*)pPlayer)->SetIndex(Choice);
		((Pick*)m_pPick[Choice])->SetColor(5); // ��ų ����
		((Pick*)m_pPick[!Choice])->SetColor(15); // �⺻ ����


	}
	// S: ��ų ���� ��
	if (ulKey & KEYID_SKEY)
	{
		Choice = Choice;
		((Player*)pPlayer)->SetIndex(Choice);
		((Pick*)m_pPick[Choice])->SetColor(15); // ��ų ����
		((Pick*)m_pPick[!Choice])->SetColor(5); // �⺻ ����
	}
	// �ٲ��!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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
