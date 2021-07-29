#pragma once
#include "Object.h"

class Dog : public Object
{
private:
	int Motion;
	int Motion_Max;
	int Check;
	int Vertical;
	ULONG Time;
	ULONG MotionTime;
	
	Object* m_Bullet[128];
	float Speed;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Dog();
	virtual ~Dog();
};

