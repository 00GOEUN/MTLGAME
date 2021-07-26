#pragma once
#include "Object.h"

class Stage2Box1 : public Object
{
private:
	char* Texture[2];
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage2Box1();
	virtual ~Stage2Box1();
};


