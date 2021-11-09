// Windows API 헤더
#include <Windows.h>
// 문자열
#include <sstream>

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
	/*첫 시작*/
	// MessageBox(nullptr, L"HelloWorld", L"SimpleWindow", MB_ICONEXCLAMATION | MB_OK);
	
	/* 윈도우를 만들기 위한 4단계 */
	// 1. 윈도우 클래스 등록 - 윈도우 프로시져 등록
	// 2. 윈도우 생성 - (1)번의 클래스 지정
	// 3. 윈도우 메시지(이벤트) 루프
	// ----------------------------------------
	// * 윈도우 프로시져 함수 만들기 - callback
	
	
	// 1 - 윈도우 프로시져 등록
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

	// 2. 윈도우 생성
	HWND hwnd = CreateWindowEx(
		0,
		gClassName,
		L"HelloWindow",
		WS_OVERLAPPEDWINDOW,
		0, 0,
		640, 480,
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

	// 3. 윈도우 메시지(이벤트) 루프 (WM_QUIT 시 종료)
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return static_cast<int>(msg.wParam);
}

// * 윈도우 프로시져 함수 만들기 - callback

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch(message)
	{
		case WM_LBUTTONDOWN:
		{
			//int x = (WORD)lparam;
			//int y = (WORD)(lparam >> 16);
			int x = LOWORD(lparam);
			int y = HIWORD(lparam);

			std::wostringstream oss;

			oss << "X : " << x << ", Y : " << y;
			MessageBox(hwnd, oss.str().c_str(), L"왼쪽클릭", MB_OK);
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
