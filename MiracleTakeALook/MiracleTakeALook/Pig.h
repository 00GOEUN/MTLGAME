#pragma once
#include "Object.h"

class Pig : public Object
{
private:
	float Speed;
	float PosX[2];
public:
	virtual void Initialize()override { strKey = "Pig"; }
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
	Pig();
	virtual ~Pig();
};

