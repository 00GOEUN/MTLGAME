#pragma once
#include "Object.h"

class Floor : public Object
{
private:
	char* Texture[8];
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Floor();
	virtual ~Floor();
};


