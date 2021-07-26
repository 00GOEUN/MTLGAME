#include "Rabbit.h"
#include "DoubleBuffer.h"
#include "RabbitBullet.h"

Rabbit::Rabbit()
{
}

Rabbit::~Rabbit()
{
	Release();
}

void Rabbit::Initialize()
{
	Hp = 50;

	for (int i = 0; i < 128; i++)
		m_Bullet[i] = NULL;


	Texture[0][0] = (char*)"    ��_��";
	Texture[0][1] = (char*)"   ( o��o)";
	Texture[0][2] = (char*)" o( u u)";
	Texture[0][3] = (char*)"   U U";

	Texture[1][0] = (char*)"  ��_��";
	Texture[1][1] = (char*)"(o��o )";
	Texture[1][2] = (char*)" (u u )o";
	Texture[1][3] = (char*)"   U U";

	m_strKey = "Rabbit";

	// Enemy2
	//    ��_��
	//   ( o��o)
	// o( u u)
	//   U U


	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen(Texture[0][1]), 4.0f); // Rabbit�� x: ���� y: ����

	Speed = 0.2f; // �ӵ� 0.2�� �ʱ�ȭ
	Horizontal = DIR_RIGHT;
	Active = false; // ������?

	Time = (ULONG)GetTickCount64();
	BulletTime = 2500;
}

int Rabbit::Update()
{
	int Result = 0;
	for (int i = 0; i < 128; i++)
	{
		Result = 0;

		if (m_Bullet[i] != NULL)
			Result = m_Bullet[i]->Update();
		if (Result)
		{
			delete m_Bullet[i];
			m_Bullet[i] = NULL;
		}
	}

	// x�࿡ -�ӵ��� ����
	//TransInfo.Position.x -= Speed;
	// x�� 3.5���� ũ�ų� ���� ���




	if (Horizontal == DIR_LEFT)
	{
		TransInfo.Position.x -= Speed;

		if (PosX[1] > TransInfo.Position.x)
			Horizontal = !Horizontal;
	}
	else
	{
		TransInfo.Position.x += Speed;

		if (PosX[0] < TransInfo.Position.x)
			Horizontal = !Horizontal;
	}






	if (Time + BulletTime < GetTickCount64())
	{
		Time = (ULONG)GetTickCount64();

		for (int i = 0; i < 128; ++i)
		{
			if (m_Bullet[i] == NULL)
			{
				m_Bullet[i] = new RabbitBullet;
				m_Bullet[i]->Initialize();

				m_Bullet[i]->SetPosition(
					TransInfo.Position.x,
					TransInfo.Position.y + 1);

				m_Bullet[i]->SetHorizontal(Horizontal);

				break;
			}
		}
	}




	//if (TransInfo.Position.x <= 10.5f)
	//{
	//	Active = false;
	//	return -1; // �� -1 ����?
	//}
	//
	return 0;
}

void Rabbit::Render()
{
	for (int i = 0; i < 128; i++)
	{
		if (m_Bullet[i] != NULL)
			m_Bullet[i]->Render();

	}
	for (int i = 0; i < 4; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y + i),
			Texture[Horizontal][i], 4);
	}

}

void Rabbit::Release()
{
	for (int i = 0; i < 128; i++)
	{
		if (m_Bullet[i] != NULL)
		{
			delete m_Bullet[i];
			m_Bullet[i] = NULL;
		}
	}
}
