#include "MainUpdate.h"
#include "SceneManager.h"
#include "InputManager.h"
#include "DoubleBuffer.h"

MainUpdate::MainUpdate()
{
}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Initialize()
{
	// ÁöÁ¤ÇÑ ConsolÀÇ ³ôÀÌ, ³ÐÀÌ ¸¸µé¾î?
	DoubleBuffer::GetInstance()->CreateBuffer(
		CONSOL_MAX_WIDTH, CONSOL_MAX_HEIGHT);

	SceneManager::GetInstance()->SetScene(SCENEID_LOGO); // ÇØ´ç ¾ÀÀ¸·Î ÀÌµ¿
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->CheckKey(); // Å° ÀÔ·Â Ã¼Å©
	SceneManager::GetInstance()->Update(); // ¾À ¾÷µ« ºÒ·¯¿È

	DoubleBuffer::GetInstance()->FlippingBuffer(); // ¤±¤©
	DoubleBuffer::GetInstance()->ClearBuffer(); // »èÁ¦?
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render(); // ¾À ·»´õ ºÒ·¯¿È
}

void MainUpdate::Release()
{
	SceneManager::GetInstance()->Release(); // ¾À ¸±¸®Áî ºÒ·¯¿È
	DoubleBuffer::GetInstance()->DestroyBuffer(); // ¤±¤©
}