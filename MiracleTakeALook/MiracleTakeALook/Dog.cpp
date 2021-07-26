#include "Dog.h"
#include "DoubleBuffer.h"
#include "DogBullet.h"

Dog::Dog()
{
}

Dog::~Dog()
{
	Release();
}

void Dog::Initialize()
{
	Motion = 0;
	Motion_Max = 3;

	Hp = 150;

	for (int i = 0; i < 128; i++)
	{
		m_Bullet[i] = NULL;
	}

	// 1
	//        ___      __
	//       |\. '___./\ |                 _
	//       |/|\./|   \\|                //
	//        _|@|@|_   \                //
	//       /(  ) ' '   \______________// 
	//      |  \/   .  |                 |
	//      \__/\__/   |                 |
	//        V  V     |                 |
	//         \______/----| |________| |
	//                  | || |     | || |
	//                  | || |     | || | 
	//                  | || |     | || | 
	//                 (__(__|    (__(__|
	//
	Texture[0][0] = (char*)"          ___      __";
	Texture[0][1] = (char*)"         |↘ '___./↘|               /\\";
	Texture[0][2] = (char*)"         |/|↘/|   ↘|              / \\";
	Texture[0][3] = (char*)"          _|@|@|_   ↘             / \\";
	Texture[0][4] = (char*)"         /(  ) ' '   ↘___________/ \\";
	Texture[0][5] = (char*)"        |  ↘/   .  |               |";
	Texture[0][6] = (char*)"        ↘__/↘__/  |               |";
	Texture[0][7] = (char*)"          V___V____/                |";
	Texture[0][8] = (char*)"                  ↘--| |________| |";
	Texture[0][9] = (char*)"                   | || |     | || |";
	Texture[0][10] = (char*)"                   | || |     | || |";
	Texture[0][11] = (char*)"                   | || |     | || |";
	Texture[0][12] = (char*)"                  (__(__|    (__(__|";

// 2
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
Texture[1][0] = (char*)"        ___      __";
Texture[1][1] = (char*)"       |↘ '___./↘ |                 /\\";
Texture[1][2] = (char*)"       |/|↘/|   ↘|                 / \\";
Texture[1][3] = (char*)"        _|@|@|_   ↘                / \\";
Texture[1][4] = (char*)"       /(  ) ' '   ↘______________/ \\";
Texture[1][5] = (char*)"      |  ↘/   .  |                 |";
Texture[1][6] = (char*)"      ↘__/↘__/| |                 |";
Texture[1][7] = (char*)"        V  /V  /  |                 |";
Texture[1][8] = (char*)"          /^ ^/  /----| |________| |";
Texture[1][9] = (char*)"          ↘____/  | || |     | || |";
Texture[1][10] = (char*)"                   | || |     | || |";
Texture[1][11] = (char*)"                   | || |     | || |";
Texture[1][12] = (char*)"                  (__(__|    (__(__|";

// 3
//                 ___      __
//                |\. '___./\ |                 _
//                |/|\./|   \\|                //
//                 _|o|o|_   \                //
//         +  \   /(  ) ' '   \______________// 
//             \ |  \/   .  |                 |
//        +   -  \__/\__/|  |                 |
//        _______  V  /V /  |                 |
//             -     /^^/  /----| |________| |
//         + -    /  \____/  | || |     | || |
//           +   /           | || |     | || | 
//              /            | || |     | || | 
//                          (__(__|    (__(__|
Texture[2][0] = (char*)"          ___      __";
Texture[2][1] = (char*)"         |↘ '___./↘|                 /\\";
Texture[2][2] = (char*)"         |/|↘/|   ↘|                / \\";
Texture[2][3] = (char*)"   ↘    _|@|@|_   ↘                / \\";
Texture[2][4] = (char*)"  + ↘  /(  ) ' '   ↘______________/ \\";
Texture[2][5] = (char*)"       |  \/   .  |                  |";
Texture[2][6] = (char*)"+    _ ↘__/↘__/|  |               |";
Texture[2][7] = (char*)"--- ____  V  /V /  |                |";
Texture[2][8] = (char*)"      -     /^^/  /----| |________| |";
Texture[2][9] = (char*)"  + -    /  ↘___/  | || |     | || |";
Texture[2][10] = (char*)"    +  /            | || |     | || |";
Texture[2][11] = (char*)"      /             | || |     | || |";
Texture[2][12] = (char*)"                   (__(__|    (__(__|";

m_strKey = "Dog";

TransInfo.Position = Vector3(0.0f, 0.0f);
TransInfo.Scale = Vector3((float)strlen(Texture[2][1]), 13.0f); // Dog의 x: 넓이 y: 높이

Speed = 0.5f; // 속도 0.2로 초기화

Active = false; // 움직임?

Time = (ULONG)GetTickCount64();
MotionTime = 300;


}

int Dog::Update()
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
	// x축에 -속도를 빼줌
	//TransInfo.Position.x -= Speed;


		if (Vertical)
		{
			TransInfo.Position.y -= Speed;

			if (TransInfo.Position.y <= 10)
			{
				Vertical = !Vertical;
			}
		}
		else
		{
			TransInfo.Position.y += Speed;


			if (TransInfo.Position.y >= 15)
			{
				Vertical = !Vertical;
			}

		}
		if (Time + MotionTime < GetTickCount64())
		{
			Time = (ULONG)GetTickCount64();
			
			Motion++;

			if (Motion_Max <= Motion)
			{
				
				for (int i = 0; i < 128; ++i)
				{
					if (m_Bullet[i] == NULL)
					{
						m_Bullet[i] = new DogBullet;
						m_Bullet[i]->Initialize();

						m_Bullet[i]->SetPosition(
							TransInfo.Position.x,
							TransInfo.Position.y + rand()%9);

						break;
					}
				}
				Motion = 0;
			}
		}

	

	





	// x가 3.5보다 크거나 같을 경우
	//if (TransInfo.Position.x <= 10.5f)
	//{
	//	Active = false;
	//	return -1; // 왜 -1 리턴?
	//}



	return 0;
}

void Dog::Render()
{
	for (int i = 0; i < 128; i++)
	{
		if (m_Bullet[i] != NULL)
			m_Bullet[i]->Render();

	}



	for (int i = 0; i < 13; ++i)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y + i),
			Texture[Motion][i], 1);
	}
}

void Dog::Release()
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
