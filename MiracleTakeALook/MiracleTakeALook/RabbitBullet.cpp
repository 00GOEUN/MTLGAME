#include "RabbitBullet.h"
#include "DoubleBuffer.h"


RabbitBullet::RabbitBullet()
{
}

RabbitBullet::~RabbitBullet()
{
	Release();
}
void RabbitBullet::Initialize()
{
	Damage = 15;

	TransInfo.Position = Vector3(0.0f, 0.0f); // 위치 초기화~
	TransInfo.Scale = Vector3(7.0f, 1.0f); // x:넓이 y:높이

	// [0]~[2]에 기본스킬 디자인을 넣음
	Texture[0][0] = (char*)"<_ ''}";
	
	Texture[1][0] = (char*)"{'' _>";

	Active = false; // 이건 모르겠엉

	m_strKey = "RabbitBullet";
	Horizontal = 0;
}

int RabbitBullet::Update()
{

	if (Horizontal == DIR_LEFT)
	{
		TransInfo.Position.x -= 1.5f;

		if (TransInfo.Position.x <= 0)
		{
			return 1;
		}
	}
	else
	{
		TransInfo.Position.x += 1.5f;

		if (TransInfo.Position.x >= 117)
		{
			return 1;
		}
	}


	//  x축을 +3만큼 이동
	//TransInfo.Position.x -= 1.5f;

	// x축이 (120 - Texture[1])보다 크거나 같으면 1을 리턴?
	//if (TransInfo.Position.x <= 0.0f)
	//{
		//return 1;
	//}

	return 0;
}

void RabbitBullet::Render()
{
	// 출력 
	DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y),
			Texture[!Horizontal][0], 1);
}

void RabbitBullet::Release()
{
}
