#include <Windows.h>
#include "D2DFramework.h"


const wchar_t gClassName[] = L"MyWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

// 매크로 만듬
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
		// 마이크로소프트에서 제공됨(c++에서 제공되는 것 찾아보기)
		mbstowcs_s(&len, wstr, e.what(), 128);

		D2DFramework::ShowErrorMsg(wstr);
	}
	

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// 일단 무한반복 ( GameLoop )
		// 메시지가 있나 살펴봅니다. PeekMessage
		// 메시지가 있으면 처리
			// 종료 메시지라면 반복 break
		// 메시지가 없으면
			// 게임의 그래픽을 갱신
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