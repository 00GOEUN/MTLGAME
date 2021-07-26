#include "Stage2Box5.h"
#include "DoubleBuffer.h"

Stage2Box5::Stage2Box5()
{
}

Stage2Box5::~Stage2Box5()
{
}

void Stage2Box5::Initialize()
{

	// 漁
	Texture[0] = (char*)"忙式式式式式式式式式式式式式式式式式式式式扣";
	Texture[1] = (char*)"戌式式式式式式式式式式式式式式式式式式式式扣";


	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(76, 12);
	TransInfo.Scale = Vector3((float)strlen("戌式式式式式式式式式式式式式式式式式式扣"), 2.0f);
}

int Stage2Box5::Update()
{
	return 0;
}

void Stage2Box5::Render()
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

void Stage2Box5::Release()
{
}
