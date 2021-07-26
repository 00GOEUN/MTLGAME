#include "Win.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

Win::Win()
{
}

Win::~Win()
{
}

void Win::Initialize()
{

	TransInfo.Position = Vector3(0, 0); // 위치 초기화

	// MyLogo 배열에 로고 디자인 넣음 
	MyWin[0].Texture = (char*)" _______ _______ _______ _______      ______ _____   _______ _______ ______";
	MyWin[1].Texture = (char*)"|     __|   _   |   |   |    ___|    |      |     |_|    ___|   _   |   __ ↘ ";
	MyWin[2].Texture = (char*)"|    |  |       |       |    ___|    |   ---|       |    ___|       |      <";
	MyWin[3].Texture = (char*)"|_______|___|___|__|_|__|_______|    |______|_______|_______|___|___|___|__|";

	MyWin[4].Texture = (char*)"☆ Push Enter ☆";

	// 
	for (int i = 0; i < 5; i++)
	{
		// 5보다 작은 것의 위치 지정과 크기 초기화
		if (i < 4)
		{
			MyWin[i].TransPos.Position = Vector3(20.0f, 8.0f + (float)i);
			MyWin[i].TransPos.Scale = Vector3(strlen(MyWin[2].Texture), 4.0f);
		}
		// 4보다 큰 것의 위치 지정과 크기 초기화
		else
		{
			MyWin[i].TransPos.Position = Vector3(50.0f, 20.0f + (float)i);
			MyWin[i].TransPos.Scale = Vector3(strlen(MyWin[4].Texture), 1.0f);
		}
	}
}

void Win::Update()
{
	// 엔터를 누르면 Menu로 이동
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(SCENEID_LOGO);
}

void Win::Render()
{
	// 8~12
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 15, (char*)"  /↘	  ", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 16, (char*)"  /  ↘  ", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 17, (char*)" --^--^--", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 18, (char*)" ( ◐ㅅ◐)★", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 19, (char*)"~/__/↖↘/", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 20, (char*)"   U U", 4);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 17, (char*)"  ^ -^", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 18, (char*)" (  ^ㅅ^)", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 19, (char*)"~(   x )" , 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 20, (char*)"   U U", 6);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 17, (char*)"  ^- ^", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 18, (char*)"(^ㅅ^  )", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 19, (char*)" ( x   )~", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 20, (char*)"   U U", 3);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 15, (char*)"      ↙↘", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 16, (char*)"    ↙  ↘", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 17, (char*)"  --^--^--", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 18, (char*)"★(◑ㅅ◑ )", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 19, (char*)" ↖//↖__↘~", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 20, (char*)"     U U", 9);


	//      ^ _^
	//    /      \
	//   |  ♥  ♥ |
	//    \___Y__/
	//
	//
	//    |\----/|
	//    | ♥_♥ | 
	// 　  \__^__/


	// 출력함 x,y,출력할 것, 색상
	for (int i = 0; i < 4; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			MyWin[i].TransPos.Position.x,
			MyWin[i].TransPos.Position.y,
			MyWin[i].Texture, 5);
	}
	DoubleBuffer::GetInstance()->WriteBuffer(
		MyWin[4].TransPos.Position.x,
		MyWin[4].TransPos.Position.y,
		MyWin[4].Texture, 8);
}

void Win::Release()
{
}
