#include <iostream>

using namespace std;

// ���� '���� &' �ٿ��ֱ�
// ���۷��� �Լ����� r�� �ٿ��� ex) rObj
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

// ���, ����

#define MAX 128

#define Output(str) cout << str << endl;

#define Output2(x,y) cout << (x+y) << endl;

// �Լ��� ���ȭ
// \ : ���� ���� ���� �ٷ� �ν�
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
	// �迭�� ���̴� ����� ���� �ΰ��� ������ ��� ���� ��쿡�� �ʱⰪ ��� ����
	// int Array[MAX];

	// Output
	Output("Hello World!!");

	// Output2
	// ���ڿ��� ����ؾ��ϴ� ��� string�� ���
	Output2(10, 20);
	string str1 = "Hello ";
	string str2 = "World!!";
	Output2(str1, str2);

	int Num1 = 10;
	int Num2 = 20;
	Output2(Num1, Num2);

	// Output3 // �Լ� �ڿ��� ; �ʿ�X
	Output3(Num1, Num2);

	// SAFE_DELETE �ȵǴ� ��??
	/*
	
	Object* pObj = new Object;
	pObj->Output4();

	// ��� 1
	SAFE_DELETE(pObj);
	pObj->Output4();

	// ��� 2
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