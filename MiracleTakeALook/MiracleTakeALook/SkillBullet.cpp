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

	Texture[0][0] = (char*)"--�� -*";
	Texture[0][1] = (char*)"  -*--��";
	Texture[0][2] = (char*)"-* --*-��";
	Texture[0][3] = (char*)"---��-*";

	Texture[1][0] = (char*)"  *- ��--";
	Texture[1][1] = (char*)" ��--*- ";
	Texture[1][2] = (char*)"��-*-- *-";
	Texture[1][3] = (char*)"  *-��---";



	Active = false; // ������Ʈ�� ȭ�鿡 ������ �Ⱥ����� �����ϴ� ���� false = �Ⱥ���. true = ����

	m_strKey = "SkillBullet";
}

int SkillBullet::Update()
{
	TransInfo.Position.x += 1.5f; // x���� +1.5��ŭ �̵�?

	// x���� 120���� Texture[2] ������ ũ�ų� ���� ���
	if (TransInfo.Position.x >= 120 - strlen(Texture[0][2]))
	{
		return 1; // 1�� ����
	}

	return 0;
}

void SkillBullet::Render()
{
	// 3�� �ݺ�
	for (int i = 0; i < 4; i++)
	{ 
		// Texture[i]�� ��ġ�� ����
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
