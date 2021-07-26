#pragma once
#include "Scene.h"

class Object;
class Stage2 : public Scene
{
private:
	int Choice; // ���� ����
	Object* m_pBackGround; // ���
	Object* m_pStage; // ��������
	Object* m_pPlayerHp; // �÷��̾� HP
	Object* m_pPick[2]; // ���� ���� �迭

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage2();
	virtual ~Stage2();
};

