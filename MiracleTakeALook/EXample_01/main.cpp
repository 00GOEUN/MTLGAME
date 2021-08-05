#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>

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
void ScoreSwap(StudentInfo& _A, StudentInfo& _B);

int main(void)
{
	LoadDate();

	

	//** �о�� �����͸� ������ ������ ���� �������� ������ �Ұ��̴�.
	//** ����, ����, ���� �������� ������ �� ���õ� ������ ������ �������� �����Ұ�.
	

	while (true)
	{
		int pick;
		cout << "1. ��ü ��� 2. ���� ���(��������) 3. ����\n����: "; cin >> pick;
	

		switch (pick)
		{
		case 1: // ��ü ���
			for (list<StudentInfo>::iterator iter = StudentList.begin();
				iter != StudentList.end(); ++iter)
			{
				cout << iter->Index << " : " << iter->Name << endl;
				cout << "���� ���� : " << iter->Kor << endl;
				cout << "���� ���� : " << iter->Eng << endl;
				cout << "���� ���� : " << iter->Math << endl << endl;
			}
			break;
		case 2: // ����
			int pick;
			cout << "1. ���� ���� ���� 2. ���� ���� ���� 3. ���� ���� ����\n����: "; cin >> pick;
			switch (pick)
			{
			case 1: // ����
				for (list<StudentInfo>::iterator iter = StudentList.begin();
					iter != StudentList.end(); ++iter)
				{
					for (list<StudentInfo>::iterator iter2 = iter;
						iter2 != StudentList.end(); ++iter2)
					{
						if ((*iter).Kor < (*iter2).Kor)
						{
							ScoreSwap((*iter), (*iter2));

						}
					}
					cout << iter->Name << " : " << iter->Kor << endl;
				}
				break;
			case 2: // ����
				for (list<StudentInfo>::iterator iter = StudentList.begin();
					iter != StudentList.end(); ++iter)
				{
					for (list<StudentInfo>::iterator iter2 = iter;
						iter2 != StudentList.end(); ++iter2)
					{
						if ((*iter).Eng < (*iter2).Eng)
						{
							ScoreSwap((*iter), (*iter2));

						}
					}
					cout << iter->Name << " : " << iter->Eng << endl;
				}
				break;
			case 3: // ����
				for (list<StudentInfo>::iterator iter = StudentList.begin();
					iter != StudentList.end(); ++iter)
				{
					for (list<StudentInfo>::iterator iter2 = iter;
						iter2 != StudentList.end(); ++iter2)
					{
						if ((*iter).Math < (*iter2).Math)
						{
							ScoreSwap((*iter), (*iter2));

						}
					}
					cout << iter->Name << " : " << iter->Math << endl;
				}
				break;
			}

			break;
		case 3: // ����
			exit(NULL);
			break;
		}
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

		fscanf(pFileCSV, "%d,%d,%d,%d, %s",
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

void ScoreSwap(StudentInfo& _A, StudentInfo& _B)
{
	StudentInfo Tmp = _A;

	_A = _B;
	_B = Tmp;
}