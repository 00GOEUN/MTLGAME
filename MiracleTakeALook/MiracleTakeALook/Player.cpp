#include "Player.h"
#include "DoubleBuffer.h"
#include "InputManager.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "SkillBullet.h"

Player::Player()
{
}

Player::~Player()
{
	Release();
}

void Player::Initialize()
{
	Hp = 100;

	// ������ 127��ŭ ��������
	for (int i = 0; i < 128; i++)
		m_Bullet[i] = NULL;

	// Texture[0]~[4]���� ���ΰ� ������ �ʱ�ȭ����
	// Texture[0] = (char*)"  ^ -^";
	
	Texture[0][0] = (char*)"  /��";
	Texture[0][1] = (char*)"  /  ��";
	Texture[0][2] = (char*)" --^--^--";
	Texture[0][3] = (char*)" ( �Ĥ���)��";
	Texture[0][4] = (char*)"~/__/�آ�/";
	Texture[0][5] = (char*)"   U U";

	Texture[1][0] = (char*)"      �ע�";
	Texture[1][1] = (char*)"    ��  ��";
	Texture[1][2] = (char*)"  --^--^--";
	Texture[1][3] = (char*)"��(�Ť��� )";
	Texture[1][4] = (char*)" ��//��__��~";
	Texture[1][5] = (char*)"     U U";

	// ����� ��ġ ����
	TransInfo.Position = Vector3(10.0f, 22.0f);
	// �𸣰���
	TransInfo.Scale = Vector3((float)strlen(Texture[0][5]), 6.0f); // Player�� x: ���� y: ����

	m_Jump = false; // ���� ����
	m_OldY = 0.0f; // ���� Y���� 0
	m_Power = 0.8f; // ���� �Ŀ� 0.08 �ʱ�ȭ

	m_Time = 0.0f; // �ð� 0 �ʱ�ȭ
	Horizontal = 0;
	m_JumpDown = false;
}

int Player::Update()
{
	CheckKey(); // Ű Ȯ�� �Լ��� �ҷ���


	float PosY = TransInfo.Position.y;

	if (m_Jump) // ���࿡ ������ �ߴٸ�
	{
		m_Time += 0.1f; // �� �ӵ��� ����


		// y�� ��ġ�� �̵�
		PosY += -sinf(90 * PI / 180) * m_Power + (GRAVITY_ACCELERATION * m_Time * m_Time) / 2;

		if (TransInfo.Position.y < PosY)
			m_JumpDown = true;

		TransInfo.Position.y = PosY;

		// ���� �ϱ� ���� ��ġ�� ���� y�ຸ�� ������
		//if (m_OldY < TransInfo.Position.y)
		//{
			// Y ���� �����ϱ� �� ��ġ�� �ٲ� �� ���� ���� ���·� �ٲ�
		//	TransInfo.Position.y = m_OldY;
		//	m_Jump = false;
		//}
	}
	else
	if (m_JumpDown == true)
	{
		//m_Jump = true;
		TransInfo.Position.y++;
	}

	int Result = 0;
	for ( int i = 0; i < 128; i++)
	{
		Result = 0;

		// m_Bullet[i]�̹� �ִٸ� Result��  m_Bullet�� Update�� �ʱ�ȭ
		if (m_Bullet[i] != NULL)
			Result = m_Bullet[i]->Update();

		// ���࿡ Result�� 1�̶�� m_Bullet�� �����ϰ� �ش� �迭�� NULL�� 
		if (Result)
		{
			delete m_Bullet[i];
			m_Bullet[i] = NULL;
		}
	}

	return 0;
}

void Player::Render()
{
	// 127�� �ݺ�
	for (int i = 0; i < 128; i++)
	{
		// m_Bullet�� ���� �ƴҰ�� Render()�� �ҷ���
		if (m_Bullet[i] != NULL)
			m_Bullet[i]->Render();
	}

	// 3�� �ݺ�
	for (int i = 0; i < 6; i++)
	{
		// Player�� �����
		// Texture�� i �迭�� �����ǿ� ��ġ�� �����ϸ�ŭ ���� ������
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y + i),
			Texture[Horizontal][i], 5);
	}

}

void Player::Release()
{
	// 127�� �ݺ�
	for (int i = 0; i < 128; i++)
	{
		// m_Bullet�� NULL�� �ƴҰ�� �����ϰ� NULL�� �ٲ���
		if (m_Bullet[i] != NULL)
		{
			delete m_Bullet[i];
			m_Bullet[i] = NULL;
		}

	}
}

void Player::CheckKey()
{
	// ulkey�� GetKey�� �ʱ�ȭ : ulkey�� GetKey��
	ULONG ulKey = InputManager::GetInstance()->GetKey(); 

	// LEFTŰ �Է� �� x���� -�� �̵�
	if (ulKey & KEYID_LEFT)
	{
		if (TransInfo.Position.x >= 3)
		{
			Horizontal = 1;
			TransInfo.Position.x--;
		}
	}
	// RIGHTŰ �Է� �� x���� +�� �̵�
	if (ulKey & KEYID_RIGHT)
	{
		if (TransInfo.Position.x <= 105)
		{
			Horizontal = 0;
			TransInfo.Position.x++;
		}
	}
	// SPACE �Է� �� ������ Ȯ���ϴ� �Լ��� �ҷ���
	if (ulKey & KEYID_SPACE)
	{
		CheckJump();
	}
	// AŰ�� �Է� �� ����
	if (ulKey & KEYID_AKEY)
	{

		ObjectManager::GetInstance()->FureBullet();
		
	}
	// SŰ�� �Է� �� ��ų
	if (ulKey & KEYID_SKEY)
	{

		ObjectManager::GetInstance()->FureBullet2();
		
	}
}

// ������ Ȯ����
void Player::CheckJump()
{
	// m_Jump�� �´ٸ� ����
	if (m_Jump)
		return;

	m_JumpDown = false;
	m_Jump = true; // m_Jump�� true�� �ٲ�
	m_OldY = TransInfo.Position.y; // m_Oldy�� �����ϱ� ���� ��ġ�� �ʱ�ȭ
	m_Time = 0.0f; // �ð��� 0�ʷ� ����
}
