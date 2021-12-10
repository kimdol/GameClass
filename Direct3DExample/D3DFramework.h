#pragma once
// 1. 디바이스 생성 (그래픽카드 접근을 위함(변수))
//		DC (Device Context)
// 2. 스왑 체인 ( 버퍼링 )
// 3. RenderTarget - 백버퍼 지정
// 4. 깊이-스텐실 버퍼(depth:24byte, Stencil:8)
// 5. 뷰포트 ( 카메라 )
// 6. 화면에 그리기 ( back -> front )

#define WIN32_LEAN_AND_MEAU // 쓸대없는거 포함안시킴(컴파일,실행속도도 빨라짐)

#include <Windows.h> // GDI, 프린터, 네트워크 (랜카드, 모뎀), 사운드 카드..등등
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
	Microsoft::WRL::ComPtr<ID3D11Texture2D>				mspRenderTarget{}; // 목표는 디스크, 모니터 등..
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

