#include "PrototypeManager.h"
#include "Object.h"

//Object* pObjList[3];

list<Object*> ObjectList;

void InitObject(string _Key)
{
	// PrototypeManager ���� ���� ��ü�� ã�ƿ�
	Object* pObj = PrototypeManager::GetInstance()->FineObject(_Key);

	// ã������ ��ü�� ���� ���
	if (pObj == nullptr)
	{
		// ���� �޽����� ���
		COORD Pos = { (SHORT)50, (SHORT)15 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << "������ ���� ��ü�� ����" << endl;

		// �Լ� ����.
		return;
	}

	// ������ü�� ���������� ������ ���
	for (int i = 0; i < 3; ++i)
	{
		Object* pTempObj = pObj->Clone();

		pTempObj->Initialize();
		pTempObj->SetIndex(i);

		ObjectList.push_back(pTempObj);
	}
}
int main(void)
{ 
	// ���� ����Ʈ�� �ٲٰ� ���?

	PrototypeManager::GetInstance()->Initialize();


	// �������
	// �ε����� 1, 2, 3

	// �ʱ�ȭ
	//Object* pObj[3];
	//for (int i = 0; i < 3; ++i)
	//{
	//	pObj[i] = PrototypeManager::GetInstance()->FineObject("Object");
	//	pObj[i]->Initialize();
	//	pObj[i]->SetIndex(i + 1);
	//}
	// ����
	InitObject("Object");
	// �ٲ�??

	// ���
	//for (int i = 0; i < 3; ++i)
	//{
	//	pObj[i]->Render(i);
	//}
	// ����
	//for (int i = 0; i < 3; ++i)
	//	if (pObjList[i])
	//		pObjList[i]->Render(i);
	// list ����
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
		// ����� ��
		(*iter)->Render();



	/*
	// ����/�ȵ�
	for (int i = 0; i < 3; i++)
	{
		delete pObj[i];
		pObj[i] = nullptr;

	}
	*/
	// ����
	//for (int i = 0; i < 3; ++i)
	//{
	//	if (pObjList[i])
	//	{
	//		delete pObjList[i];
	//		pObjList[i] = nullptr;
	//	}
	//}
		for (list<Object*>::iterator iter = ObjectList.begin();
			iter != ObjectList.end(); ++iter)
		// ����ߵ�
			if ((*iter))
			{
				delete (*iter);
				(*iter) = nullptr;
			}


	return 0;
}