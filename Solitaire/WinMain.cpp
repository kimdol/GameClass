#include "GameLogic.h"

#pragma comment(lib, "Gdiplus.lib")

const wchar_t gClassName[]{ L"MyWindwClass" };

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

solitaire::GameLogic gLogic;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	// GDIPlus 초기화
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, nullptr);

	// 1
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);

	if (RegisterClassEx(&wc) == false)
	{
		MessageBox(nullptr, L"Failed to register window", L"Error", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	// 2
	RECT wr = { 0, 0, 1024, 768 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
	HWND hwnd = CreateWindowEx(
		0,
		gClassName,
		L"Solitaire Game",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right - wr.left, wr.bottom - wr.top,
		0,
		0,
		hInstance,
		0
	);

	if (hwnd == nullptr)
	{
		MessageBox(nullptr, L"Failed to Create window", L"Error", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	gLogic.initialize(hwnd);
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);



	// 3
	// 3. 윈도우 메시지(이벤트) 루프 (WM_QUIT 시 종료)
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	gLogic.Release();
	Gdiplus::GdiplusShutdown(gdiplusToken);
	return static_cast<int>(msg.wParam);
}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(hwnd, &ps);

	Gdiplus::Graphics graphics(hdc);

	//TEST
	gLogic.Draw(graphics);

	EndPaint(hwnd, &ps);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		case WM_PAINT:
		{
			OnPaint(hwnd);
		}
		break;
		case WM_LBUTTONUP:
		{
			gLogic.OnClick(LOWORD(lparam), HIWORD(lparam));
			
		}
		break;
		case WM_KEYDOWN:
		{
			
		}
		break;
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
