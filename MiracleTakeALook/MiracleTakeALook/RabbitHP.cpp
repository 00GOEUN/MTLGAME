#include "RabbitHP.h"
#include "DoubleBuffer.h"

RabbitHP::RabbitHP()
{
}

RabbitHP::~RabbitHP()
{
}

void RabbitHP::Initialize()
{
	TransInfo.Position = Vector3(0, 0);

	Texture[0] = (char*)"[     ]";

}

int RabbitHP::Update()
{
	return 0;
}

void RabbitHP::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		(int)TransInfo.Position.x,
		(int)TransInfo.Position.y,
		Texture[0]);
	DoubleBuffer::GetInstance()->WriteBuffer(
		(int)TransInfo.Position.x + 1,
		(int)TransInfo.Position.y + 1,
		(char*)"�����", 10);
	// �� ĭ�� �� 5
}

void RabbitHP::Release()
{
}

