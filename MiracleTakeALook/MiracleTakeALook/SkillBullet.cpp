#include "SkillBullet.h"
#include "DoubleBuffer.h"

SkillBullet::SkillBullet()
{
}

SkillBullet::~SkillBullet()
{
}
void SkillBullet::Initialize()
{
	Damage = 25;

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(10.0f, 4.0f);

	Texture[0][0] = (char*)"--☆ -*";
	Texture[0][1] = (char*)"  -*--★";
	Texture[0][2] = (char*)"-* --*-☆";
	Texture[0][3] = (char*)"---★-*";

	Texture[1][0] = (char*)"  *- ☆--";
	Texture[1][1] = (char*)" ★--*- ";
	Texture[1][2] = (char*)"☆-*-- *-";
	Texture[1][3] = (char*)"  *-★---";



	Active = false; // 오브젝트가 화면에 보일지 안보일지 결정하는 변수 false = 안보임. true = 보임

	m_strKey = "SkillBullet";
}

int SkillBullet::Update()
{
	TransInfo.Position.x += 1.5f; // x축을 +1.5만큼 이동?

	// x축이 120에서 Texture[2] 뺐을때 크거나 같을 경우
	if (TransInfo.Position.x >= 120 - strlen(Texture[0][2]))
	{
		return 1; // 1로 리턴
	}

	return 0;
}

void SkillBullet::Render()
{
	// 3번 반복
	for (int i = 0; i < 4; i++)
	{ 
		// Texture[i]의 위치를 저장
		//DoubleBuffer::GetInstance()->WriteBuffer(
		//	(int)TransInfo.Position.x,
		//	(int)TransInfo.Position.y + i,
		//	Texture[i], 12);
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y) + i,
			Texture[0][i], 12);
	}
}

void SkillBullet::Release()
{
}
