#include <Windows.h>
#include <d2d1.h>

#pragma comment (lib, "d2d1.lib")

const wchar_t gClassName[] = L"MyWindowClass";

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

// 0. 전역변수 - 인터페이스
ID2D1Factory* gpD2DFactory{};
ID2D1HwndRenderTarget* gpRenderTarget{};

ID2D1SolidColorBrush* gpBrush{};
ID2D1RadialGradientBrush* gpRadialBrush{};



int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	// 1. Direct2D Factory 생성
	HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &gpD2DFactory);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"Failed to create D2D Factory", L"Error", MB_OK);
		return 0;
	}



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
		MessageBox(nullptr, L"Failed To Register window class!", L"Error", MB_OK | MB_ICONEXCLAMATION);
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
		MessageBox(nullptr, L"Failed To Create window!", L"Error", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}

	// 2. 렌더 타겟 생성
	GetClientRect(hwnd, &wr);
	hr = gpD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(wr.right - wr.left, wr.bottom - wr.top)),
		&gpRenderTarget
	);
	if (FAILED(hr))
	{
		MessageBox(nullptr, L"Failed to create D2D RenderTarget", L"Error", MB_OK);
		return 0;
	}

	gpRenderTarget->CreateSolidColorBrush(D2D1::ColorF(0x9aCD32, 1.0f), &gpBrush);
	ID2D1GradientStopCollection* pGradientStops{};
	D2D1_GRADIENT_STOP stops[2];
	stops[0].color = D2D1::ColorF(D2D1::ColorF::Yellow, 1);
	stops[0].position = 0.0f;
	stops[1].color = D2D1::ColorF(D2D1::ColorF::Crimson, 1);
	stops[1].position = 1.0f;

	hr = gpRenderTarget->CreateGradientStopCollection(stops, 2,
		D2D1_GAMMA_2_2,
		D2D1_EXTEND_MODE_CLAMP,
		&pGradientStops
		);
	if (SUCCEEDED(hr))
	{
		gpRenderTarget->CreateRadialGradientBrush(
			D2D1::RadialGradientBrushProperties(
				D2D1::Point2F(50, 150),
				D2D1::Point2F(0, 0),
				50,
				50),
			pGradientStops,
			&gpRadialBrush
			);
	}
	if (pGradientStops != nullptr)
	{
		pGradientStops->Release();
		pGradientStops = nullptr;
	}
	


	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	// 4. 리소스 해제 후, 종료(모든 해제는 역순으로)
	if (gpRadialBrush != nullptr)
	{
		gpRadialBrush->Release();
		gpRadialBrush = nullptr;
	}
	if (gpBrush != nullptr)
	{
		gpBrush->Release();
		gpBrush = nullptr;
	}
	if (gpRenderTarget != nullptr)
	{
		gpRenderTarget->Release();
		gpRenderTarget = nullptr;
	}
	if (gpD2DFactory != nullptr)
	{
		gpD2DFactory->Release();
		gpD2DFactory = nullptr;
	}
	
	

	return static_cast<int>(msg.wParam);
}

void OnPaint(HWND hwnd)
{
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(hwnd, &ps);

	// 3. 그리기
	gpRenderTarget->BeginDraw();
	gpRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

	gpBrush->SetOpacity(1.0f);
	gpBrush->SetColor(D2D1::ColorF(D2D1::ColorF::Aquamarine));
	gpRenderTarget->FillRectangle(D2D1::RectF(0.0f, 0.0f, 100.0f, 100.0f), gpBrush);

	gpBrush->SetOpacity(0.5f);
	gpBrush->SetColor(D2D1::ColorF(D2D1::ColorF::LightYellow));
	gpRenderTarget->FillRectangle(D2D1::RectF(50.0f, 50.0f, 150.0f, 150.0f), gpBrush);

	gpRenderTarget->FillRectangle (D2D1::RectF(0.0f, 0.0f, 100.0f, 100.0f), gpBrush);

	gpRenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(50.0f, 150.f), 50.0f, 50.0f),
		gpRadialBrush);




	gpRenderTarget->EndDraw();
	



	EndPaint(hwnd, &ps);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		case WM_PAINT:
			OnPaint(hwnd);
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