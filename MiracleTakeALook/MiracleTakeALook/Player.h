#pragma once
#include "Object.h"

class Player : public Object
{
private:
	int Index;
	bool m_Jump; // 점프 함수
	bool m_JumpDown; // 점프 내려가는 중 함수
	float m_Power; // 점프하는 파워

	float m_OldY; // 점프하기 전 y좌표

	float m_Time; // 점프하는 시간?
	Object* m_Bullet[128];
	Object* m_pPickBullet; // 공격 선택 
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

	void CheckKey(); // 키 입력 확인
	void CheckJump(); // 점프 확인
	void SetIndex(const int& _Index) { Index = _Index; } // 공격 선택
public:
	Player();
	virtual ~Player();
};

