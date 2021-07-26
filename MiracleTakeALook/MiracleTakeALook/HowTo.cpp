#include "HowTo.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"


HowTo::HowTo()
{
}

HowTo::~HowTo()
{
}


void HowTo::Initialize()
{
	// MyHowTo �迭�� �ΰ� ������ ���� 
	MyHowTo[0].Texture = (char*)" ________ ________ _______     ________ _______     _______  ________ ________ ________";
	MyHowTo[1].Texture = (char*)"|��     /|��     /|��    /|   |��     /|��    /|   |��     /|��     /|��     /|��    /|";
	MyHowTo[2].Texture = (char*)"| +----+ | +----+ | +---+ |   | +----+ | +---+ |   | +----+ | +----+ | +---+ | +----+ |";
	MyHowTo[3].Texture = (char*)"| |    | | |    | | |   | |   | |    | | |   | |   | |    | | |    | | |   | | |    | |";
	MyHowTo[4].Texture = (char*)"| |H   | | |o   | | |w  | |   | |T   | | |o  | |   | |P   | | |l   | | |a  | | |y   | |";
	MyHowTo[5].Texture = (char*)"| +----+ | +----+ | +---+ |   | +----+ | +---+ |   | +----+ | +----+ | +---+ | +----+ |";
	MyHowTo[6].Texture = (char*)"|/_____��|/_____��|/____��|   |______��|/____��|   |/_____��|/_____��|/____��|/_____��|";
	
	MyHowTo[7].Texture = (char*)"�� Push ENETER ��";
	
	MyHowTo[8].Texture = (char*)"�� Story ��";
	MyHowTo[9].Texture = (char*)"�̶�Ŭ �༺�� ���� �� ������ �� �ϳ�!";
	MyHowTo[10].Texture = (char*)"�̶�Ŭ �༺�� ħ���Ϸ��� �ִϸ��� óġ�Ͽ� �̶�Ŭ �༺�� ���Ѷ�!";
	MyHowTo[11].Texture = (char*)"�� ���۹� ��";
	MyHowTo[12].Texture = (char*)"[ <- ] [ -> ] [ SPACE ]";
	MyHowTo[13].Texture = (char*)"�� ���� ��";
	MyHowTo[14].Texture = (char*)"[ A ] [ S ]";

	//
	//
	//		 ________ ________ _______     ________ _______     _______  ________ ________ ________
	//		|��     /|��     /|��     /|   |��     /|��    /|    |��     /|��     /|��     /|��     /|
	//		| +----+ | +----+ | +---+ |   | +----+ | +---+ |   | +----+ | +----+ | +---+ | +----+ |
	//		| |    | | |    | | |   | |   | |    | | |   | |   | |    | | |    | | |   | | |    | |
	//		| |H   | | |o   | | |w  | |   | |T   | | |o  | |   | |P   | | |l   | | |a  | | |y   | |
	//		| +----+ | +----+ | +---+ |   | +----+ | +---+ |   | +----+ | +----+ | +---+ | +----+ |
	//		|/_____��|/______��|/____��|   |______��|/_____��|   |/_____��|/_____��|/_____��|/_____��|
	//
	//
	//											�� Story ��
	//									�̶�Ŭ �༺�� ���� �� ������ �� �ϳ�!
	//						�̶�Ŭ �༺�� ħ���Ϸ��� �ִϸ��� óġ�Ͽ� �̶�Ŭ �༺�� ���Ѷ�!
	//								
	//											�� ���۹� ��
	//									[ <- ] [ -> ] [ SPACE ]
	//
	//											�� ���� ��
	//											[ A ] [ S ]
	//
	//										�� Push ENETER ��


	float CenterX;
	float CenterY;

	for (int i = 0; i < 15; i++)
	{
		CenterX = (120 / 2) - ((float)strlen(MyHowTo[0].Texture) / 2); // ����
		MyHowTo[i].TransPos.Position = Vector3(CenterX, 2.0f + (float)i);
		MyHowTo[i].TransPos.Scale = Vector3((float)strlen(MyHowTo[i].Texture), 7.0f);
		if (i == 7 )
		{
			CenterX = (120 / 2) - ((float)strlen(MyHowTo[7].Texture) / 2); // ����
			MyHowTo[i].TransPos.Position = Vector3(CenterX, 20.0f+(float)i);
			MyHowTo[i].TransPos.Scale = Vector3((float)strlen(MyHowTo[i].Texture), 1.0f);
		}
		if (i > 7)
		{
			CenterX = (120 / 2) - ((float)strlen(MyHowTo[i].Texture) / 2); // ����
			CenterY = 0;
			if(i>10)
				CenterY = 1;
			if(i>12)
				CenterY = 2;
			MyHowTo[i].TransPos.Position = Vector3(CenterX, CenterY+ 4.0f + (float)i);

			if(i>10)
			MyHowTo[i].TransPos.Position = Vector3(CenterX, CenterY+ 6.0f + (float)i);

			MyHowTo[i].TransPos.Scale = Vector3((float)strlen(MyHowTo[i].Texture), 8.0f);
		}
	}

}

void HowTo::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
}

void HowTo::Render()
{
	// ����� x,y,����� ��, ����
	for (int i = 0; i < 15; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			MyHowTo[i].TransPos.Position.x,
			MyHowTo[i].TransPos.Position.y,
			MyHowTo[i].Texture, 5);
		if(i>6)
		DoubleBuffer::GetInstance()->WriteBuffer(
			MyHowTo[i].TransPos.Position.x,
			MyHowTo[i].TransPos.Position.y,
			MyHowTo[i].Texture, 8);
		if (i > 7)
			DoubleBuffer::GetInstance()->WriteBuffer(
				MyHowTo[i].TransPos.Position.x,
				MyHowTo[i].TransPos.Position.y,
				MyHowTo[i].Texture, 15);
	}
}

void HowTo::Release()
{
}