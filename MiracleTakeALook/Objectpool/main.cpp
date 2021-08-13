#include <iostream>
#include <Windows.h>
#include <list>


using namespace std;

struct Vector3
{
	float x, y, z;

	Vector3() {}
};

struct Transform
{
	Vector3 Position;
	Vector3 Scale;
};




struct Object
{
private:
	int Key;
	//int Value;
	//bool Active;
	Transform TransInfo;
public:
	void Intialize()
	{
		Key = 0;

		TransInfo.Position = Vector3();
	}

	//ObjectPool() : Key(0), Value(0), Active(false) {}
	//
	//
	//ObjectPool(int _Key, int _Value, bool _Active)
	//	: Key(_Key), Value(_Value), Active(_Active) {}

	void Output(float _x, float _y, string _str)
	{
		COORD Pos = { _x, _y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << _str << endl;
	}
public:
	Object() {}
	~Object() {}


};

bool check = false;
int Count = 0;

//void InputKey(ObjectPool* _pool);
void Output(float _x, float _y, string _str);


int main(void)
{

	//ObjectPool* Array[128] = { nullptr };
	// 실제 사용한 오브젝트 랜더링 될 오브젝트 리스트
	list<Object*> EnableList;
	// 사용을 마친 오브젝트 리스트 렌더링X
	list<Object*> DesableList;


	//for (int i = 0; i < 128; ++i)
	//{
	//	Array[i] = new ObjectPool;
	//
	//	Array[i]->Active = false;
	//	Array[i]->Key = i;
	//	Array[i]->Value = 0;
	//}
	//for (list< ObjectPool*>::iterator iter = ObjectPoolList.begin();
	//	iter != ObjectPoolList.end;  ++iter)
	//{
	//	ObjectPoolList.push_back(new ObjectPool(i, 0, false));
	//
	//	ObjectPoolList[i]->Active = false;
	//	ObjectPoolList[i]->Key = i;
	//	ObjectPoolList[i]->Value = 0;
	//}


	//while (true)
	//{
	//	system("cls");
	//	check = false;
	//
	//	if (GetAsyncKeyState(VK_RETURN))
	//		check = true;
	//
	//	if (check)
	//	{
	//		for (int i = 0; i < 128; ++i)
	//		{
	//			if (Array[i]->Active)
	//			{
	//				Array[i]->Active = true;
	//				//Array[i]->Key = Count++;
	//				Array[i]->Value = 0;
	//			}
	//		}
	//	}
	//		//InputKey(Array[Count]);
	//
	//
	//
	//	for (int i = 0; i < 128; ++i)
	//	{
	//		if (Array[i])
	//		{
	//			Array[i]->Value++;
	//			cout << Array[i]->Key << " : " << Array[i]->Value << endl << endl;;
	//			
	//			if (Array[i]->Value >= 50)
	//			{
	//				Array[i]->Active = false;
	//				//--Count;
	//			}
	//		}
	//	}
	//	Sleep(50);
	//}

	while (true)
	{
		system("cls");
		//  총알이 발사 될 위치
		Output(2, 15, "==>");

		check = false;

		// 키 입력 확인
		if (GetAsyncKeyState(VK_RETURN))
			check = true;

		// 입력 됨
		if (check)
		{
			//list< ObjectPoolList*>::iterator iter = ObjectPoolList.begin();

			if (DesableList.empty())
			{
				//ObjectPool* pTmp = new ObjectPool(count++, 0, fales);
				//ObjectPoolList.push_back(new ObjectPool(Count++, 0, false));
				// 5개의 오브젝트 추가 생성
				for (int i = 0; i < 5; ++i)
					DesableList.push_back(new Object(Count++, 0));
			}
			// 추가 생선된 오브젝트 하나 선택
			list<Object*>::iterator iter = DesableList.begin();

			// 초기화 에 필요한 구문 작성.


			// 사용할 리스트에 추가.
			EnableList.push_back((*iter));

			// 현재 리스트에서 삭제.
			DesableList.pop_front();

			// 종료되었을때 어떻게 할지~
			// 할지말지를 물어봄
			//else
			//{
			//	for (list< Object*>::iterator iter = ObjectPoolList.begin();
			//		iter != ObjectPoolList.end();  ++iter)
			//	{
			//		if (!(*iter)->Active)
			//		{
			//			int Pick;
			//			cout << "1. GO 2. EXIT"; cin >> Pick;
			//			switch (Pick)
			//			{
			//			case 1: // go
			//				(*iter)->Active = true;
			//				(*iter)->Key = 0;
			//				(*iter)->Value = 0;
			//				break;
			//			case 2:
			//				exit(nullptr);
			//				break;
			//
			//			}
			//			break;
			//
			//		}
			//	}
			//}
		}
			//InputKey(Array[Count]);

		//for (list< ObjectPool*>::iterator iter = ObjectPoolList.begin();
		//	iter != ObjectPoolList.end();  ++iter)
		//{
		//	if ((*iter)->Active)
		//	{
		//		(*iter)->Value++;
		//		cout << (*iter)->Key << " : " << (*iter)->Value << endl << endl;;
		//		
		//		if ((*iter)->Value >= 50)
		//		{
		//			(*iter)->Active = false;
		//			//--Count;
		//		}
		//	}
		//}
		 
		// 오류내용 수정
		// Render
		cout << "EnableList" << endl;
		for (list<Object*>::iterator iter = EnableList.begin();
			iter != EnableList.end();/* 증감문은 아래쪽에 */)
		{
			// Value 값 증가
			(*iter)->Value++;

			// 콘솔창에 출력
			cout << (*iter)->Key << " : " << (*iter)->Value << endl;

			// 출력된 오브젝트의 Value 값이 일정 이상이 된다면....
			if ((*iter)->Value >= 50)
			{
				// 현재 리스트에서 DesableList 로 옴겨놓고
				DesableList.push_back((*iter));

				// 현재 리스트에서 삭제.
				iter = EnableList.erase(iter);
			}
			else
				++iter; // 오브젝트가 삭제되지 않을때 증가시킴..
		}

		cout << "DesableList" << endl;
		for (list<Object*>::iterator iter = DesableList.begin();
			iter != DesableList.end(); ++iter)
		{
			//** 콘솔창에 출력
			cout << (*iter)->Key << endl;
		}
		Sleep(50);
	}
	//for (int i = 0; i < 128; ++i)
	//{
	//	delete Array[i];
	//	Array[i] = nullptr;
	//}
	//for (list<ObjectPool*>::iterator iter = ObjectPoolList.begin();
	//	iter != ObjectPoolList.end(); ++iter)
	//{
	//	delete (*iter);
	//	(*iter) = nullptr;
	//}
	//ObjectPoolList.clear();

	// DesableList 전제 삭제
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	DesableList.clear();


	// EnableList 전제 삭제
	for (list<Object*>::iterator iter = EnableList.begin();
		iter != EnableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	EnableList.clear();

	return 0;
}


//void InputKey(ObjectPool* _pool)
//{
//	if (!check)
//		return;
//
//	_pool->Active = true;
//
//	_pool->Key = Count++;
//	_pool->Value = 0;
//
//}

void Output(float _x, float _y, string _str)
{
	COORD Pos = { _x, _y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	cout << _str << endl;
}