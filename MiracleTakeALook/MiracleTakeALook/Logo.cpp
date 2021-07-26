#include "Logo.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Initialize()
{

	TransInfo.Position = Vector3(70, 0); // 위치 초기화

	// MyLogo 배열에 로고 디자인 넣음 
	MyLogo[0].Texture = (char*)"             * +                        ★";
	MyLogo[1].Texture = (char*)" ☆  _______ __                   __";
	MyLogo[2].Texture = (char*)"*   |   |   |__|.----.---.-.----.|  |.-----.   +";
	MyLogo[3].Texture = (char*)"    |       |  ||   _|  _  |  __||  ||  -__|";
	MyLogo[4].Texture = (char*)"    |__|_|__|__||__| |___._|____||__||_____|   ";



	MyLogo[5].Texture = (char*)"   _______         __         * .   _______      _____                __   +  ★";
	MyLogo[6].Texture = (char*)"  |_     _|.---.-.|  |--.-----.    |   _   |    |     |_.-----.-----.|  |--. *";
	MyLogo[7].Texture = (char*)"    |   |  |  _  ||    <|  -__|    |       |    |       |  _  |  _  ||    < ";
	MyLogo[8].Texture = (char*)"'   |___|  |___._||__|__|_____|    |___|___|    |_______|_____|_____||__|__|    .";
	MyLogo[9].Texture = (char*)" ★ .                           . *                                        ☆ '    ";

	MyLogo[10].Texture = (char*)"☆ Push Enter ☆";

	// 
	for (int i = 0; i < 11; i++)
	{
		// 5보다 작은 것의 위치 지정과 크기 초기화
		if (i < 5)
		{
			MyLogo[i].TransPos.Position = Vector3(15.0f, 8.0f + (float)i);
			MyLogo[i].TransPos.Scale = Vector3(strlen(MyLogo[2].Texture), 5.0f);
		}
		// 4보다 큰 것의 위치 지정과 크기 초기화
		else if ( i < 10)
		{
			MyLogo[i].TransPos.Position = Vector3(30.0f, 9.0f + (float)i);
			MyLogo[i].TransPos.Scale = Vector3(strlen(MyLogo[9].Texture), 5.0f);

		}
		if (i == 10)
		{
			MyLogo[i].TransPos.Position = Vector3(50.0f, 10.0f+(float)i);
			MyLogo[i].TransPos.Scale = Vector3(strlen(MyLogo[10].Texture), 1.0f);
		}
	}
}

void Logo::Update()
{
	// 엔터를 누르면 Menu로 이동
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(SCENEID_MENU);
}

void Logo::Render()
{		
	// 8~12
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 5, (char*)"★",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 10 , (int)TransInfo.Position.y + 6, (char*)"☆",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x, (int)TransInfo.Position.y + 7, (char*)" ★",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 35, (int)TransInfo.Position.y + 20, (char*)"★",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 45, (int)TransInfo.Position.y + 21, (char*)"☆",6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x - 55, (int)TransInfo.Position.y + 22, (char*)"★",6);

	// 출력함 x,y,출력할 것, 색상
	for (int i = 0; i < 10; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			MyLogo[i].TransPos.Position.x,
			MyLogo[i].TransPos.Position.y,
			MyLogo[i].Texture, 5);
	}
	DoubleBuffer::GetInstance()->WriteBuffer(
		MyLogo[10].TransPos.Position.x,
		MyLogo[10].TransPos.Position.y,
		MyLogo[10].Texture, 8);
}

void Logo::Release()
{
}
