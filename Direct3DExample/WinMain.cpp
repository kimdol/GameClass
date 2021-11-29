#define WIN32_LEAN_AND_MEAU // 쓸대없는거 포함안시킴(컴파일,실행속도도 빨라짐)

#include <Windows.h> // GDI, 프린터, 네트워크 (랜카드, 모뎀), 사운드 카드..등등
#include <string>

#include <wrl/client.h>
#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")

// 1. 디바이스 생성 (그래픽카드 접근을 위함(변수))
//		DC (Device Context)
// 2. 스왑 체인 ( 버퍼링 )
// 3. RenderTarget - 백버퍼 지정
// 4. 깊이-스텐실 버퍼(depth:24byte, Stencil:8)
// 5. 뷰포트 ( 카메라 )
// 6. 화면에 그리기 ( back -> front )


const std::wstring gClassName{ L"MyWindowClass" };
const std::wstring gTitle{ L"Direct3D Example" };
const int WINDOW_WIDTH{ 800 };
const int WINDOW_HEIGHT{ 600 };

HWND gHwnd{};
HINSTANCE gInstance{};

using namespace Microsoft::WRL;

ComPtr <ID3D11Device>		gspDevice{};
ComPtr<ID3D11DeviceContext> gspDeviceContext{};
// Grapghics instructure
ComPtr<IDXGISwapChain>		gspSwapChain{};


void InitD3D();
void ReleaseD3D();

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	gInstance = hInstance;

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = gClassName.c_str();
	wc.hInstance = gInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = WindowProc;
	wc.cbSize = sizeof(WNDCLASSEX);

	if (!RegisterClassEx(&wc))
	{
		return 0;
	}

	RECT wr{ 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);

	gHwnd = CreateWindowEx(
		NULL,
		gClassName.c_str(),
		gTitle.c_str(),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		wr.right - wr.left,
		wr.bottom - wr.top,
		NULL,
		NULL,
		gInstance,
		NULL
	);

	if (gHwnd == nullptr)
	{
		return 0;
	}

	ShowWindow(gHwnd, nShowCmd);

	SetForegroundWindow(gHwnd);
	SetFocus(gHwnd);

	UpdateWindow(gHwnd);

	InitD3D();

	MSG msg{};
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);

			if (msg.message == WM_QUIT)
			{
				break;
			}
		}
		else
		{
			// game loop
		}
	}

	ReleaseD3D();

	return static_cast<int>(msg.wParam);
}

void InitD3D()
{
}

void ReleaseD3D()
{
	gspSwapChain.Reset();
	gspDevice.Reset();
	gspDeviceContext.Reset();

	DestroyWindow(gHwnd);
	UnregisterClass(gClassName.c_str(), gInstance); // 등록한 윈도우 클래스 없앰

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
	}
}