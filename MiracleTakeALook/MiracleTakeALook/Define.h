#pragma once

// SAFE_RELEASE(함수)가 들어오면 삭제해줌
template <typename T>
inline void Safe_Release(T& _Obj)
{
	if (_Obj)
	{
		delete _Obj;
		_Obj = NULL;
	}
}

#define SAFE_RELEASE(obj) Safe_Release(obj)