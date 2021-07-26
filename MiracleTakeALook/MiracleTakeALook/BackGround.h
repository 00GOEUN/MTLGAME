#pragma once
#include "Object.h"

class BackGround : public Object
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	BackGround();
	virtual ~BackGround();
};

