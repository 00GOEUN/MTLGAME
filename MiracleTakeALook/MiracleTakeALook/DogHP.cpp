#include "DogHP.h"
#include "DoubleBuffer.h"

DogHP::DogHP()
{
}

DogHP::~DogHP()
{
}

void DogHP::Initialize()
{
	TransInfo.Position = Vector3(0, 0);

	Texture[0] = (char*)"��������������������������������������������";
	Texture[1] = (char*)"��������������������������������������������";
	Texture[2] = (char*)"��������������������������������������������";

}

int DogHP::Update()
{
	return 0;
}

void DogHP::Render()
{
	for (int i = 0; i < 3; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			(int)TransInfo.Position.y + i,
			Texture[i]);
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x + 2,
			(int)TransInfo.Position.y + 1,
			(char*)"���������������������", 10);
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x + 2,
			(int)TransInfo.Position.y + 1,
			(char*)"�����������", 8);
		// �� ĭ�� �� 5
	}
}

void DogHP::Release()
{
}

