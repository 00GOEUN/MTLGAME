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

	// 漁
	//Texture[0] = (char*)"戌式式式戎";
	Texture[0] = (char*)"戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎";



	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(0, 28);
	TransInfo.Scale = Vector3((float)strlen("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎"), 7.0f);
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
