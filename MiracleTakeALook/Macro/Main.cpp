#include <iostream>

using namespace std;

// ���, ����

#define MAX 128

#define Output(str) cout << str << endl;

#define Output2(x,y) cout << (x+y) << endl;

// ����
//#define Safe_Delete(Obj)
// �Լ��� ���ȭ
// \ : ���� ���� ���� �ٷ� �ν�

#define Output3(x, y)			\
{								\
	cout << (x + y) << endl;	\
}

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
	Output3(Num1, Num2)
	


	return 0;
}