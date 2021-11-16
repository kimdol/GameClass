#include <Windows.h>
#include "D2DFramework.h"


const wchar_t gClassName[] = L"MyWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

// ��ũ�� ����
#define SAFE_RELEASE(p) { if (p) { p->Release(); p = nullptr;}}

D2DFramework myFramework;

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{

	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProc;

	if (RegisterClassEx(&wc) == false)
	{
		D2DFramework::ShowErrorMsg(L"Failed To Register window class!");
		return 0;
	}

	RECT wr = { 0, 0, 1024, 768 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);

	HWND hwnd = CreateWindowEx(
		0,
		gClassName,
		L"Direct2D",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right - wr.left, wr.bottom - wr.top,
		0,
		0,
		hInstance,
		0
	);

	if (hwnd == 0)
	{
		D2DFramework::ShowErrorMsg(L"Failed To Create window!");
		return 0;
	}
	try
	{
		ThrowIfFailed(myFramework.Init(hwnd));
	}
	catch (com_exception& e)
	{
		static wchar_t wstr[128]{};
		size_t len;
		// ����ũ�μ���Ʈ���� ������(c++���� �����Ǵ� �� ã�ƺ���)
		mbstowcs_s(&len, wstr, e.what(), 128);

		D2DFramework::ShowErrorMsg(wstr);
	}
	

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// �ϴ� ���ѹݺ� ( GameLoop )
		// �޽����� �ֳ� ���캾�ϴ�. PeekMessage
		// �޽����� ������ ó��
			// ���� �޽������ �ݺ� break
		// �޽����� ������
			// ������ �׷����� ����
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			myFramework.Render();
		}
	}
	
	myFramework.Release();

	return static_cast<int>(msg.wParam);
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