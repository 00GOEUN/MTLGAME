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

	Texture[0] = (char*)"忙式式式式式式式式式式式式式式式式式式式式忖";
	Texture[1] = (char*)"弛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛﹛弛";
	Texture[2] = (char*)"戌式式式式式式式式式式式式式式式式式式式式戎";

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
			(char*)"﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥﹥", 10);
		// и 蘊渡 Я 5
	}
}

void PlayerHP::Release()
{
}

