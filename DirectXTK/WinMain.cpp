#include "pch.h"
#include "Game.h"

using namespace DirectX;

namespace
{
	std::unique_ptr<Game> g_game;
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// c언어로 컴파일되게끔 함
extern "C"
{
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	if (!XMVerifyCPUSupport())
	{
		return 1;
	}

	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	if (FAILED(hr))
	{
		return 1;
	}

	g_game = std::make_unique<Game>();

	{
		WNDCLASSEX wcex{};

		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WndProc;
		wcex.hInstance = hInstance;
		wcex.hIcon = LoadIcon(hInstance, L"IDI_ICON");
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_WINDOW + 1);
		wcex.lpszClassName = L"DirectXTKSimpleSampleWindowClass";
		wcex.hIconSm = LoadIcon(wcex.hInstance, L"IDI_ICON");

		if (!RegisterClassExW(&wcex))
		{
			return 1;
		}

		int w, h;
		g_game->GetDefaultSize(w, h);

		RECT rc{ 0, 0, static_cast<LONG>(w), static_cast<LONG>(h) };
		AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

		HWND hwnd = CreateWindowExW(
			0,
			L"DirectXTKSimpleSampleWindowClass",
			L"DirectXTK Sample",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			rc.right - rc.left,
			rc.bottom - rc.top,
			nullptr,
			nullptr,
			hInstance,
			nullptr
		);

		if (!hwnd)
		{
			return 1;
		}

		ShowWindow(hwnd, nShowCmd);

		SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(g_game.get()));

		GetClientRect(hwnd, &rc);

		g_game->Initialize(hwnd, rc.right - rc.left, rc.bottom - rc.top);
	}

	MSG msg{};
	while (WM_QUIT != msg.message)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			g_game->Tick();
		}
	}

	g_game.reset();


	CoUninitialize();

	return static_cast<int>(msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static bool s_in_sizemove = false;
	static bool s_in_suspend = false;
	static bool s_in_minimized = false;
	static bool s_in_fullscreen = false;

	auto game = reinterpret_cast<Game*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

	switch (message)
	{
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;

		case WM_PAINT:
			if (s_in_sizemove && game)
			{
				game->Tick();
			}
			else
			{
				PAINTSTRUCT ps;
				BeginPaint(hWnd, &ps);
				EndPaint(hWnd, &ps);
			}
			break;

		case WM_MOVE:
			if (game)
			{
				game->OnWindowMoved();
			}
			break;

		case WM_SIZE:
			if (wParam == SIZE_MINIMIZED)
			{
				if (!s_in_minimized)
				{
					s_in_minimized = true;
					if (!s_in_suspend && game)
					{
						game->OnSuspending();
					}
					s_in_suspend = true;
				}
			}
			else if (s_in_minimized)
			{
				s_in_minimized = false;
				if (s_in_suspend && game)
				{
					game->OnResuming();
				}
				s_in_suspend = false;
			}
			else if (!s_in_sizemove && game)
			{
				game->OnWindowSizeChanged(LOWORD(lParam), HIWORD(lParam));
			}
			break;

		case WM_ENTERSIZEMOVE:
			s_in_sizemove = true;
			break;

		case WM_EXITSIZEMOVE:
			s_in_sizemove = false;
			if (game)
			{
				RECT rc;
				GetClientRect(hWnd, &rc);
				game->OnWindowSizeChanged(rc.right - rc.left, rc.bottom - rc.top);
			}
			break;

		case WM_GETMINMAXINFO:
			if (lParam)
			{
				auto info = reinterpret_cast<MINMAXINFO*>(lParam);
				info->ptMinTrackSize.x = 320;
				info->ptMinTrackSize.y = 240;
			}
			break;

		case WM_ACTIVATEAPP:
			if (game)
			{
				if (wParam)
				{
					game->OnActivated();
				}
				else
				{
					game->OnDeActivated();
				}
			}
			break;

		case WM_POWERBROADCAST:
			switch (wParam)
			{
				case PBT_APMQUERYSUSPEND:
					if (!s_in_suspend && game)
					{
						game->OnSuspending();
					}
					s_in_suspend = true;
					return TRUE;
					break;

				case PBT_APMRESUMESUSPEND:
					if (!s_in_minimized)
					{
						if (s_in_suspend && game)
						{
							game->OnResuming();
						}
						s_in_suspend = false;
					}
					return TRUE;
					break;

			}
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_INPUT:
		case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
		case WM_MOUSEWHEEL:
		case WM_XBUTTONUP:
		case WM_XBUTTONDOWN:
		case WM_MOUSEHOVER:
			Mouse::ProcessMessage(message, wParam, lParam);
			break;

		case WM_KEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
			Keyboard::ProcessMessage(message, wParam, lParam);
			break;

		case WM_SYSKEYDOWN:
			if (wParam == VK_RETURN && (lParam & 0x60000000) == 0x20000000)
			{
				if (s_in_fullscreen)
				{
					SetWindowLongPtr(hWnd, GWL_STYLE, WS_OVERLAPPEDWINDOW);
					SetWindowLongPtr(hWnd, GWL_EXSTYLE, 0);

					int width{ 800 };
					int height{ 600 };
					if (game)
					{
						game->GetDefaultSize(width, height);
					}

					ShowWindow(hWnd, SW_SHOWNORMAL);

					SetWindowPos(hWnd, HWND_TOP, 0, 0, width, height,
						SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);
				}
				else
				{
					SetWindowLongPtr(hWnd, GWL_STYLE, 0);
					SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_TOPMOST);

					SetWindowPos(hWnd, HWND_TOP, 0, 0, 0, 0, 
						SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_FRAMECHANGED);

					ShowWindow(hWnd, SW_SHOWMAXIMIZED);
				}

				s_in_fullscreen = !s_in_fullscreen;
			}

			Keyboard::ProcessMessage(message, wParam, lParam);
			break;

		case WM_MENUCHAR:
			return MAKELRESULT(0, MNC_CLOSE);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

void ExitGame() noexcept
{
	PostQuitMessage(0);
}