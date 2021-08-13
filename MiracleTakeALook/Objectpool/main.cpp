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
	// ���� ����� ������Ʈ ������ �� ������Ʈ ����Ʈ
	list<Object*> EnableList;
	// ����� ��ģ ������Ʈ ����Ʈ ������X
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
		//  �Ѿ��� �߻� �� ��ġ
		Output(2, 15, "==>");

		check = false;

		// Ű �Է� Ȯ��
		if (GetAsyncKeyState(VK_RETURN))
			check = true;

		// �Է� ��
		if (check)
		{
			//list< ObjectPoolList*>::iterator iter = ObjectPoolList.begin();

			if (DesableList.empty())
			{
				//ObjectPool* pTmp = new ObjectPool(count++, 0, fales);
				//ObjectPoolList.push_back(new ObjectPool(Count++, 0, false));
				// 5���� ������Ʈ �߰� ����
				for (int i = 0; i < 5; ++i)
					DesableList.push_back(new Object(Count++, 0));
			}
			// �߰� ������ ������Ʈ �ϳ� ����
			list<Object*>::iterator iter = DesableList.begin();

			// �ʱ�ȭ �� �ʿ��� ���� �ۼ�.


			// ����� ����Ʈ�� �߰�.
			EnableList.push_back((*iter));

			// ���� ����Ʈ���� ����.
			DesableList.pop_front();

			// ����Ǿ����� ��� ����~
			// ���������� ���
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
		 
		// �������� ����
		// Render
		cout << "EnableList" << endl;
		for (list<Object*>::iterator iter = EnableList.begin();
			iter != EnableList.end();/* �������� �Ʒ��ʿ� */)
		{
			// Value �� ����
			(*iter)->Value++;

			// �ܼ�â�� ���
			cout << (*iter)->Key << " : " << (*iter)->Value << endl;

			// ��µ� ������Ʈ�� Value ���� ���� �̻��� �ȴٸ�....
			if ((*iter)->Value >= 50)
			{
				// ���� ����Ʈ���� DesableList �� �Ȱܳ���
				DesableList.push_back((*iter));

				// ���� ����Ʈ���� ����.
				iter = EnableList.erase(iter);
			}
			else
				++iter; // ������Ʈ�� �������� ������ ������Ŵ..
		}

		cout << "DesableList" << endl;
		for (list<Object*>::iterator iter = DesableList.begin();
			iter != DesableList.end(); ++iter)
		{
			//** �ܼ�â�� ���
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

	// DesableList ���� ����
	for (list<Object*>::iterator iter = DesableList.begin();
		iter != DesableList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = nullptr;
	}
	DesableList.clear();


	// EnableList ���� ����
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