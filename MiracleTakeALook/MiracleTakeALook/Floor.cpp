#include "Floor.h"
#include "DoubleBuffer.h"

Floor::Floor()
{
}

Floor::~Floor()
{
}

void Floor::Initialize()
{

	// ��
	//Texture[0] = (char*)"����������";
	Texture[0] = (char*)"������������������������������������������������������������������������������������������������������������������������";



	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(0, 28);
	TransInfo.Scale = Vector3((float)strlen("������������������������������������������������������������������������������������������������������������������������"), 7.0f);
}

int Floor::Update()
{
	return 0;
}

void Floor::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		(int)TransInfo.Position.x,
		(int)TransInfo.Position.y,
		Texture[0]);

}

void Floor::Release()
{
}
