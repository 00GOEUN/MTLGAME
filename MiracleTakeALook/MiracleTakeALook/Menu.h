#pragma once
#include "Scene.h"
#include "Object.h"
class Menu :public Scene
{
protected:
	// 달, 캐릭터
	Transform TransInfo;
	bool Active; // 이건 뭐야? 활동?
private:
	MENU MyMenu[9]; // Mymenu 배열 생성
	int Choice; // 선택
	MENU MyPlayer[4];
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render()override;
	virtual void Release()override;
public: //  뭔데!!! 뭐냐교!!! 뭔데!!!!!!! 모르겠다고!!!
	Transform GetTransform() const { return TransInfo; }

	Vector3 GetPosition() const { return TransInfo.Position; }
	void SetPosition(const float& _x, const float& _y) { TransInfo.Position.x = _x; TransInfo.Position.y = _y; }

	Vector3 GetScale() const { return TransInfo.Scale; }

	bool GetActive() const { return Active; }
	void SetActive(const bool& _Active) { Active = _Active; }
public:
	Menu();
	virtual ~Menu();
};

