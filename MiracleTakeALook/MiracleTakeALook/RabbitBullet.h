#pragma once
#include "Object.h"

class RabbitBullet : public Object
{
private:
	//int Count; // ������ ī��Ʈ �ϴ°�
	Object* Target; // Pig�� Ÿ������ �Ұǵ�.. �����̳�!!


public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetTarget(Object* _Target) { Target = _Target; } // Ÿ���� �޾Ƽ� ������ �ϴ°ɱ��,,?
public:
	RabbitBullet();
	virtual ~RabbitBullet();
};

