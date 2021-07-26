#pragma once
#include "Scene.h"

class Logo : public Scene
{
protected:
	Transform TransInfo;

private:
	LOGO MyLogo[11]; // MyLogo ¹è¿­
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public: //  ¹ºµ¥!!! ¹¹³Ä±³!!! ¹ºµ¥!!!!!!! ¸ð¸£°Ú´Ù°í!!!
	Transform GetTransform() const { return TransInfo; }

public:
	Logo();
	virtual ~Logo();
};

