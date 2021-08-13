#include "PrototypeManager.h"
#include "Object.h"

//Object* pObjList[3];

list<Object*> ObjectList;

void InitObject(string _Key)
{
	// PrototypeManager 에서 원본 객체를 찾아옴
	Object* pObj = PrototypeManager::GetInstance()->FineObject(_Key);

	// 찾으려는 객체가 없을 경우
	if (pObj == nullptr)
	{
		// 오류 메시지를 출력
		COORD Pos = { (SHORT)50, (SHORT)15 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
		cout << "복제할 원본 객체가 없음" << endl;

		// 함수 종료.
		return;
	}

	// 원형객체를 정상적으로 참조할 경우
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
	// 숙제 리스트로 바꾸고 출력?

	PrototypeManager::GetInstance()->Initialize();


	// 정상출력
	// 인덱스에 1, 2, 3

	// 초기화
	//Object* pObj[3];
	//for (int i = 0; i < 3; ++i)
	//{
	//	pObj[i] = PrototypeManager::GetInstance()->FineObject("Object");
	//	pObj[i]->Initialize();
	//	pObj[i]->SetIndex(i + 1);
	//}
	// 변경
	InitObject("Object");
	// 바꿔??

	// 출력
	//for (int i = 0; i < 3; ++i)
	//{
	//	pObj[i]->Render(i);
	//}
	// 변경
	//for (int i = 0; i < 3; ++i)
	//	if (pObjList[i])
	//		pObjList[i]->Render(i);
	// list 변경
	for (list<Object*>::iterator iter = ObjectList.begin();
		iter != ObjectList.end(); ++iter)
		// 적어야 됨
		(*iter)->Render();



	/*
	// 삭제/안됨
	for (int i = 0; i < 3; i++)
	{
		delete pObj[i];
		pObj[i] = nullptr;

	}
	*/
	// 변경
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
		// 적어야됨
			if ((*iter))
			{
				delete (*iter);
				(*iter) = nullptr;
			}


	return 0;
}