#include "Menu.h"
#include "SceneManager.h"
#include "DoubleBuffer.h"

Menu::Menu()
{
}

Menu::~Menu()
{
	Release();
}

void Menu::Initialize()
{
	// ��
	TransInfo.Position = Vector3(60, 0); // ��ġ �ʱ�ȭ

	// �޴�
	MyMenu[0].Texture = (char*)"+-+-+-+-+-+";
	MyMenu[1].Texture = (char*)"|S|t|a|r|t|";
	MyMenu[2].Texture = (char*)"+-+-+-+-+-+";

	MyMenu[3].Texture = (char*)"+-+-+-+ +-+-+ +-+-+-+-+";
	MyMenu[4].Texture = (char*)"|H|o|w| |t|o| |p|l|a|y|";
	MyMenu[5].Texture = (char*)"+-+-+-+ +-+-+ +-+-+-+-+";
	
	MyMenu[6].Texture = (char*)"+-+-+-+-+";
	MyMenu[7].Texture = (char*)"|E|x|i|t|";
	MyMenu[8].Texture = (char*)"+-+-+-+-+";
        

	for (int i = 0; i < 9; i++)
	{
		MyMenu[i].Color = 8;
	}

	float Center;

	for (int i = 0; i < 9; i++)
	{
		// ����
		if (i < 3)
		{
			Center = (120 / 2) - ((float)strlen(MyMenu[1].Texture) / 2); 
		}
		else if (i < 6)
		{
			Center = (120 / 2) - ((float)strlen(MyMenu[4].Texture) / 2);
		}
		else if (i < 9)
		{
			Center = (120 / 2) - ((float)strlen(MyMenu[7].Texture) / 2);
		}
		MyMenu[i].TransPos.Position = Vector3(Center, 10.0f + i); // ��ġ �ʱ�ȭ
		MyMenu[i].TransPos.Scale = Vector3(9.0f, 1.0f); // ������ ��??
	}

	MyPlayer[0].Texture = (char*)"  ^ -^";
	MyPlayer[1].Texture = (char*)" ( �Ĥ���)��";
	MyPlayer[2].Texture = (char*)"~(   x ) /";
	MyPlayer[3].Texture = (char*)"   U U";

	for (int i = 0; i < 4; i++)
	{
		MyPlayer[i].TransPos.Position = Vector3(10.0f, 22.0f + i); // ��ġ �ʱ�ȭ
		MyPlayer[i].TransPos.Scale = Vector3(9.0f, 1.0f); // ������ ��??
	}
		
	Choice = 0; // ���� 0 �ʱ�ȭ
}

void Menu::Update()
{
	//ULONG ulKey = InputManager::GetInstance()->GetKey();

	if(GetAsyncKeyState(VK_UP))
	{
		// ������ 0�� �ƴϸ� -1
		if (Choice != 0)
			Choice--;
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		// ������ 2�� �ƴϸ� +1
		if (Choice != 2)
			Choice++;
	}
	// ������ ���ڿ� �°� �÷��� ����
	switch (Choice)
	{
	case 0: // 0~2
		for (int i = 0; i < 9; i++)
		{
			if (i < 3)
				MyMenu[i].Color = 5;
			else
				MyMenu[i].Color = 8;
		}
		break;
	case 1: // 3~5
		for (int i = 0; i < 9; i++)
		{
			if (i < 3)
				MyMenu[i].Color = 8;
			if (2 < i)
				MyMenu[i].Color = 5;
			if (5 < i)
				MyMenu[i].Color = 8;
		}
		break;
	case 2: // 6~8
		for (int i = 0; i < 9; i++)
		{
			if (i < 6)
				MyMenu[i].Color = 8;
			else
				MyMenu[i].Color = 5;
		}
		break;
	}
	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (Choice)
		{
		case 0:
			SceneManager::GetInstance()->SetScene(SCENEID_STAGE);
			break;
		case 1:
			SceneManager::GetInstance()->SetScene(SCENEID_HOWTO);
			break;
		case 2:
			exit(NULL);
			break;
		}
	}
}

void Menu::Render()
{
	// �� 
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y, (char*)"          __ _ __,", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 1, (char*)"      .--         --.", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 2, (char*)"   ./    ()      .-.  *.", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 3, (char*)"  /    o    .   (   )  �� ", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 4, (char*)" /  .            '-'    �� ", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 5, (char*)" | ()    .  O         .  |", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 6, (char*)"|    o           ()       |", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 7, (char*)"|       .--.          O   |", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 8, (char*)" | .   |    |            |", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 9, (char*)"  *    `.__.'    o   .   / ", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 10, (char*)"   ��                   /", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 11, (char*)"   `��  o    ()       /'", 6);
	DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 12, (char*)"       `--___ _ ___--'", 6);

	// �޴�
	for (int i = 0; i < 9; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			MyMenu[i].TransPos.Position.x,
			MyMenu[i].TransPos.Position.y,
			MyMenu[i].Texture, MyMenu[i].Color);
	}

	// ĳ����
	for (int i = 0; i < 4; i++)
	{
		DoubleBuffer::GetInstance()->WriteBuffer(
			MyPlayer[i].TransPos.Position.x,
			MyPlayer[i].TransPos.Position.y,
			MyPlayer[i].Texture, 5);
	}

}

void Menu::Release()
{
}
