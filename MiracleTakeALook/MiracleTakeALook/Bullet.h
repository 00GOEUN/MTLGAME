#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	//int Count; // 무엇을 카운트 하는가
	Object* Target; // Pig를 타겟으로 할건뎅.. 무엇이냐!!
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public: 
	void SetTarget(Object* _Target) { Target = _Target; } // 타겟을 받아서 삭제를 하는걸까용,,?
public:
	Bullet();
	virtual ~Bullet();
};

