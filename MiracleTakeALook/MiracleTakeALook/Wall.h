#pragma once
#include "Object.h"

class Wall : public Object
{
private:
	char* Texture[128];
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Wall();
	virtual ~Wall();
};


