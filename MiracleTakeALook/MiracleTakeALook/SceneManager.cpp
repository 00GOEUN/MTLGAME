#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"
#include "Stage2.h"
#include "Stage3.h"
#include "HowTo.h"
#include "Win.h"
#include "Over.h"

SceneManager* SceneManager::m_pInstance = NULL;

SceneManager::SceneManager() : m_pSceneState(NULL)
{
}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(const SCENEID _SceneID)
{
	// 설정된 m_pSceneState를 삭제
	SAFE_RELEASE(m_pSceneState);

	switch (_SceneID)
	{
		// 들어온 SCENEID에 해당하는 것을 새로 생성해줌
	case SCENEID_LOGO:
		m_pSceneState = new Logo;
		break;
	case SCENEID_MENU:
		m_pSceneState = new Menu;
		break;
	case SCENEID_STAGE:
		m_pSceneState = new Stage;
		break;
	case SCENEID_STAGE2:
		m_pSceneState = new Stage2;
		break;
	case SCENEID_STAGE3:
		m_pSceneState = new Stage3;
		break;
	case SCENEID_HOWTO:
		m_pSceneState = new HowTo;
		break;
	case SCENEID_WIN:
		m_pSceneState = new Win;
		break;
	case SCENEID_OVER:
		m_pSceneState = new Over;
		break;
	case SCENEID_EXIT:
		exit(NULL);
		break;
	}

	m_pSceneState->Initialize(); // 해당하는 씬의 Initialize()를 가져옴

	Sleep(1500); // 속도임


}

void SceneManager::Update()
{
	// 해당 씬의 Update를 가져옴
	m_pSceneState->Update();
}

void SceneManager::Render()
{
	// 해당 씬의 Render를 가져옴
	m_pSceneState->Render();
}

void SceneManager::Release()
{
	// 저장된 씬 삭제
	SAFE_RELEASE(m_pSceneState);
}
