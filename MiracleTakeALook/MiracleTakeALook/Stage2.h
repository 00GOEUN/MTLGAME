#pragma once
#include "Scene.h"

class Object;
class Stage2 : public Scene
{
private:
	int Choice; // 공격 선택
	Object* m_pBackGround; // 배경
	Object* m_pStage; // 스테이지
	Object* m_pPlayerHp; // 플레이어 HP
	Object* m_pPick[2]; // 공격 선택 배열

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage2();
	virtual ~Stage2();
};

