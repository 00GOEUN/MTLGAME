/*
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <fstream>
#include <Windows.h>

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

	

	//** 읽어온 데이터를 각각의 점수에 따라 내림차순 정렬을 할것이다.
	//** 국어, 영어, 수학 점수별로 선택한 후 선택된 과목의 점수를 내림차순 정렬할것.
	

	while (true)
	{
		int pick;
		cout << "1. 전체 출력 2. 선택 출력(내림차순) 3. 종료\n선택: "; cin >> pick;
	

		switch (pick)
		{
		case 1: // 전체 출력
			for (list<StudentInfo>::iterator iter = StudentList.begin();
				iter != StudentList.end(); ++iter)
			{
				cout << iter->Index << " : " << iter->Name << endl;
				cout << "국어 점수 : " << iter->Kor << endl;
				cout << "영어 점수 : " << iter->Eng << endl;
				cout << "수학 점수 : " << iter->Math << endl << endl;
			}
			break;
		case 2: // 선택
			int pick;
			cout << "1. 국어 점수 정렬 2. 영어 점수 정렬 3. 수학 점수 정렬\n선택: "; cin >> pick;
			switch (pick)
			{
			case 1: // 국어
				for (list<StudentInfo>::iterator iter = StudentList.begin();
					iter != StudentList.end(); ++iter)
				{
					for (list<StudentInfo>::iterator iter2 = iter;
						iter2 != StudentList.end(); ++iter2)
					{
						// 안됨1
						//if ((*iter).Kor < (*iter2).Kor)
						//{
						//	ScoreSwap((*iter), (*iter2));
						//}
						// 안됨2
						//StudentInfo Temp = (*iter);
						//(*iter) = (*iter2);
						//(*iter) = Temp;
					}
					cout << iter->Name << " : " << iter->Kor << endl;
				}
				break;
			case 2: // 영어
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
			case 3: // 수학
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
		case 3: // 종료
			exit(NULL);
			break;
		}
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

		fscanf(pFileCSV, "%d,%d,%d,%d, %s",
			&Info.Index, &Info.Kor, &Info.Eng, &Info.Math, buffer);


		//** 읽어온 문자열을 포인터에 맞게 변경한다.
		Info.Name = new char[4];
		strcpy(Info.Name, buffer);

		//** 리스트에 추가한다.
		StudentList.push_back(Info);
	}

	StudentList.pop_back();

	//** 파일을 닫는다.
	fclose(pFileCSV);
}

void ScoreSwap(StudentInfo& _A, StudentInfo& _B)
{
	StudentInfo Tmp = _A;

	_A = _B;
	_B = Tmp;
}

*/

/*
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



list<StudentInfo*> StudentList;

void LoadDate();
void Output();

int main(void)
{
	LoadDate();
	Output();

	int pick;

	cout << "입력: "; cin >> pick;

	list<StudentInfo*> SortList(StudentList);


	//** 읽어온 데이터를 각각의 점수에 따라 내림차순 정렬을 할것이다.
	//** 국어, 영어, 수학 점수별로 선택한 후 선택된 과목의 점수를 내림차순 정렬할것.


	while (true)
	{
		int pick;
		cout << "1. 전체 출력 2. 선택 출력(내림차순) 3. 종료\n선택: "; cin >> pick;


		switch (pick)
		{
		case 1: // 전체 출력
			for (list<StudentInfo*>::iterator iter = SortList.begin();
				iter != SortList.end(); ++iter)
			{
				for (list<StudentInfo*>::iterator iter2 = SortList.begin();
					iter2 != SortList.end(); ++iter2)
				{
					if ((*iter)->Kor > (*iter2)->Kor)
					{
						StudentInfo* pTemp = (*iter);
						(*iter) = (*iter2);
						(*iter2) = pTemp;
					}
				}
			}
			break;
		case 2: // 선택
			

			break;
		case 3: // 종료
			exit(NULL);
			break;
		}
	}
	cout << endl << endl;
	cout << "******************" << endl;
	for (list<StudentInfo*>::iterator iter = SortList.begin();
		iter != SortList.end(); ++iter)
	{
		cout << (*iter)->Index << " : " << (*iter)->Name << endl;
		cout << "국어 점수 : " << (*iter)->Kor << endl;
		cout << "영어 점수 : " << (*iter)->Eng << endl;
		cout << "수학 점수 : " << (*iter)->Math << endl << endl;
	}
	cout << "******************" << endl;

	Output();

	return 0;
}


void LoadDate()
{
	//** 에디터를 불러온다.
	FILE* pFileCSV = fopen("StudenInfoList.csv", "r");

	//** 파일을 완전이 읽어온다.
	while (!feof(pFileCSV))
	{
		StudentInfo* Info = new StudentInfo;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d, %s",
			// 포인터로 만들었을 경우 & 안 써도 됨
			&Info->Index, &Info->Kor, &Info->Eng, &Info->Math, buffer);


		//** 읽어온 문자열을 포인터에 맞게 변경한다.
		Info->Name = new char[4];
		strcpy(Info->Name, buffer);

		//** 리스트에 추가한다.
		StudentList.push_back(Info);
	}

	StudentList.pop_back();

	//** 파일을 닫는다.
	fclose(pFileCSV);
}

void Output()
{
	cout << endl << endl;
	cout << "******************" << endl;
	for (list<StudentInfo*>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << (*iter)->Index << " : " << (*iter)->Name << endl;
		cout << "국어 점수 : " << (*iter)->Kor << endl;
		cout << "영어 점수 : " << (*iter)->Eng << endl;
		cout << "수학 점수 : " << (*iter)->Math << endl << endl;
	}
	cout << "******************" << endl;
}
*/



