#include "Stage1Box3.h"
#include "DoubleBuffer.h"

Stage1Box3::Stage1Box3()
{
}

Stage1Box3::~Stage1Box3()
{
}

void Stage1Box3::Initialize()
{

	// 漁
	Texture[0] = (char*)"忙式式式式式式式式式式式扣";
	Texture[1] = (char*)"戌式式式式式式式式式式式扣";

	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(94, 15);
	TransInfo.Scale = Vector3((float)strlen("戌式式式式式式式式式式式戎"), 7.0f);
}

int Stage1Box3::Update()
{
	return 0;
}

void Stage1Box3::Render()
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

void Stage1Box3::Release()
{
}
