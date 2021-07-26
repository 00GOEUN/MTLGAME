#include "Wall.h"
#include "DoubleBuffer.h"

Wall::Wall()
{
}

Wall::~Wall()
{
}
void Wall::Initialize()
{
	TransInfo.Position = Vector3(0, 0);

	Texture[0] = (char*)"┌──────────────────────────────────────────────────────────┓";
	for (int i = 0; i < 28; i++)
	{
		Texture[i +1] = (char*)"│";
	}


	
	//Texture[28] = (char*)"└──────────────────────────────────────────────────────────┘";


	for (int i = 0; i < 27; i++)
	{
		Texture[i + 29] = (char*)"│";
	}

	//// 벽
	//Texture[56] = (char*)"┌──────┐";
	//Texture[57] = (char*)"│　　　　　　│";
	//Texture[58] = (char*)"│　　　　　　│";
	//Texture[59] = (char*)"│　　　　　　│";
	//Texture[60] = (char*)"│　　　　　　│";
	//Texture[61] = (char*)"│　　　　　　│";
	//Texture[62] = (char*)"┴──────┴";
	//
	//// 다리( 중간 )
	//Texture[63] = (char*)"┌────────────┐";
	//Texture[64] = (char*)"└────────────┘";
	//
	//// 다리2( 끝 )
	//Texture[65] = (char*)"┌────────────┤";
	//Texture[66] = (char*)"└────────────┤";
}

int Wall::Update()
{
	return 0;
}

void Wall::Render()
{
	for (int i = 0; i < 28; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x,
			(int)TransInfo.Position.y + i,
			Texture[i]);
	}
	for (int i = 0; i < 27; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			(int)TransInfo.Position.x +118,
			(int)TransInfo.Position.y + 1+ i,
			Texture[29+i]);
	}
	//// 벽
	//for (int i = 0; i < 7; i++)
	//{
	//	DoubleBuffer::GetInstance()->WriteBuffer(
	//		(int)TransInfo.Position.x + 20,
	//		(int)TransInfo.Position.y + 22 + i,
	//		Texture[56 + i], 5);
	//}
	//// 중간 다리
	//for (int i = 0; i < 2; i++)
	//{
	//	DoubleBuffer::GetInstance()->WriteBuffer(
	//		(int)TransInfo.Position.x + 50,
	//		(int)TransInfo.Position.y + 15 + i,
	//		Texture[63 + i]);
	//}
	//// 끝 다리
	//for (int i = 0; i < 2; i++)
	//{
	//	DoubleBuffer::GetInstance()->WriteBuffer(
	//		(int)TransInfo.Position.x + 92,
	//		(int)TransInfo.Position.y + 10 + i,
	//		Texture[65 + i]);
	//}
}

void Wall::Release()
{
}
