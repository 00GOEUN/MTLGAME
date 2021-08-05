#include <iostream>
#include <string>

using namespace std;


int main(void)
{
	// 별도의 문자열 초기화.
	string str1 = "Hello";
	string str2 = "World!!";

	// 기존 문자열데이터를 결합하여 초기화.
	string str3 = str1 + " " + str2;
	cout << str3 << endl;

	// 모든 데이터 삭제
	str3.clear();

	// 정수를 문자열로 변경
	int Num = 100;
	str3 = to_string(Num);
	cout << str3 << endl;

	// char* 형태의 문자열을  string 형태에 추가.
	char* Buffer = (char*)"\n축하 합니다. \n100 점 입니다.";
	str3 += Buffer;
	cout << str3 << endl;

	// 문자열 비교
	string string1 = "AA";
	string string2 = "AA";

	if (string1 == string2)
		cout << "같다.";
	else
		cout << "다르다.";

	return 0;
}