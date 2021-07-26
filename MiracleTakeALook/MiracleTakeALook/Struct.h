#pragma once

// 입력 받는 것에 따라 처리를 다르게함
struct Vector3
{
	float x, y, z;

	Vector3() {};

	Vector3(float _x, float _y)
		: x(_x), y(_y), z(0) {};

	Vector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {};

};


struct Transform
{
	Vector3 Position; // 포지션 : 위치
	Vector3 Scale; // 스케일 : 크기인가
};

typedef struct TagLogo
{
	Transform TransPos; 
	char* Texture;
	int Color;
}LOGO, MENU, HOWTO, WIN, OVER;