#include "PrototypeManager.h"
#include "Object.h"

Object* pObjList[3];


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
	// pObjList �� �ʱ�ȭ
	for (int i = 0; i < 3; ++i)
	{
		// ������ ���� ��ü�� ���纻�� �Ѱ���
		pObjList[i] = pObj->Clone();


		// �׸��� ���纻�� �ʱ�ȭ��
		pObjList[i]->Initialize();

		// ���纻�� �ε������� ����.
		pObjList[i]->SetIndex(i + 1);
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
	for (list<Transform*>::iterator iter = TransformList.begin();
		iter != TransformList.end(); ++iter)
		// ����� ��

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
	for (list<Transform*>::iterator iter = TransformList.begin();
		iter != TransformList.end(); ++iter)
		// ����ߵ�



	return 0;
}