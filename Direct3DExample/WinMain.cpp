#define WIN32_LEAN_AND_MEAU // ������°� ���ԾȽ�Ŵ(������,����ӵ��� ������)

#include <Windows.h> // GDI, ������, ��Ʈ��ũ (��ī��, ��), ���� ī��..���
#include <string>

#include <wrl/client.h>
#include <d3d11.h>
#pragma comment (lib, "d3d11.lib")

// 1. ����̽� ���� (�׷���ī�� ������ ����(����))
//		DC (Device Context)
// 2. ���� ü�� ( ���۸� )
// 3. RenderTarget - ����� ����
// 4. ����-���ٽ� ����(depth:24byte, Stencil:8)
// 5. ����Ʈ ( ī�޶� )
// 6. ȭ�鿡 �׸��� ( back -> front )


const std::wstring gClassName{ L"MyWindowClass" };
const std::wstring gTitle{ L"Direct3D Example" };
const int WINDOW_WIDTH{ 800 };
const int WINDOW_HEIGHT{ 600 };

HWND gHwnd{};
HINSTANCE gInstance{};

using namespace Microsoft::WRL;

ComPtr <ID3D11Device>				gspDevice{};
ComPtr<ID3D11DeviceContext>			gspDeviceContext{};
// Grapghics instructure
ComPtr<IDXGISwapChain>				gspSwapChain{};
ComPtr<ID3D11Texture2D>				gspRenderTarget{}; // ��ǥ�� ��ũ, ����� ��..
ComPtr<ID3D11Texture2D>				gspDepthStencil{};
ComPtr<ID3D11RenderTargetView>		gspRenderTargetView{};
ComPtr<ID3D11DepthStencilView>		gspDepthStencilView{};


void InitD3D();
void RenderFrame();
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
			RenderFrame();
		}
	}

	ReleaseD3D();

	return static_cast<int>(msg.wParam);
}

void InitD3D()
{
	// Device �����
	// SwapChain �����

	DXGI_SWAP_CHAIN_DESC scd{};

	ZeroMemory(&scd, sizeof(DXGI_SWAP_CHAIN_DESC));
	scd.BufferCount = 1; // ����� ����
	scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	scd.OutputWindow = gHwnd;
	scd.Windowed = TRUE;
	scd.SampleDesc.Count = 1;


	D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		NULL,
		NULL,
		0,
		D3D11_SDK_VERSION,
		&scd,
		gspSwapChain.ReleaseAndGetAddressOf(),
		gspDevice.ReleaseAndGetAddressOf(),
		NULL,
		gspDeviceContext.ReleaseAndGetAddressOf()
	);

	// ����Ÿ��
	gspSwapChain->GetBuffer(
		0, 
		IID_PPV_ARGS(gspRenderTarget.ReleaseAndGetAddressOf())
	);
	gspDevice->CreateRenderTargetView(
		gspRenderTarget.Get(),
		nullptr,
		gspRenderTargetView.ReleaseAndGetAddressOf()
	);

	// ����-���ٽ�
	CD3D11_TEXTURE2D_DESC dtd(
		DXGI_FORMAT_D24_UNORM_S8_UINT,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		1,
		1,
		D3D11_BIND_DEPTH_STENCIL
	);

	gspDevice->CreateTexture2D(
		&dtd,
		nullptr,
		gspDepthStencil.ReleaseAndGetAddressOf()
	);

	CD3D11_DEPTH_STENCIL_VIEW_DESC dsvd(
		D3D11_DSV_DIMENSION_TEXTURE2D
	);

	gspDevice->CreateDepthStencilView(
		gspDepthStencil.Get(),
		&dsvd,
		gspDepthStencilView.ReleaseAndGetAddressOf()
	);

	// ����������
	gspDeviceContext->OMSetRenderTargets(
		1,
		gspRenderTargetView.GetAddressOf(),
		gspDepthStencilView.Get()
	);

	// ����Ʈ(View-Port)
	CD3D11_VIEWPORT viewport(
		0.0f, 
		0.0f, 
		static_cast<float>(WINDOW_WIDTH), 
		static_cast<float>(WINDOW_HEIGHT)
	);

	gspDeviceContext->RSSetViewports(1, &viewport);

}

void RenderFrame()
{
}

void ReleaseD3D()
{
	gspSwapChain.Reset();
	gspDevice.Reset();
	gspDeviceContext.Reset();

	DestroyWindow(gHwnd);
	UnregisterClass(gClassName.c_str(), gInstance); // ����� ������ Ŭ���� ����

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