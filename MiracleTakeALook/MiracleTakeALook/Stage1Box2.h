#pragma once
#include "Object.h"

class Stage1Box2 : public Object
{
private:
	char* Texture[3];
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage1Box2();
	virtual ~Stage1Box2();
};


