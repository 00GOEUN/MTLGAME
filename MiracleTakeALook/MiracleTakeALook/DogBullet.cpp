#include "DogBullet.h"
#include "DoubleBuffer.h"


DogBullet::DogBullet()
{
}

DogBullet::~DogBullet()
{
	Release();
}
void DogBullet::Initialize()
{
	Damage = 25;

	TransInfo.Position = Vector3(0.0f, 0.0f); // 위치 초기화~
	TransInfo.Scale = Vector3(11.0f, 5.0f); // x:넓이 y:높이

	// [0]~[2]에 기본스킬 디자인을 넣음
	Texture[0][0] = (char*)" _______";
	Texture[0][1] = (char*)"<__     |";
	Texture[0][2] = (char*)"<__  ))  |";
	Texture[0][3] = (char*)"<__  ))  |";
	Texture[0][4] = (char*)"<_______|";

	Active = false; // 이건 모르겠엉

	m_strKey = "DogBullet";
}

int DogBullet::Update()
{
	//  x축을 -1.5만큼 이동
	TransInfo.Position.x -= 1.5f;

	// x축이 (120 - Texture[1])보다 크거나 같으면 1을 리턴?
	if (TransInfo.Position.x <= 0.0f)
		return 1;

	return 0;
}

void DogBullet::Render()
{
	// 출력 
	for (int i = 0; i < 5; i++)
	{
		//DoubleBuffer::GetInstance()->WriteBuffer(
		//	(int)TransInfo.Position.x,
		//	(int)TransInfo.Position.y + i,
		//	Texture[i], 12);
		// 현재 위치에서 스케일 / 2.0f을 빼서 저장 : /2.0f는 왜 하는가..?
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y) + i,
			Texture[0][i], 6);

	}
}

void DogBullet::Release()
{
}