/*
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


list<StudentInfo*> StudentList;
map<string, list<StudentInfo*>>  ScoreList;


void LoadDate();
void Output();


int main(void)
{
	LoadDate();

	//** 읽어온 데이터를 각각의 점수에 따라 내림차순 정렬을 할것이다.
	//** 국어, 영어, 수학 점수별로 선택한 후 선택된 과목의 점수를 내림차순 정렬할것.

	list<StudentInfo*> SortList(StudentList);

	while (true)
	{
		int Pick;
		cout << "1. 국어 2. 영어 3. 수학 4. 전체 5. 종료\n선택: "; cin >> Pick;

		system("cls");

		switch (Pick)
		{
		case 1: // 국어
			for (list<StudentInfo*>::iterator iter = SortList.begin();
				iter != SortList.end(); ++iter)
			{
				for (list<StudentInfo*>::iterator iter2 = iter;
					iter2 != SortList.end(); ++iter2)
				{
					if ((*iter)->Kor < (*iter2)->Kor)
					{
						StudentInfo* pTemp = (*iter);
						(*iter) = (*iter2);
						(*iter2) = pTemp;
					}
				}
				cout << (*iter)->Name << ":" << (*iter)->Kor << endl;
				list<StudentInfo*> TempList(SortList);
				ScoreList.insert(make_pair("Kor", TempList));
			}
			break;
		case 2: // 영어
			for (list<StudentInfo*>::iterator iter = SortList.begin();
				iter != SortList.end(); ++iter)
			{
				for (list<StudentInfo*>::iterator iter2 = iter;
					iter2 != SortList.end(); ++iter2)
				{
					if ((*iter)->Eng < (*iter2)->Eng)
					{
						StudentInfo* pTemp = (*iter);
						(*iter) = (*iter2);
						(*iter2) = pTemp;
					}
				}
				cout << (*iter)->Name << ":" << (*iter)->Eng << endl;
				list<StudentInfo*> TempList(SortList);
				ScoreList.insert(make_pair("Eng", TempList));
			}
			break;
		case 3: // 수학
			for (list<StudentInfo*>::iterator iter = SortList.begin();
				iter != SortList.end(); ++iter)
			{
				for (list<StudentInfo*>::iterator iter2 = iter;
					iter2 != SortList.end(); ++iter2)
				{
					if ((*iter)->Math < (*iter2)->Math)
					{
						StudentInfo* pTemp = (*iter);
						(*iter) = (*iter2);
						(*iter2) = pTemp;
					}
				}
				cout << (*iter)->Name << ":" << (*iter)->Math << endl;
				list<StudentInfo*> TempList(SortList);
				ScoreList.insert(make_pair("Math", TempList));
			}
			break;
		case 4: // 전체
			Output();
			break;
		case 5: // 종료
			exit(NULL);
			break;
		}

		for (map<string, list<StudentInfo*>>::iterator iter = ScoreList.begin();
			iter != ScoreList.end(); ++iter)
		{
			cout << "*******" << iter->first << "*******" << endl;

			for (list<StudentInfo*>::iterator iter2 = iter->second.begin();
				iter2 != iter->second.end(); ++iter2)
			{
				cout << (*iter2)->Index << " : " << (*iter2)->Name << endl;
				cout << "국어 점수 : " << (*iter2)->Kor << endl;
				cout << "영어 점수 : " << (*iter2)->Eng << endl;
				cout << "수학 점수 : " << (*iter2)->Math << endl << endl;
			}
			cout << "********************" << endl << endl;
		}

		// 이해하기
		//int Array[] = { 1, 2, 3, 4, 5 };
		//int* iter = Array;
		//iter++;

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
		StudentInfo* pInfo = new StudentInfo;

		char buffer[128] = "";

		fscanf(pFileCSV, "%d,%d,%d,%d,%s",
			&pInfo->Index, &pInfo->Kor, &pInfo->Eng, &pInfo->Math, buffer);

		//** 읽어온 문자열을 포인터에 맞게 변경한다.
		pInfo->Name = new char[4];
		strcpy(pInfo->Name, buffer);

		//** 리스트에 추가한다.
		StudentList.push_back(pInfo);
	}

	StudentList.pop_back();

	//** 파일을 닫는다.
	fclose(pFileCSV);
}

void Output()
{
	cout << endl << endl;
	cout << "******************" << endl;
	for (list<StudentInfo*>::iterator iter = StudentList.begin();
		iter != StudentList.end(); ++iter)
	{
		cout << (*iter)->Index << " : " << (*iter)->Name << endl;
		cout << "국어 점수 : " << (*iter)->Kor << endl;
		cout << "영어 점수 : " << (*iter)->Eng << endl;
		cout << "수학 점수 : " << (*iter)->Math << endl << endl;
	}
	cout << "******************" << endl;
}

*/


