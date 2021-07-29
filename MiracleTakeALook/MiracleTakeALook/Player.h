#pragma once
#include "Object.h"

class Player : public Object
{
private:
	int Index;
	bool m_Jump; // ���� �Լ�
	bool m_JumpDown; // ���� �������� �� �Լ�
	float m_Power; // �����ϴ� �Ŀ�

	float m_OldY; // �����ϱ� �� y��ǥ

	float m_Time; // �����ϴ� �ð�?
	Object* m_Bullet[128];
	Object* m_pPickBullet; // ���� ���� 
	int PickBullet;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	bool GetJumpDown() const { return m_JumpDown; }
	void SetJumpDown(const bool& _JumpDown)  { m_JumpDown = _JumpDown; }
	void SetJump(const bool& _Jump)  { m_Jump = _Jump; }

	void CheckKey(); // Ű �Է� Ȯ��
	void CheckJump(); // ���� Ȯ��
	void SetIndex(const int& _Index) { Index = _Index; } // ���� ����
public:
	Player();
	virtual ~Player();
};

