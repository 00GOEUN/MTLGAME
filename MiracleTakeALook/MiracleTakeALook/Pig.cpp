#include "Pig.h"
#include "DoubleBuffer.h"

Pig::Pig()
{
}

Pig::~Pig()
{
}

void Pig::Initialize()
{
	Hp = 20;

	Texture[0][0] = (char*)"  (�� o..o��)";
	Texture[0][1] = (char*)"@(_ U  x U)";
	Texture[0][2] = (char*)"    U  U";

	Texture[1][0] = (char*)"(��o..o ��)";
	Texture[1][1] = (char*)" (U x  U _)@";
	Texture[1][2] = (char*)"    U  U";

	m_strKey = "Pig";

	// Enemy1
	//    ^ -^
	//  (  o..o)
	// @( U x U)
	//    U  U

	// Enemy2
	//    ��_��
	//   ( o��o)
	// o( u u)
	//   U U

	// Enemy3
	//        ___      __
	//       |\. '___./\ |                 _
	//       |/|\./|   \\|                //
	//        _|o|o|_   \                //
	//       /(  ) ' '   \______________// 
	//      |  \/   .  |                 |
	//      \__/\__/|  |                 |
	//        V  /V /  |                 |
	//          /^^/  /----| |________| |
	//          \____/  | || |     | || |
	//                  | || |     | || | 
	//                  | || |     | || | 
	//                 (__(__|    (__(__|
	//


	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3((float)strlen(Texture[0][1]), 3.0f); // Pig�� x: ���� y: ����
	
	Speed = 0.2f; // �ӵ� 0.2�� �ʱ�ȭ

	Active = false; // ������?

	//** �¿� Ȯ�ο�   0 = �������� �̵�  1 = �������� �̵�
	Horizontal = 0;
}

int Pig::Update()
{
	//CheckXMax();
	//
	//float PosX = TransInfo.Position.x;
	//
	//if (m_XMax)
	if (Horizontal)
	{
		TransInfo.Position.x -= Speed;

		if(PosX[1] > TransInfo.Position.x)
			Horizontal = !Horizontal;


		/*
		if(EnemyNum = 1)
			if (TransInfo.Position.x <= 35)
				Horizontal = !Horizontal;
		if (EnemyNum = 2)
			if (TransInfo.Position.x <= 50)
				Horizontal = !Horizontal;
		if (EnemyNum = 3)
			if (TransInfo.Position.x <= 70)
				Horizontal = !Horizontal;
		*/


	}
	else
	{
		TransInfo.Position.x += Speed;

		if (PosX[0] < TransInfo.Position.x)
			Horizontal = !Horizontal;


		/*
		if (EnemyNum = 1)
			if (TransInfo.Position.x >= 105)
				Horizontal = !Horizontal;
		if (EnemyNum = 2)
			if (TransInfo.Position.x >= 60)
				Horizontal = !Horizontal;
		if (EnemyNum = 3)
			if (TransInfo.Position.x >= 105)
				Horizontal = !Horizontal;
		*/

	}

	//switch (EnemyNum)
	//{
	//case 1:
	//	if (Horizontal)
	//	{
	//		TransInfo.Position.x -= Speed;
	//
	//		if (TransInfo.Position.x <= 40)
	//		{
	//			Horizontal = !Horizontal;
	//		}
	//	}
	//	else
	//	{
	//		TransInfo.Position.x += Speed;
	//
	//
	//		if (TransInfo.Position.x >= 100)
	//		{
	//			Horizontal = !Horizontal;
	//		}
	//
	//	}
	//	break;
	//case 2:
	//	if (Horizontal)
	//	{
	//		TransInfo.Position.x -= Speed;
	//
	//		if (TransInfo.Position.x <= 40)
	//		{
	//			Horizontal = !Horizontal;
	//		}
	//	}
	//	else
	//	{
	//		TransInfo.Position.x += Speed;
	//
	//
	//		if (TransInfo.Position.x >= 100)
	//		{
	//			Horizontal = !Horizontal;
	//		}
	//
	//	}
	//	break;
	//case 3:
	//	if (Horizontal)
	//	{
	//		TransInfo.Position.x -= Speed;
	//
	//		if (TransInfo.Position.x <= 40)
	//		{
	//			Horizontal = !Horizontal;
	//		}
	//	}
	//	else
	//	{
	//		TransInfo.Position.x += Speed;
	//
	//
	//		if (TransInfo.Position.x >= 100)
	//		{
	//			Horizontal = !Horizontal;
	//		}
	//
	//	}
	//	break;
	//}

	//else
	

	// x�࿡ -�ӵ��� ����
	//TransInfo.Position.x -= Speed;


	// x�� 3.5���� ũ�ų� ���� ���
	//if (TransInfo.Position.x <= 2.0f)
	//{
	//	Active = false;
	//	return -1; // �� -1 ����?
	//}

	return 0;
}

void Pig::Render()
{
	for (int i = 0; i < 3; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y + i),
			Texture[Horizontal][i], 3);
	}

}

void Pig::Release()
{
}


