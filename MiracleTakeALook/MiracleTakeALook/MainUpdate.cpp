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
	// ������ Consol�� ����, ���� �����?
	DoubleBuffer::GetInstance()->CreateBuffer(
		CONSOL_MAX_WIDTH, CONSOL_MAX_HEIGHT);

	SceneManager::GetInstance()->SetScene(SCENEID_LOGO); // �ش� ������ �̵�
}

void MainUpdate::Update()
{
	InputManager::GetInstance()->CheckKey(); // Ű �Է� üũ
	SceneManager::GetInstance()->Update(); // �� ���� �ҷ���

	DoubleBuffer::GetInstance()->FlippingBuffer(); // ����
	DoubleBuffer::GetInstance()->ClearBuffer(); // ����?
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render(); // �� ���� �ҷ���
}

void MainUpdate::Release()
{
	SceneManager::GetInstance()->Release(); // �� ������ �ҷ���
	DoubleBuffer::GetInstance()->DestroyBuffer(); // ����
}