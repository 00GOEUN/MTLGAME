#include <iostream>
#include <string>

using namespace std;


int main(void)
{
	// ������ ���ڿ� �ʱ�ȭ.
	string str1 = "Hello";
	string str2 = "World!!";

	// ���� ���ڿ������͸� �����Ͽ� �ʱ�ȭ.
	string str3 = str1 + " " + str2;
	cout << str3 << endl;

	// ��� ������ ����
	str3.clear();

	// ������ ���ڿ��� ����
	int Num = 100;
	str3 = to_string(Num);
	cout << str3 << endl;

	// char* ������ ���ڿ���  string ���¿� �߰�.
	char* Buffer = (char*)"\n���� �մϴ�. \n100 �� �Դϴ�.";
	str3 += Buffer;
	cout << str3 << endl;

	// ���ڿ� ��
	string string1 = "AA";
	string string2 = "AA";

	if (string1 == string2)
		cout << "����.";
	else
		cout << "�ٸ���.";

	return 0;
}