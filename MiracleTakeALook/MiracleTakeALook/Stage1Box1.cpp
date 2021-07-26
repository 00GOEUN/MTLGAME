#include "Stage1Box1.h"
#include "DoubleBuffer.h"

Stage1Box1::Stage1Box1()
{
}

Stage1Box1::~Stage1Box1()
{
}

void Stage1Box1::Initialize()
{

	// 漁
	Texture[0] = (char*)"忙式式式式式式忖";
	Texture[1] = (char*)"弛﹛﹛﹛﹛﹛﹛弛";
	Texture[2] = (char*)"弛﹛﹛﹛﹛﹛﹛弛";
	Texture[3] = (char*)"弛﹛﹛﹛﹛﹛﹛弛";
	Texture[4] = (char*)"弛﹛﹛﹛﹛﹛﹛弛";
	Texture[5] = (char*)"弛﹛﹛﹛﹛﹛﹛弛";
	Texture[6] = (char*)"扛式式式式式式扛";
	


	Active = true;
	
	m_strKey = "Ground";
	
	TransInfo.Position = Vector3(22, 22);
	TransInfo.Scale = Vector3((float)strlen("扛式式式式式式扛"),  7.0f);
}

int Stage1Box1::Update()
{
	return 0;
}

void Stage1Box1::Render()
{
	// 漁
	for (int i = 0; i < 7; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			(int)TransInfo.Position.y + i,
			Texture[i]);
	}
}

void Stage1Box1::Release()
{
}
