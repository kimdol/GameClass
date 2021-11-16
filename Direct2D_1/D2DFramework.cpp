#include "D2DFramework.h"

#pragma comment (lib, "d2d1.lib")

HRESULT D2DFramework::Init(HWND hwnd)
{
	// 1. Direct2D Factory 积己
	HRESULT hr = D2D1CreateFactory(
		D2D1_FACTORY_TYPE_SINGLE_THREADED, mspD2DFactory.GetAddressOf());
	ThrowIfFailed(hr);
	// 2. 坊歹 鸥百 积己
	RECT wr;
	GetClientRect(hwnd, &wr);
	hr = mspD2DFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(
			hwnd, 
			D2D1::SizeU(wr.right - wr.left, wr.bottom - wr.top)),
		mspRenderTarget.GetAddressOf()
	);
	ThrowIfFailed(hr);

	return S_OK;
}

void D2DFramework::Release()
{
}

void D2DFramework::Render()
{
	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
	
	// TODO : 弊府扁

	mspRenderTarget->EndDraw();
}

void D2DFramework::ShowErrorMsg(LPCWSTR msg, LPCWSTR title)
{
	OutputDebugString(msg);

	MessageBox(nullptr, msg,
		title, MB_OK | MB_ICONEXCLAMATION);

}