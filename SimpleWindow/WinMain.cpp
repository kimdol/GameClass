// Windows API ���
#include <Windows.h>
// ���ڿ�
#include <sstream>
// GDI+
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
// using namespace Gdiplus;

const wchar_t gClassName[] = L"MyWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

// entry point
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
	)
{
	/*ù ����*/
	// MessageBox(nullptr, L"HelloWorld", L"SimpleWindow", MB_ICONEXCLAMATION | MB_OK);
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR token;

	Gdiplus::GdiplusStartup(&token, &gdiplusStartupInput, nullptr);
	
	/* �����츦 ����� ���� 4�ܰ� */
	// 1. ������ Ŭ���� ��� - ������ ���ν��� ���
	// 2. ������ ���� - (1)���� Ŭ���� ����
	// 3. ������ �޽���(�̺�Ʈ) ����
	// ----------------------------------------
	// * ������ ���ν��� �Լ� ����� - callback
	
	
	// 1 - ������ ���ν��� ���
	WNDCLASSEX wc;

	//memset(&wc, 0, sizeof(WNDCLASSEX));
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);  // count of byte
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProc;

	if (RegisterClassEx(&wc) == false)
	{
		MessageBox(nullptr, L"Failed To Regisster window class!", L"Error", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	// 2. ������ ����
	RECT wr = { 0, 0, 640, 480 };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false); // Ŭ���̾�Ʈ ũ�� ���

	HWND hwnd = CreateWindowEx(
		0,
		gClassName,
		L"HelloWindow",
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
		MessageBox(nullptr, L"Failed to Create window", L"Error", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	// 3. ������ �޽���(�̺�Ʈ) ���� (WM_QUIT �� ����)
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	Gdiplus::GdiplusShutdown(token);
	return static_cast<int>(msg.wParam);
}

void Example_DrawRectangle2(HWND hwnd)
{
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(hwnd, &ps);
	//Graphics graphics(hdc);

	HPEN bluePen = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
	HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

	// Create a RectF object.
	//RectF rect(199.0f, 100.0f, 200.0f, 200.0f);

	// Draw rect.
	//graphics.DrawRectangle(&blackPen, rect);
}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(hwnd, &ps);
	
	/*GDI*/
	/*{
		HPEN bluePen = CreatePen(PS_DOT, 1, RGB(0, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, bluePen);

		HBRUSH hatchBrush = CreateHatchBrush(HS_CROSS, RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, hatchBrush);

		Rectangle(hdc, 0, 0, 100, 100);

		DeleteObject(hatchBrush);
		SelectObject(hdc, oldBrush);

		DeleteObject(bluePen);
		SelectObject(hdc, oldPen);
	}*/
	/*GDI plus*/
	Gdiplus::Graphics graphics(hdc);					// DC -> Graphics
	Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 255));	// HPEN -> Pen

	graphics.DrawRectangle(&pen, 0, 0, 100, 100);

	pen.SetColor(Gdiplus::Color::HotPink);
	graphics.DrawLine(&pen, 0, 0, 100, 100);

	Gdiplus::SolidBrush brush(Gdiplus::Color::Black);
	Gdiplus::FontFamily family(L"���� ���");
	Gdiplus::Font font(&family, 24, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
	graphics.DrawString(L"���� ��� ���ڿ��Դϴ�.", -1, &font, { 0.0f, 110.0f }, &brush);
	
	Gdiplus::Image image(L"1.png");
	/*graphics.DrawImage(&image, Gdiplus::RectF(
		ps.rcPaint.left, ps.rcPaint.top,
		ps.rcPaint.right - ps.rcPaint.left, ps.rcPaint.bottom - ps.rcPaint.top
	));*/
	graphics.DrawImage(&image, 0, 0, image.GetWidth(), image.GetHeight()); // �����״��

	EndPaint(hwnd, &ps);
}


// * ������ ���ν��� �Լ� ����� - callback
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch(message)
	{
		case WM_PAINT:
		{
			OnPaint(hwnd);
		}
		break;
		case WM_LBUTTONDOWN:
		{
			//int x = (WORD)lparam;
			//int y = (WORD)(lparam >> 16);
			int x = LOWORD(lparam);
			int y = HIWORD(lparam);

			std::wostringstream oss;

			oss << "X : " << x << ", Y : " << y;
			MessageBox(hwnd, oss.str().c_str(), L"����Ŭ��", MB_OK);
			break;
		}
		case WM_KEYDOWN:
		{
			std::wostringstream oss;

			oss << wparam << std::endl;
			
			OutputDebugString(oss.str().c_str());
			break;
		}
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
