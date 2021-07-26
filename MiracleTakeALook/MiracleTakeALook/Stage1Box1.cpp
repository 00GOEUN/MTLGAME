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

	// ��
	Texture[0] = (char*)"����������������";
	Texture[1] = (char*)"����������������";
	Texture[2] = (char*)"����������������";
	Texture[3] = (char*)"����������������";
	Texture[4] = (char*)"����������������";
	Texture[5] = (char*)"����������������";
	Texture[6] = (char*)"����������������";
	


	Active = true;
	
	m_strKey = "Ground";
	
	TransInfo.Position = Vector3(22, 22);
	TransInfo.Scale = Vector3((float)strlen("����������������"),  7.0f);
}

int Stage1Box1::Update()
{
	return 0;
}

void Stage1Box1::Render()
{
	// ��
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
