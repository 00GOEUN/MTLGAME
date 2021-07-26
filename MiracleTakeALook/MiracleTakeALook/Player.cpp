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

	// 공격을 127만큼 생성해줌
	for (int i = 0; i < 128; i++)
		m_Bullet[i] = NULL;

	// Texture[0]~[4]까지 주인공 디자인 초기화해줌
	// Texture[0] = (char*)"  ^ -^";
	
	Texture[0][0] = (char*)"  /↘";
	Texture[0][1] = (char*)"  /  ↘";
	Texture[0][2] = (char*)" --^--^--";
	Texture[0][3] = (char*)" ( ◐ㅅ◐)★";
	Texture[0][4] = (char*)"~/__/↖↘/";
	Texture[0][5] = (char*)"   U U";

	Texture[1][0] = (char*)"      ↙↘";
	Texture[1][1] = (char*)"    ↙  ↘";
	Texture[1][2] = (char*)"  --^--^--";
	Texture[1][3] = (char*)"★(◑ㅅ◑ )";
	Texture[1][4] = (char*)" ↖//↖__↘~";
	Texture[1][5] = (char*)"     U U";

	// 출력할 위치 지정
	TransInfo.Position = Vector3(10.0f, 22.0f);
	// 모르겠음
	TransInfo.Scale = Vector3((float)strlen(Texture[0][5]), 6.0f); // Player의 x: 넓이 y: 높이

	m_Jump = false; // 점프 안함
	m_OldY = 0.0f; // 현재 Y축은 0
	m_Power = 0.8f; // 무슨 파워 0.08 초기화

	m_Time = 0.0f; // 시간 0 초기화
	Horizontal = 0;
	m_JumpDown = false;
}

int Player::Update()
{
	CheckKey(); // 키 확인 함수를 불러옴


	float PosY = TransInfo.Position.y;

	if (m_Jump) // 만약에 점프를 했다면
	{
		m_Time += 0.1f; // 이 속도로 진행


		// y의 위치를 이동
		PosY += -sinf(90 * PI / 180) * m_Power + (GRAVITY_ACCELERATION * m_Time * m_Time) / 2;

		if (TransInfo.Position.y < PosY)
			m_JumpDown = true;

		TransInfo.Position.y = PosY;

		// 점프 하기 전의 위치가 현재 y축보다 작으면
		//if (m_OldY < TransInfo.Position.y)
		//{
			// Y 축을 점프하기 전 위치로 바꾼 후 점프 안함 상태로 바꿈
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

		// m_Bullet[i]이미 있다면 Result는  m_Bullet의 Update로 초기화
		if (m_Bullet[i] != NULL)
			Result = m_Bullet[i]->Update();

		// 만약에 Result가 1이라면 m_Bullet를 삭제하고 해당 배열을 NULL로 
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
	// 127번 반복
	for (int i = 0; i < 128; i++)
	{
		// m_Bullet이 널이 아닐경우 Render()를 불러옴
		if (m_Bullet[i] != NULL)
			m_Bullet[i]->Render();
	}

	// 3번 반복
	for (int i = 0; i < 6; i++)
	{
		// Player를 출력함
		// Texture의 i 배열을 포지션에 위치에 스케일만큼 빼서 저장함
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y + i),
			Texture[Horizontal][i], 5);
	}

}

void Player::Release()
{
	// 127번 반복
	for (int i = 0; i < 128; i++)
	{
		// m_Bullet이 NULL이 아닐경우 삭제하고 NULL로 바꿔줌
		if (m_Bullet[i] != NULL)
		{
			delete m_Bullet[i];
			m_Bullet[i] = NULL;
		}

	}
}

void Player::CheckKey()
{
	// ulkey를 GetKey로 초기화 : ulkey는 GetKey임
	ULONG ulKey = InputManager::GetInstance()->GetKey(); 

	// LEFT키 입력 시 x축의 -로 이동
	if (ulKey & KEYID_LEFT)
	{
		if (TransInfo.Position.x >= 3)
		{
			Horizontal = 1;
			TransInfo.Position.x--;
		}
	}
	// RIGHT키 입력 시 x축의 +로 이동
	if (ulKey & KEYID_RIGHT)
	{
		if (TransInfo.Position.x <= 105)
		{
			Horizontal = 0;
			TransInfo.Position.x++;
		}
	}
	// SPACE 입력 시 점프를 확인하는 함수를 불러옴
	if (ulKey & KEYID_SPACE)
	{
		CheckJump();
	}
	// A키를 입력 시 공격
	if (ulKey & KEYID_AKEY)
	{

		ObjectManager::GetInstance()->FureBullet();
		
	}
	// S키를 입력 시 스킬
	if (ulKey & KEYID_SKEY)
	{

		ObjectManager::GetInstance()->FureBullet2();
		
	}
}

// 점프를 확인함
void Player::CheckJump()
{
	// m_Jump가 맞다면 종료
	if (m_Jump)
		return;

	m_JumpDown = false;
	m_Jump = true; // m_Jump를 true로 바꿈
	m_OldY = TransInfo.Position.y; // m_Oldy는 점프하기 전의 위치로 초기화
	m_Time = 0.0f; // 시간은 0초로 시작
}
