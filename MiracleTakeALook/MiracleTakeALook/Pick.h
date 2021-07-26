#pragma once
#include "Object.h"

class Pick : public Object
{
private:
	char* Texture[5];
	int Index;
	int Color;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(const int& _index) { Index = _index; }
	void SetColor(const int& _color) { Color = _color; }
public:
	Pick();
	virtual ~Pick();
};

