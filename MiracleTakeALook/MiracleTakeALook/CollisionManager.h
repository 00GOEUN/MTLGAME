#pragma once
#include "Headers.h"

class CollisionManager
{
public:
	/*
	// _Temp: 몬스터 _Dest: 공격
	static bool CollisionRact(const Transform& _Temp, const Transform& _Dest)
	{
		// 몬스터와 공격이 접촉하면
			// 몬스터 위치x + (몬스터 크기x/2) 가 공격 위치x - (공격 크기x/2) 보다  같거나 클때
		if ((_Temp.Position.x + (_Temp.Scale.x / 2)) >= (_Dest.Position.x - (_Dest.Scale.x / 2)) &&
			// 공격 위치x + (공격 크기x/2) 가 몬스터 위치x - (몬스터 크기x/2) 보다 같거나 클때 
			(_Dest.Position.x + (_Dest.Scale.x / 2)) >= (_Temp.Position.x - (_Temp.Scale.x / 2)) &&
			// 몬스터 위치y + (몬스터 크기y/2) 가 공격 위치y - (공격 크기y/2)보다 같거나 클때
			(_Temp.Position.y + (_Temp.Scale.y / 2)) >= (_Dest.Position.y - (_Dest.Scale.y / 2)) &&
			// 공격 위치y + (공격 크기y/2) 가 몬스터 위치y - (몬스터 크기y/2)보다 같거나 클때
			(_Dest.Position.y + (_Dest.Scale.y / 2)) >= (_Temp.Position.y - (_Temp.Scale.y / 2)))
			return true; // true로 리턴
		// 아니면 false로 리턴
		return false;
	}
	*/




	static bool CollisionLine(const Transform& _Temp, const Transform& _Dest)
	{
		if (_Temp.Position.x <= (_Dest.Position.x + _Dest.Scale.x) &&
			_Dest.Position.x <= (_Temp.Position.x + _Temp.Scale.x) )
			return true; // true로 리턴
		// 아니면 false로 리턴
		return false;
	}


	static bool CollisionRact(const Transform& _Temp, const Transform& _Dest)
	{
		if (_Temp.Position.x <= (_Dest.Position.x + _Dest.Scale.x ) &&
			_Dest.Position.x <= (_Temp.Position.x + _Temp.Scale.x) &&
			_Temp.Position.y <= (_Dest.Position.y + _Dest.Scale.y) &&
			_Dest.Position.y <= (_Temp.Position.y + _Temp.Scale.y) )
			return true; // true로 리턴
		// 아니면 false로 리턴
		return false;
	}
};