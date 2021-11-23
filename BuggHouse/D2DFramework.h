#pragma once

#include <d2d1.h>
#include <wincodec.h>
#include <wrl/client.h>
#include "ComException.h"

class D2DFramework
{
private:
	const LPCWSTR WND_CLASS_NAME{ L"MyWindowClass" };

protected:
	HWND mHwnd{};

	Microsoft::WRL::ComPtr<ID2D1Factory> mspD2DFactory{};
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> mspRenderTarget{};

protected:
	HRESULT InitWindow(HINSTANCE hInstance, LPCWSTR title,
		UINT width, UINT height);
	HRESULT InitD2D();
	virtual HRESULT CreateDeviceResources();

public:
	HWND GetWindowHandle() { return mHwnd; };
	// 리턴값에 의해 소유권이 넘어갈수있어서 일반포인터로 씀
	ID2D1Factory* GetD2DFactory() { return mspD2DFactory.Get(); }
	ID2D1HwndRenderTarget* GetRenderTarget() { return mspRenderTarget.Get(); }

public:
	virtual HRESULT Initialize(HINSTANCE hInstance,
		LPCWSTR title = L"MyFramework",
		UINT width = 1024,
		UINT height = 768
	);
	virtual void Release();
	virtual int GameLoop();
	virtual void Render();

	static void ShowErrorMsg(LPCWSTR msg, LPCWSTR title = L"Error");

public:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message,
		WPARAM wparam, LPARAM lparam);

};

