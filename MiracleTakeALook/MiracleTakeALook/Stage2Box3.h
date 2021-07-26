#pragma once
#include "Object.h"

class Stage2Box3 : public Object
{
private:
	char* Texture[22];
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Stage2Box3();
	virtual ~Stage2Box3();
};


