#pragma once
#include "Scene.h"
class Win : public Scene
{
protected:
	Transform TransInfo;
private:
	WIN MyWin[15]; // Win ¹è¿­

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	Win();
	virtual ~Win();
};