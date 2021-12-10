#pragma once
// 1. ����̽� ���� (�׷���ī�� ������ ����(����))
//		DC (Device Context)
// 2. ���� ü�� ( ���۸� )
// 3. RenderTarget - ����� ����
// 4. ����-���ٽ� ����(depth:24byte, Stencil:8)
// 5. ����Ʈ ( ī�޶� )
// 6. ȭ�鿡 �׸��� ( back -> front )

#define WIN32_LEAN_AND_MEAU // ������°� ���ԾȽ�Ŵ(������,����ӵ��� ������)

#include <Windows.h> // GDI, ������, ��Ʈ��ũ (��ī��, ��), ���� ī��..���
#include <string>

#include <wrl/client.h>
#include <d3d11.h>

#include "Timer.h"

class D3DFramework
{
private:
	const std::wstring mClassName{ L"MyWindowClass" };
	const std::wstring mTitle{ L"Direct3D Example" };

protected:
	int mScreenWidth{ 800 };
	int mScreenHeight{ 600 };
	bool mMinimized{ false };
	bool mMaximized{ false };
	bool mResizing{ false };
	bool mPaused{ false };

	std::wstring mTitleText{};
	MyUtil::Timer mTimer;

	HWND mHwnd{};
	HINSTANCE mInstance{};

	Microsoft::WRL::ComPtr <ID3D11Device>				mspDevice{};
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>			mspDeviceContext{};
	// Grapghics instructure
	Microsoft::WRL::ComPtr<IDXGISwapChain>				mspSwapChain{};
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				mspRenderTarget{}; // ��ǥ�� ��ũ, ����� ��..
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				mspDepthStencil{};
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>		mspRenderTargetView{};
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>		mspDepthStencilView{};

private:
	void InitWindow(HINSTANCE hInstance);
	void InitD3D();
	void CalculateFPS();

protected:
	void OnResize();
	void RenderFrame();
	virtual void Render() {};
	virtual void Update(float delta) {};

public:
	virtual void Initialize(HINSTANCE hInstance,
		int width = 800,
		int height = 600
	);
	virtual void Destroy();
	virtual void GameLoop();

public:
	LRESULT CALLBACK MessageHandle(HWND hwnd, UINT message,
		WPARAM wparam, LPARAM lparam);
	

};

static LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

