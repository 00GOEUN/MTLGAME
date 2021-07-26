#include "PlayerHP.h"
#include "DoubleBuffer.h"

PlayerHP::PlayerHP()
{
}

PlayerHP::~PlayerHP()
{
}

void PlayerHP::Initialize()
{
	TransInfo.Position = Vector3(0, 0);

	Texture[0] = (char*)"��������������������������������������������";
	Texture[1] = (char*)"��������������������������������������������";
	Texture[2] = (char*)"��������������������������������������������";

}

int PlayerHP::Update()
{
	return 0;
}

void PlayerHP::Render()
{
	for (int i = 0; i < 3; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			(int)TransInfo.Position.y + i,
			Texture[i]);
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x + 2,
			(int)TransInfo.Position.y+ 1,
			(char*)"���������������������", 10);
		// �� ĭ�� �� 5
	}
}

void PlayerHP::Release()
{
}

