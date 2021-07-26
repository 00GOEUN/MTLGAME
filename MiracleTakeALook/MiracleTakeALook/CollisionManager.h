#pragma once
#include "Headers.h"

class CollisionManager
{
public:
	/*
	// _Temp: ���� _Dest: ����
	static bool CollisionRact(const Transform& _Temp, const Transform& _Dest)
	{
		// ���Ϳ� ������ �����ϸ�
			// ���� ��ġx + (���� ũ��x/2) �� ���� ��ġx - (���� ũ��x/2) ����  ���ų� Ŭ��
		if ((_Temp.Position.x + (_Temp.Scale.x / 2)) >= (_Dest.Position.x - (_Dest.Scale.x / 2)) &&
			// ���� ��ġx + (���� ũ��x/2) �� ���� ��ġx - (���� ũ��x/2) ���� ���ų� Ŭ�� 
			(_Dest.Position.x + (_Dest.Scale.x / 2)) >= (_Temp.Position.x - (_Temp.Scale.x / 2)) &&
			// ���� ��ġy + (���� ũ��y/2) �� ���� ��ġy - (���� ũ��y/2)���� ���ų� Ŭ��
			(_Temp.Position.y + (_Temp.Scale.y / 2)) >= (_Dest.Position.y - (_Dest.Scale.y / 2)) &&
			// ���� ��ġy + (���� ũ��y/2) �� ���� ��ġy - (���� ũ��y/2)���� ���ų� Ŭ��
			(_Dest.Position.y + (_Dest.Scale.y / 2)) >= (_Temp.Position.y - (_Temp.Scale.y / 2)))
			return true; // true�� ����
		// �ƴϸ� false�� ����
		return false;
	}
	*/




	static bool CollisionLine(const Transform& _Temp, const Transform& _Dest)
	{
		if (_Temp.Position.x <= (_Dest.Position.x + _Dest.Scale.x) &&
			_Dest.Position.x <= (_Temp.Position.x + _Temp.Scale.x) )
			return true; // true�� ����
		// �ƴϸ� false�� ����
		return false;
	}


	static bool CollisionRact(const Transform& _Temp, const Transform& _Dest)
	{
		if (_Temp.Position.x <= (_Dest.Position.x + _Dest.Scale.x ) &&
			_Dest.Position.x <= (_Temp.Position.x + _Temp.Scale.x) &&
			_Temp.Position.y <= (_Dest.Position.y + _Dest.Scale.y) &&
			_Dest.Position.y <= (_Temp.Position.y + _Temp.Scale.y) )
			return true; // true�� ����
		// �ƴϸ� false�� ����
		return false;
	}
};