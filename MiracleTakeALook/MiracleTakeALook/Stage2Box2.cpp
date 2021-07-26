#include "Stage2Box2.h"
#include "DoubleBuffer.h"

Stage2Box2::Stage2Box2()
{
}

Stage2Box2::~Stage2Box2()
{
}

void Stage2Box2::Initialize()
{

	// º®
	Texture[0] = (char*)"¦£¦¡¦¡¦¡¦¤";
	Texture[1] = (char*)"¦¢¡¡¡¡¡¡¦¢";
	Texture[2] = (char*)"¦¢¡¡¡¡¡¡¦¢";
	Texture[3] = (char*)"¦¢¡¡¡¡¡¡¦¢";
	Texture[4] = (char*)"¦¢¡¡¡¡¡¡¦¢";
	Texture[5] = (char*)"¦¢¡¡¡¡¡¡¦¢";
	Texture[6] = (char*)"¦ª¦¡¦¡¦¡¦ª";



	Active = true;

	m_strKey = "Ground";

	TransInfo.Position = Vector3(32, 22);
	TransInfo.Scale = Vector3((float)strlen("¦ª¦¡¦¡¦¡¦ª"), 7.0f);
}

int Stage2Box2::Update()
{
	return 0;
}

void Stage2Box2::Render()
{
	// º®
	for (int i = 0; i < 7; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			(int)TransInfo.Position.y + i,
			Texture[i]);
	}
}

void Stage2Box2::Release()
{
}
