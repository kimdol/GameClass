#include "D2DFramework.h"

#pragma comment (lib, "d2d1.lib")

HRESULT D2DFramework::InitWindow(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpszClassName = WND_CLASS_NAME;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.lpfnWndProc = D2DFramework::WndProc;

	if (RegisterClassEx(&wc) == false)
	{
		D2DFramework::ShowErrorMsg(L"Failed To Register window class!");
		return 0;
	}

	RECT wr = { 0, 0, 
		static_cast<LONG>(width), static_cast<LONG>(height) };
	AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, false);

	mHwnd = CreateWindowEx(
		0,
		WND_CLASS_NAME,
		title,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		wr.right - wr.left, wr.bottom - wr.top,
		0,
		0,
		hInstance,
		0
	);

	if (mHwnd == 0)
	{
		D2DFramework::ShowErrorMsg(L"Failed To Create window!");
		return 0;
	}

	SetWindowLongPtr(mHwnd, GWLP_USERDATA, 
		reinterpret_cast<LONG_PTR>(this));

	return S_OK;
}

HRESULT D2DFramework::InitD2D()
{
	// 1. Direct2D Factory 积己
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED, mspD2DFactory.GetAddressOf());
	ThrowIfFailed(hr);
	
	hr = CreateDeviceResources();
	ThrowIfFailed(hr);

	return hr;
}

HRESULT D2DFramework::CreateDeviceResources()
{
	// 2. 坊歹 鸥百 积己
	RECT wr;
	GetClientRect(mHwnd, &wr);
	HRESULT hr = mspD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			mHwnd,
			D2D1::SizeU(wr.right - wr.left, wr.bottom - wr.top)),
		mspRenderTarget.GetAddressOf()
	);

	return hr;
}

HRESULT D2DFramework::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;

	hr = InitWindow(hInstance, title, width, height);
	ThrowIfFailed(hr);

	hr = InitD2D();
	ThrowIfFailed(hr);

	ShowWindow(mHwnd, SW_SHOW);
	UpdateWindow(mHwnd);

	return hr;
}

void D2DFramework::Release()
{
}

int D2DFramework::GameLoop()
{
	// 老窜 公茄馆汗 ( GameLoop )
		// 皋矫瘤啊 乐唱 混旗壕聪促. PeekMessage
		// 皋矫瘤啊 乐栏搁 贸府
			// 辆丰 皋矫瘤扼搁 馆汗 break
		// 皋矫瘤啊 绝栏搁
			// 霸烙狼 弊贰侨阑 盎脚
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
			Render();
		}
	}

	return static_cast<int>(msg.wParam);
}

void D2DFramework::Render()
{
	HRESULT hr;

	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
	
	// TODO : 弊府扁



	hr = mspRenderTarget->EndDraw();
	if (hr == D2DERR_RECREATE_TARGET)
	{
		CreateDeviceResources();
	}
}

void D2DFramework::ShowErrorMsg(LPCWSTR msg, LPCWSTR title)
{
	OutputDebugString(msg);

	MessageBox(nullptr, msg,
		title, MB_OK | MB_ICONEXCLAMATION);

}

LRESULT D2DFramework::WndProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	// static 窃荐啊 牢胶畔胶甫 静绰 厚搬
	D2DFramework* pFramework = 
		reinterpret_cast<D2DFramework*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));

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
