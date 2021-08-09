#include <iostream>

using namespace std;

// 삭제 '형태 &' 붙여주기
// 레퍼런스 함수에는 r을 붙여줌 ex) rObj
template <typename T>
inline void Safe_Relase(T& _rObj)
{						
		if (_rObj)		
		{				
			delete _rObj;
			_rObj = NULL;
		}				
}

#define SAFE_DELETE(_Obj){	\
	Safe_Relase(_Obj);		\
}


// singlrton
#define DECLARE_SINGLETON(type)					\
static type** GetInstance()						\
{												\
	static type* pInstance = new type;			\
												\
	if (pInstance == NULL)						\
		pInstance = new type;					\
	return &pInstance;							\
}												\
static void	DestroyInstance()					\
{												\
	type** ppInstance = GetInstance();			\
												\
	if ((*ppInstance) != NULL)					\
	{											\
		delete *ppInstance;						\
		ppInstance = NULL;						\
	}											\
}

// 상수, 정수

#define MAX 128

#define Output(str) cout << str << endl;

#define Output2(x,y) cout << (x+y) << endl;

// 함수를 상수화
// \ : 다음 줄을 같은 줄로 인식
#define Output3(x, y)			\
{								\
	cout << (x + y) << endl;	\
}

#define GETSINGLETON(type) (*type::GetInstance())
#define DESTROYSINGLETON(type) (*type::GetInstance())->DestroyInstance()


class Object 
{
public:
	DECLARE_SINGLETON(Object)
public:
	int Number;
	void Output4() {cout << "Object" << endl; }

public:
	Object() {}
	~Object() {}

};









int main(void)
{
	// 배열의 길이는 상수와 정수 두가지 조건이 모두 참인 경우에만 초기값 사용 가능
	// int Array[MAX];

	// Output
	Output("Hello World!!");

	// Output2
	// 문자열을 사용해야하는 경우 string을 사용
	Output2(10, 20);
	string str1 = "Hello ";
	string str2 = "World!!";
	Output2(str1, str2);

	int Num1 = 10;
	int Num2 = 20;
	Output2(Num1, Num2);

	// Output3 // 함수 뒤에는 ; 필요X
	Output3(Num1, Num2);

	// SAFE_DELETE 안되는 듯??
	/*
	
	Object* pObj = new Object;
	pObj->Output4();

	// 방법 1
	SAFE_DELETE(pObj);
	pObj->Output4();

	// 방법 2
	delete pObj;
	pObj = NULL;
	pObj->Output4();
	*/

	GETSINGLETON(Object)->Number = 10;
	GETSINGLETON(Object)->Output4();

	cout << GETSINGLETON(Object)->Number << endl;

	DESTROYSINGLETON(Object);


		return 0;
};