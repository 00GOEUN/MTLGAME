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

	// ��
	Texture[0] = (char*)"��������������������������";
	Texture[1] = (char*)"��������������������������";

	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(94, 15);
	TransInfo.Scale = Vector3((float)strlen("��������������������������"), 7.0f);
}

int Stage1Box3::Update()
{
	return 0;
}

void Stage1Box3::Render()
{
	// ��
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
