#include "Over.h"
#include "DoubleBuffer.h"
#include "SceneManager.h"

Over::Over()
 {
 }

 Over::~Over()
 {
 }

 void Over::Initialize()
 {

	 TransInfo.Position = Vector3(0, 0); // ��ġ �ʱ�ȭ

	 // MyLogo �迭�� �ΰ� ������ ���� 
	 MyOver[0].Texture = (char*)" _______ _______ _______ _______      _______ ___ ___ _______ ______ ";
	 MyOver[1].Texture = (char*)"|     __|   _   |   |   |    ___|    |       |   |   |    ___|   __ �� ";
	 MyOver[2].Texture = (char*)"|    |  |       |       |    ___|    |   -   |   |   |    ___|      <";
	 MyOver[3].Texture = (char*)"|_______|___|___|__|_|__|_______|    |_______|��_____/|_______|___|__|";

	 MyOver[4].Texture = (char*)"�� Push Enter ��";

	 // 
	 for (int i = 0; i < 5; i++)
	 {
		 // 5���� ���� ���� ��ġ ������ ũ�� �ʱ�ȭ
		 if (i < 4)
		 {
			 MyOver[i].TransPos.Position = Vector3(24.0f, 8.0f + (float)i);
			 MyOver[i].TransPos.Scale = Vector3(strlen(MyOver[2].Texture), 4.0f);
		 }
		 // 4���� ū ���� ��ġ ������ ũ�� �ʱ�ȭ
		 else
		 {
			 MyOver[i].TransPos.Position = Vector3(50.0f, 20.0f + (float)i);
			 MyOver[i].TransPos.Scale = Vector3(strlen(MyOver[4].Texture), 1.0f);
		 }
	 }
 }

 void Over::Update()
 {
	 // ���͸� ������ Menu�� �̵�
	 if (GetAsyncKeyState(VK_RETURN))
		 exit(NULL);
 }

 void Over::Render()
 {
	 //// 8~12
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 15, (char*)"  /��	  ", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 16, (char*)"  /  ��  ", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 17, (char*)" --^--^--", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 18, (char*)" ( �Ф���)��", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 19, (char*)"~/__/�آ�/", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 20, (char*)"   U U", 4);

	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 17, (char*)"  ^ -^", 6);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 18, (char*)" (  ;��;)", 6);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 19, (char*)"~(   x )", 6);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 20, (char*)"   U U", 6);

	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 17, (char*)"  ^- ^", 3);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 18, (char*)"(;��;  )", 3);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 19, (char*)" ( x   )~", 3);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 20, (char*)"   U U", 3);

	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 15, (char*)"      �ע�", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 16, (char*)"    ��  ��", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 17, (char*)"  --^--^--", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 18, (char*)"��(�Ф��� )", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 19, (char*)" ��//��__��~", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 20, (char*)"     U U", 9);

	 // ����� x,y,����� ��, ����
	 for (int i = 0; i < 5; i++)
	 {
		 DoubleBuffer::GetInstance()->WriteBuffer(
			 MyOver[i].TransPos.Position.x,
			 MyOver[i].TransPos.Position.y,
			 MyOver[i].Texture, 5);
		 if (i == 4)
		 {
			 DoubleBuffer::GetInstance()->WriteBuffer(
				 MyOver[i].TransPos.Position.x,
				 MyOver[i].TransPos.Position.y,
				 MyOver[i].Texture, 8);
		 }
	 }
 }

 void Over::Release()
 {
 }
