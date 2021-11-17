#include <Windows.h>
#include "D2DFramework.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

// ��ũ�� ����
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
		D2DFramework myFramework;

		if (SUCCEEDED(myFramework.Initialize(hInstance)))
		{
			ret = myFramework.GameLoop();
		}
	}
	catch (com_exception& e)
	{
		static wchar_t wstr[128]{};
		size_t len;
		// ����ũ�μ���Ʈ���� ������(c++���� �����Ǵ� �� ã�ƺ���)
		mbstowcs_s(&len, wstr, e.what(), 128);

		D2DFramework::ShowErrorMsg(wstr);
	}
	

	return ret;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		case WM_CLOSE:
			DestroyWindow(hwnd);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hwnd, message, wparam, lparam);
			break;
	}

	return 0;
}