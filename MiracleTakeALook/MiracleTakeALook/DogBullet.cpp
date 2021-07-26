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

	TransInfo.Position = Vector3(0.0f, 0.0f); // ��ġ �ʱ�ȭ~
	TransInfo.Scale = Vector3(11.0f, 5.0f); // x:���� y:����

	// [0]~[2]�� �⺻��ų �������� ����
	Texture[0][0] = (char*)" _______";
	Texture[0][1] = (char*)"<__     |";
	Texture[0][2] = (char*)"<__  ))  |";
	Texture[0][3] = (char*)"<__  ))  |";
	Texture[0][4] = (char*)"<_______|";

	Active = false; // �̰� �𸣰ھ�

	m_strKey = "DogBullet";
}

int DogBullet::Update()
{
	//  x���� -1.5��ŭ �̵�
	TransInfo.Position.x -= 1.5f;

	// x���� (120 - Texture[1])���� ũ�ų� ������ 1�� ����?
	if (TransInfo.Position.x <= 0.0f)
		return 1;

	return 0;
}

void DogBullet::Render()
{
	// ��� 
	for (int i = 0; i < 5; i++)
	{
		//DoubleBuffer::GetInstance()->WriteBuffer(
		//	(int)TransInfo.Position.x,
		//	(int)TransInfo.Position.y + i,
		//	Texture[i], 12);
		// ���� ��ġ���� ������ / 2.0f�� ���� ���� : /2.0f�� �� �ϴ°�..?
		DoubleBuffer::GetInstance()->WriteBuffer(
			int(TransInfo.Position.x),
			int(TransInfo.Position.y) + i,
			Texture[0][i], 6);

	}
}

void DogBullet::Release()
{
}
