#pragma once
#include "Scene.h"
class Over : public Scene
{
protected:
	Transform TransInfo;
private:
	OVER MyOver[15]; // OVER ¹è¿­

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Over();
	virtual ~Over();
};