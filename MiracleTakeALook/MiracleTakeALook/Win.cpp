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

	TransInfo.Position = Vector3(0, 0); // ��ġ �ʱ�ȭ

	// MyLogo �迭�� �ΰ� ������ ���� 
	MyWin[0].Texture = (char*)" _______ _______ _______ _______      ______ _____   _______ _______ ______";
	MyWin[1].Texture = (char*)"|     __|   _   |   |   |    ___|    |      |     |_|    ___|   _   |   __ �� ";
	MyWin[2].Texture = (char*)"|    |  |       |       |    ___|    |   ---|       |    ___|       |      <";
	MyWin[3].Texture = (char*)"|_______|___|___|__|_|__|_______|    |______|_______|_______|___|___|___|__|";

	MyWin[4].Texture = (char*)"�� Push Enter ��";

	// 
	for (int i = 0; i < 5; i++)
	{
		// 5���� ���� ���� ��ġ ������ ũ�� �ʱ�ȭ
		if (i < 4)
		{
			MyWin[i].TransPos.Position = Vector3(20.0f, 8.0f + (float)i);
			MyWin[i].TransPos.Scale = Vector3(strlen(MyWin[2].Texture), 4.0f);
		}
		// 4���� ū ���� ��ġ ������ ũ�� �ʱ�ȭ
		else
		{
			MyWin[i].TransPos.Position = Vector3(50.0f, 20.0f + (float)i);
			MyWin[i].TransPos.Scale = Vector3(strlen(MyWin[4].Texture), 1.0f);
		}
	}
}

void Win::Update()
{
	// ���͸� ������ Menu�� �̵�
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(SCENEID_LOGO);
}

void Win::Render()
{
	// 8~12
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 15, (char*)"  /��	  ", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 16, (char*)"  /  ��  ", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 17, (char*)" --^--^--", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 18, (char*)" ( �Ĥ���)��", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 19, (char*)"~/__/�آ�/", 4);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 20, (char*)"   U U", 4);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 17, (char*)"  ^ -^", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 18, (char*)" (  ^��^)", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 19, (char*)"~(   x )" , 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 20, (char*)"   U U", 6);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 17, (char*)"  ^- ^", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 18, (char*)"(^��^  )", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 19, (char*)" ( x   )~", 3);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 20, (char*)"   U U", 3);

	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 15, (char*)"      �ע�", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 16, (char*)"    ��  ��", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 17, (char*)"  --^--^--", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 18, (char*)"��(�Ť��� )", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 19, (char*)" ��//��__��~", 9);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 20, (char*)"     U U", 9);


	//      ^ _^
	//    /      \
	//   |  ��  �� |
	//    \___Y__/
	//
	//
	//    |\----/|
	//    | ��_�� | 
	// ��  \__^__/


	// ����� x,y,����� ��, ����
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
