#pragma once
#include "Scene.h"
class HowTo : public Scene
{
private:
	HOWTO MyHowTo[15]; // HowTo ¹è¿­

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	HowTo();
	virtual ~HowTo();
};