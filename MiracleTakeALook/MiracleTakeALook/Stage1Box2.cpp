#include "Stage1Box2.h"
#include "DoubleBuffer.h"

Stage1Box2::Stage1Box2()
{
}

Stage1Box2::~Stage1Box2()
{
}

void Stage1Box2::Initialize()
{

	// ��
	Texture[0] = (char*)"��������������������������";
	Texture[1] = (char*)"��������������������������";

	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(50, 18);
	TransInfo.Scale = Vector3((float)strlen("��������������������������"), 7.0f);
}

int Stage1Box2::Update()
{
	return 0;
}

void Stage1Box2::Render()
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

void Stage1Box2::Release()
{
}
