#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>

// 실행 오류
// 엑셀 설치 중..

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
		cout << "국어 점수 : " << iter->Kor << endl;
		cout << "영어 점수 : " << iter->Eng << endl;
		cout << "수학 점수 : " << iter->Math << endl << endl;
	}

	//** 읽어온 데이터를 각각의 점수에 따라 내림차순 정렬을 할것이다.
	//** 국어, 영어, 수학 점수별로 선택한 후 선택된 과목의 점수를 내림차순 정렬할것.
	
	int pick;

	while (true)
	{
		cout << "1. 국어 2. 영어 3. 수학 4. 종료\n선택: "; cin >> pick;
	
	}

	switch (pick)
	{
	case 1: // ??
		
		break;
	case 2: // 정렬
		pick = 0;
		cout << "1. 국어 점수 정렬" << endl;
		cout << "2. 영어 점수 정렬" << endl;
		cout << "3. 수학 점수 정렬" << endl;
		cout << "선택: "; cin >> pick;
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
	case 3: // 종료
		exit(NULL);
		break;
	}

	return 0;
}


void LoadDate()
{
	//** 에디터를 불러온다.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** 파일을 완전이 읽어온다.
	while (!feof(pFileCSV))
	{
		StudentInfo Info;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&Info.Index, &Info.Kor, &Info.Eng, &Info.Math, buffer);


		//** 읽어온 문자열을 포인터에 맞게 변경한다.
		Info.Name = new char[4];
		strcpy(Info.Name, buffer);

		//** 리스트에 추가한다.
		StudentList.push_back(Info);
	}

	//** 파일을 닫는다.
	fclose(pFileCSV);
}