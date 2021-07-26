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

	TransInfo.Position = Vector3(0.0f, 0.0f); // ��ġ �ʱ�ȭ~
	TransInfo.Scale = Vector3(7.0f, 1.0f); // x:���� y:����

	// [0]~[2]�� �⺻��ų �������� ����
	Texture[0][0] = (char*)"<_ ''}";
	
	Texture[1][0] = (char*)"{'' _>";

	Active = false; // �̰� �𸣰ھ�

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


	//  x���� +3��ŭ �̵�
	//TransInfo.Position.x -= 1.5f;

	// x���� (120 - Texture[1])���� ũ�ų� ������ 1�� ����?
	//if (TransInfo.Position.x <= 0.0f)
	//{
		//return 1;
	//}

	return 0;
}

void RabbitBullet::Render()
{
	// ��� 
	DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y),
			Texture[!Horizontal][0], 1);
}

void RabbitBullet::Release()
{
}
