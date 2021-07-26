#include "Stage2Box3.h"
#include "DoubleBuffer.h"

Stage2Box3::Stage2Box3()
{
}

Stage2Box3::~Stage2Box3()
{
}

void Stage2Box3::Initialize()
{

	// º®
	Texture[0] = (char*) "¦¨¦¨";
	Texture[1] = (char*) "¦¢¦¢";
	Texture[2] = (char*) "¦¢¦¢";
	Texture[3] = (char*) "¦¢¦¢";
	Texture[4] = (char*) "¦¢¦¢";
	Texture[5] = (char*) "¦¢¦¢";
	Texture[6] = (char*) "¦¢¦¢";
	Texture[7] = (char*) "¦¢¦¢";
	Texture[8] = (char*) "¦¢¦¢";
	Texture[9] = (char*) "¦¢¦¢";
	Texture[10] = (char*)"¦¢¦¢";
	Texture[11] = (char*)"¦¢¦¢";
	Texture[12] = (char*)"¦¢¦¢";
	Texture[13] = (char*)"¦¢¦¢";
	Texture[14] = (char*)"¦¢¦¢";
	Texture[14] = (char*)"¦¢¦¢";
	Texture[15] = (char*)"¦¢¦¢";
	Texture[16] = (char*)"¦¢¦¢";
	Texture[17] = (char*)"¦¢¦¢";
	Texture[18] = (char*)"¦¢¦¢";
	Texture[19] = (char*)"¦¢¦¢";
	Texture[20] = (char*)"¦¢¦¢";
	Texture[21] = (char*)"¦¦¦¥";



	Active = true;


	TransInfo.Position = Vector3(56, 0);
	TransInfo.Scale = Vector3((float)strlen("¦¨¦¨"), 22.0f);
}

int Stage2Box3::Update()
{
	return 0;
}

void Stage2Box3::Render()
{
	// º®
	for (int i = 0; i < 22; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			(int)TransInfo.Position.y + i,
			Texture[i]);
	}
}

void Stage2Box3::Release()
{
}
