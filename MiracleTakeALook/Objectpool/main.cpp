#include <iostream>
#include <Windows.h>
#include <list>


using namespace std;




struct ObjectPool
{
	int Key;
	int Value;
	bool Active;

	ObjectPool() : Key(0), Value(0), Active(false) {}


	ObjectPool(int _Key, int _Value, bool _Active)
		: Key(_Key), Value(_Value), Active(_Active) {}

};

bool check = false;
int Count = 0;

//void InputKey(ObjectPool* _pool);

int main(void)
{

	//ObjectPool* Array[128] = { NULL };
	list<ObjectPool*> ObjectPoolList;


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
		check = false;

		if (GetAsyncKeyState(VK_RETURN))
			check = true;

		if (check)
		{
			//list< ObjectPoolList*>::iterator iter = ObjectPoolList.begin();

			if (ObjectPoolList.empty())
			{
				//ObjectPool* pTmp = new ObjectPool(count++, 0, fales);
				ObjectPoolList.push_back(new ObjectPool(Count++, 0, false));
			}
			else
			{
				for (list< ObjectPool*>::iterator iter = ObjectPoolList.begin();
					iter != ObjectPoolList.end();  ++iter)
				{
					if (!(*iter)->Active)
					{
						(*iter)->Active = true;
						(*iter)->Key = 0;
						(*iter)->Value = 0;
						break;
					}
				}
			}
		}
			//InputKey(Array[Count]);

		// 숙제 마지막~ 머라..?
		// 그


		for (list< ObjectPool*>::iterator iter = ObjectPoolList.begin();
			iter != ObjectPoolList.end();  ++iter)
		{
			if ((*iter)->Active)
			{
				(*iter)->Value++;
				cout << (*iter)->Key << " : " << (*iter)->Value << endl << endl;;
				
				if ((*iter)->Value >= 50)
				{
					(*iter)->Active = false;
					//--Count;
				}
			}
		}
		Sleep(50);
	}
	//for (int i = 0; i < 128; ++i)
	//{
	//	delete Array[i];
	//	Array[i] = NULL;
	//}
	for (list<ObjectPool*>::iterator iter = ObjectPoolList.begin();
		iter != ObjectPoolList.end(); ++iter)
	{
		delete (*iter);
		(*iter) = NULL;
	}
	ObjectPoolList.clear();

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