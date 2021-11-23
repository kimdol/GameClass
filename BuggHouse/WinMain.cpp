#include <Windows.h>
#include "BuggyHouse.h"

// 매크로 만듬
#define SAFE_RELEASE(p) { if (p) { p->Release(); p = nullptr;}}



int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	int ret{ 0 };

	try
	{
		BuggyHouse myFramework;

		if (SUCCEEDED(myFramework.Initialize(hInstance)))
		{
			ret = myFramework.GameLoop();
		}
	}
	catch (com_exception& e)
	{
		static wchar_t wstr[128]{};
		size_t len;
		// 마이크로소프트에서 제공됨(c++에서 제공되는 것 찾아보기)
		mbstowcs_s(&len, wstr, e.what(), 128);

		BuggyHouse::ShowErrorMsg(wstr);
	}


	return ret;
}