#include <iostream>
#include <Windows.h>
#include <list>
#include <map>
#include <string>

using namespace std;

struct Vector3
{
	float x, y;

	Vector3() {}

	Vector3(float _x, float _y) : x(_x), y(_y) {}
};


struct Transform
{
	Vector3 Position;
	Vector3 Scale;
};


class Object
{
private:
	string str;
	Transform TransInfo;
public:
	void Initialize()
	{
		str = "->";
		TransInfo.Position = Vector3(4.0f, 15.0f);
	}

	int Update()
	{
		TransInfo.Position.x++;

		if (TransInfo.Position.x >= 100)
			return 1;

		return 0;
	}

	void Render()
	{
		COORD Pos = { (SHORT)TransInfo.Position.x, (SHORT)TransInfo.Position.y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << str << endl;
	}
public:
	Object() { }
	~Object() { }
};


bool check = false;
int Count = 0;


void Output(float _x, float _y, string _str);




int main(void)
{
	//** 실제 사용한 오브젝트 (랜더링 될 오브젝트 리스트)
	list<Object*> EnableList;

	//** 사용을 마친 오브젝트 리스트 (랜더링 되지 않음)
	list<Object*> DesableList;


	while (true)
	{
		system("cls");

		//** 총알이 발사될 위치.
		Output(2, 15, "◎");

		check = false;

		//** 키 입력 이벤트 확인
		if (GetAsyncKeyState(VK_RETURN))
			//** 한번만 입력받기위함.
			check = true;


		//** 입력이 되었다면..
		if (check)
		{
			//** DesableList 에 여분의 오브젝트가 있는지 확인 하고 없다면...
			if (DesableList.empty())
			{
				//** 5개의 오브젝트를 추가 생성한 후...
				for (int i = 0; i < 5; ++i)
					DesableList.push_back(new Object);
			}

			//** 추가 생성된 오브젝트 하나를 선택.
			list<Object*>::iterator iter = DesableList.begin();


			//** 초기화 에 필요한 구문 작성.
			(*iter)->Initialize();

			//** 사용할 리스트에 추가.
			EnableList.push_back((*iter));

			//** 현재 리스트에서 삭제.
			DesableList.pop_front();
		}


		for (list<Object*>::iterator iter = EnableList.begin();
			iter != EnableList.end();)
		{
			int iResult = (*iter)->Update();
			(*iter)->Render();

			if (iResult == 1)
			{
				//** 현재 리스트에서 삭제.
				DesableList.push_back((*iter));

				//** 사용할 리스트에 추가.
				iter = EnableList.erase(iter);
			}
			else
				++iter;
		}

		//** 현재 리스트에 남아있는 오브젝트의 개수 확인. (DesableList)
		string Buffer = "DesableList : " + to_string(DesableList.size());
		Output(10, 1, Buffer);
		Buffer.clear();

		//** 현재 리스트에 남아있는 오브젝트의 개수 확인. (EnableList)
		Buffer = "EnableList : " + to_string(EnableList.size());
		Output(10, 2, Buffer);


		Sleep(50);
	}



	//** DesableList 전제 삭제
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = NULL;
	}
	DesableList.clear();


	//** EnableList 전제 삭제
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = NULL;
	}
	EnableList.clear();

	return 0;
}

void Output(float _x, float _y, string _str)
{
	COORD Pos = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	cout << _str << endl;
}