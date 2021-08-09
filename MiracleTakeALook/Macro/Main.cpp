#include <iostream>

using namespace std;

// 상수, 정수

#define MAX 128

#define Output(str) cout << str << endl;

#define Output2(x,y) cout << (x+y) << endl;

// 삭제
//#define Safe_Delete(Obj)
// 함수를 상수화
// \ : 다음 줄을 같은 줄로 인식

#define Output3(x, y)			\
{								\
	cout << (x + y) << endl;	\
}

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
	Output3(Num1, Num2)
	


	return 0;
}