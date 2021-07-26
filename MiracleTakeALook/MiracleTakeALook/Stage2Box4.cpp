#include "Stage2Box4.h"
#include "DoubleBuffer.h"

Stage2Box4::Stage2Box4()
{
}

Stage2Box4::~Stage2Box4()
{
}

void Stage2Box4::Initialize()
{

	// 漁
	Texture[0] = (char*)"戌式式式式式式式式式式式式式式式式式式忖";
	Texture[1] = (char*)"式式式式式式式式式式式式式式式式式式式戎";



	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(58, 20);
	TransInfo.Scale = Vector3((float)strlen("式式式式式式式式式式式式式式式式式式式戎"), 2.0f);
}

int Stage2Box4::Update()
{
	return 0;
}

void Stage2Box4::Render()
{
	// 漁
	for (int i = 0; i < 2; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			(int)TransInfo.Position.y + i,
			Texture[i]);
	}
}

void Stage2Box4::Release()
{
}
