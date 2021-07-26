#include "PigHP.h"
#include "DoubleBuffer.h"

PigHP::PigHP()
{
}

PigHP::~PigHP()
{
}

void PigHP::Initialize()
{
	TransInfo.Position = Vector3(0, 0);

	Texture[0] = (char*)"[   ]";

}

int PigHP::Update()
{
	return 0;
}

void PigHP::Render()
{
	DoubleBuffer::GetInstance()->WriteBuffer(
		(int)TransInfo.Position.x,
		(int)TransInfo.Position.y,
		Texture[0]);
	DoubleBuffer::GetInstance()->WriteBuffer(
		(int)TransInfo.Position.x + 1,
		(int)TransInfo.Position.y + 1,
		(char*)"¡á¡á", 10);
		// ÇÑ Ä­´ç ÇÇ 5
}

void PigHP::Release()
{
}

