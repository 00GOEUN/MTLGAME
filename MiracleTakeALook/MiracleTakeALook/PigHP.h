#pragma once
#include "Object.h"

class PigHP : public Object
{
private:
	char* Texture[3];
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	PigHP();
	virtual ~PigHP();

};


