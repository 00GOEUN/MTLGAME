#pragma once
#include "Object.h"

class Rabbit : public Object
{
private:
	float Speed;
	ULONG Time;
	ULONG BulletTime;
	Object* m_Bullet[128];
	float PosX[2];
public:
	virtual void Initialize()override { strKey = "Rabbit"; }
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetRightPos(const float& _x)
	{
		PosX[0] = _x;
	}

	void SetLeftPos(const float& _x)
	{
		PosX[1] = _x;
	}
public:
	Rabbit();
	virtual ~Rabbit();
};

