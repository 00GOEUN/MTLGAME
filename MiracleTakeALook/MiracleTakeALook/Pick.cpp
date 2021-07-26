#include "Pick.h"
#include "DoubleBuffer.h"

Pick::Pick() : Color(5)
{
}

Pick::~Pick()
{
}

void Pick::Initialize()
{
	TransInfo.Position = Vector3(0, 0);

	Texture[0] = (char*)"忙式式式式式忖";
	Texture[1] = (char*)"弛﹛﹛﹛﹛﹛弛";
	Texture[2] = (char*)"弛﹛﹛﹛﹛﹛弛";
	Texture[3] = (char*)"弛﹛﹛﹛﹛﹛弛";
	Texture[4] = (char*)"戌式式式式式戎";
	Color = 15;
}

int Pick::Update()
{
	return 0;
}

void Pick::Render()
{
	for (int i = 0; i < 5; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			(int)TransInfo.Position.y + i,
			Texture[i],  Color);
	}

	switch (Index)
	{
	case 0:
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x + 4,
			(int)TransInfo.Position.y + 2,
			(char*)" ---≧", 14);
		break;

	case 1:
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x + 4,
			(int)TransInfo.Position.y + 1,
			(char*)"  -*", 12);
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x + 4,
			(int)TransInfo.Position.y + 2,
			(char*)"--* -≧", 12);
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x + 4,
			(int)TransInfo.Position.y + 3,
			(char*)" -≠", 12);
		break;
	}
}

void Pick::Release()
{
}
