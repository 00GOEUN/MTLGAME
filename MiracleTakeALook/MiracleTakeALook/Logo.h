#pragma once
#include "Scene.h"

class Logo : public Scene
{
protected:
	Transform TransInfo;

private:
	LOGO MyLogo[11]; // MyLogo �迭
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;

public: //  ����!!! ���ı�!!! ����!!!!!!! �𸣰ڴٰ�!!!
	Transform GetTransform() const { return TransInfo; }

public:
	Logo();
	virtual ~Logo();
};

