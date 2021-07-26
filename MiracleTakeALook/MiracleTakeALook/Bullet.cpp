#include "Bullet.h"
#include "DoubleBuffer.h"


Bullet::Bullet()
{
}

Bullet::~Bullet()
{
	Release();
}
void Bullet::Initialize()
{
	Damage = 10;

	TransInfo.Position = Vector3(0.0f, 0.0f); // ��ġ �ʱ�ȭ~
	TransInfo.Scale = Vector3(7.0f, 3.0f); // x:���� y:����

	// [0]~[2]�� �⺻��ų �������� ����
	Texture[0][0] = (char*)"-*";
	Texture[0][1] = (char*)" ---��";
	Texture[0][2] = (char*)" -+";

	Texture[1][0] = (char*)"    *-";
	Texture[1][1] = (char*)"��--- ";
	Texture[1][2] = (char*)"   +-";

	Active = false; // �̰� �𸣰ھ�
	m_strKey = "Bullet";
}

int Bullet::Update()
{ 
	//  x���� +3��ŭ �̵�
	TransInfo.Position.x += 1.5f;

	// x���� (120 - Texture[1])���� ũ�ų� ������ 1�� ����?
	if (TransInfo.Position.x >= (120.0f - strlen(Texture[0][1])))
	{
		return 1;
	}

	return 0;
}

void Bullet::Render()
{
	// ��� 
	for (int i = 0; i < 3; i++)
	{
		//DoubleBuffer::GetInstance()->WriteBuffer(
		//	(int)TransInfo.Position.x,
		//	(int)TransInfo.Position.y + i,
		//	Texture[i], 12);
		// ���� ��ġ���� ������ / 2.0f�� ���� ���� : /2.0f�� �� �ϴ°�..?
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x ),
			int(TransInfo.Position.y ) + i,
			Texture[0][i], 14);

	}
}

void Bullet::Release()
{
}
