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

	 TransInfo.Position = Vector3(0, 0); // 위치 초기화

	 // MyLogo 배열에 로고 디자인 넣음 
	 MyOver[0].Texture = (char*)" _______ _______ _______ _______      _______ ___ ___ _______ ______ ";
	 MyOver[1].Texture = (char*)"|     __|   _   |   |   |    ___|    |       |   |   |    ___|   __ ↘ ";
	 MyOver[2].Texture = (char*)"|    |  |       |       |    ___|    |   -   |   |   |    ___|      <";
	 MyOver[3].Texture = (char*)"|_______|___|___|__|_|__|_______|    |_______|↘_____/|_______|___|__|";

	 MyOver[4].Texture = (char*)"☆ Push Enter ☆";

	 // 
	 for (int i = 0; i < 5; i++)
	 {
		 // 5보다 작은 것의 위치 지정과 크기 초기화
		 if (i < 4)
		 {
			 MyOver[i].TransPos.Position = Vector3(24.0f, 8.0f + (float)i);
			 MyOver[i].TransPos.Scale = Vector3(strlen(MyOver[2].Texture), 4.0f);
		 }
		 // 4보다 큰 것의 위치 지정과 크기 초기화
		 else
		 {
			 MyOver[i].TransPos.Position = Vector3(50.0f, 20.0f + (float)i);
			 MyOver[i].TransPos.Scale = Vector3(strlen(MyOver[4].Texture), 1.0f);
		 }
	 }
 }

 void Over::Update()
 {
	 // 엔터를 누르면 Menu로 이동
	 if (GetAsyncKeyState(VK_RETURN))
		 exit(NULL);
 }

 void Over::Render()
 {
	 //// 8~12
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 15, (char*)"  /↘	  ", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 16, (char*)"  /  ↘  ", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 17, (char*)" --^--^--", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 18, (char*)" ( ㅠㅅㅠ)★", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 19, (char*)"~/__/↖↘/", 4);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 20, (int)TransInfo.Position.y + 20, (char*)"   U U", 4);

	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 17, (char*)"  ^ -^", 6);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 18, (char*)" (  ;ㅅ;)", 6);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 19, (char*)"~(   x )", 6);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 42, (int)TransInfo.Position.y + 20, (char*)"   U U", 6);

	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 17, (char*)"  ^- ^", 3);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 18, (char*)"(;ㅅ;  )", 3);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 19, (char*)" ( x   )~", 3);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 64, (int)TransInfo.Position.y + 20, (char*)"   U U", 3);

	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 15, (char*)"      ↙↘", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 16, (char*)"    ↙  ↘", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 17, (char*)"  --^--^--", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 18, (char*)"★(ㅠㅅㅠ )", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 19, (char*)" ↖//↖__↘~", 9);
	 DoubleBuffer::GetInstance()->WriteBuffer((int)TransInfo.Position.x + 86, (int)TransInfo.Position.y + 20, (char*)"     U U", 9);

	 // 출력함 x,y,출력할 것, 색상
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
