#pragma once

// �Է� �޴� �Ϳ� ���� ó���� �ٸ�����
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
	Vector3 Position; // ������ : ��ġ
	Vector3 Scale; // ������ : ũ���ΰ�
};

typedef struct TagLogo
{
	Transform TransPos; 
	char* Texture;
	int Color;
}LOGO, MENU, HOWTO, WIN, OVER;