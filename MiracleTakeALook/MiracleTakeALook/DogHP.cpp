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

	Texture[0] = (char*)"忙式式式式式式式式式式式式式式式式式式式式忖";
	Texture[1] = (char*)"弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛";
	Texture[2] = (char*)"戌式式式式式式式式式式式式式式式式式式式式戎";

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
			(char*)"﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥", 10);
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x + 2,
			(int)TransInfo.Position.y + 1,
			(char*)"﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥", 8);
		// и 蘊渡 Я 5
	}
}

void DogHP::Release()
{
}

