#include "MainUpdate.h"

int main(void)
{
	system("Miracle Take A Look");

	system("mode con:cols=120 lines=30");

	srand((ULONG)GetTickCount64());

	MainUpdate Main; // 이제 Main으로 부를거임
	Main.Initialize();

	ULONGLONG Time = GetTickCount64();

	int FrameTime = 50;

	while (true)
	{
		if (Time + FrameTime < GetTickCount64())
		{
			Time = GetTickCount64();
			system("cls");

			Main.Update();
			Main.Render();

			// ㅁㄹ
			if (GetAsyncKeyState(VK_TAB))
				FrameTime = 0;
			else
				FrameTime = 50;
		}
	}
	return 0;
}