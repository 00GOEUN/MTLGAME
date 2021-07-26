#pragma once
#include "Object.h"

class Stage2Box2 : public Object
{
private:
	char* Texture[7];
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage2Box2();
	virtual ~Stage2Box2();
};


