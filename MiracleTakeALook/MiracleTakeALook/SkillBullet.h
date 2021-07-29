#pragma once
#include "Object.h"
class SkillBullet : public Object
{
private:
	//char* Texture[0][4]; // Texture�� [0]~ [3]��ŭ ����
	Object* Target;
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetTarget(Object* _Target) { Target = _Target; }
public:
	SkillBullet();
	virtual ~SkillBullet();
};

