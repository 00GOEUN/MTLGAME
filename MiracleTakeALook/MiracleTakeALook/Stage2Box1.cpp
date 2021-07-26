#include "Stage2Box1.h"
#include "DoubleBuffer.h"

Stage2Box1::Stage2Box1()
{
}

Stage2Box1::~Stage2Box1()
{
}

void Stage2Box1::Initialize()
{

	// 漁
	Texture[0] = (char*)"戍式式式式式式忖";
	Texture[1] = (char*)"戍式式式式式式戎";



	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(0, 15);
	TransInfo.Scale = Vector3((float)strlen("戍式式式式式式戎"), 2.0f);
}

int Stage2Box1::Update()
{
	return 0;
}

void Stage2Box1::Render()
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

void Stage2Box1::Release()
{
}
