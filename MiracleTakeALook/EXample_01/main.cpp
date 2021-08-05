#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>

// ���� ����
// ���� ��ġ ��..

using namespace std;

struct StudentInfo
{
	char* Name;
	int Index;

	int Kor;
	int Eng;
	int Math;
};



list<StudentInfo> StudentList;

void LoadDate();

int main(void)
{
	LoadDate();

	for (list<StudentInfo>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << iter->Index << " : " << iter->Name << endl;
		cout << "���� ���� : " << iter->Kor << endl;
		cout << "���� ���� : " << iter->Eng << endl;
		cout << "���� ���� : " << iter->Math << endl << endl;
	}

	//** �о�� �����͸� ������ ������ ���� �������� ������ �Ұ��̴�.
	//** ����, ����, ���� �������� ������ �� ���õ� ������ ������ �������� �����Ұ�.
	
	int pick;

	while (true)
	{
		cout << "1. ���� 2. ���� 3. ���� 4. ����\n����: "; cin >> pick;
	
	}

	switch (pick)
	{
	case 1: // ??
		
		break;
	case 2: // ����
		pick = 0;
		cout << "1. ���� ���� ����" << endl;
		cout << "2. ���� ���� ����" << endl;
		cout << "3. ���� ���� ����" << endl;
		cout << "����: "; cin >> pick;
		switch (pick)
		{
		case 1:


			break;
		case 2:

			break;
		case 3:

			break;
		}

		break;
	case 3: // ����
		exit(NULL);
		break;
	}

	return 0;
}


void LoadDate()
{
	//** �����͸� �ҷ��´�.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** ������ ������ �о�´�.
	while (!feof(pFileCSV))
	{
		StudentInfo Info;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&Info.Index, &Info.Kor, &Info.Eng, &Info.Math, buffer);


		//** �о�� ���ڿ��� �����Ϳ� �°� �����Ѵ�.
		Info.Name = new char[4];
		strcpy(Info.Name, buffer);

		//** ����Ʈ�� �߰��Ѵ�.
		StudentList.push_back(Info);
	}

	//** ������ �ݴ´�.
	fclose(pFileCSV);
}