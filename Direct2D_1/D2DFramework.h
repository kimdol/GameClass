#pragma once

#include <d2d1.h>
#include <wrl/client.h>
#include <exception>
#include <sstream>

class com_exception : public std::exception
{
private:
	HRESULT result;

public:
	com_exception(HRESULT hr) : result{ hr } {}
	virtual const char* what() const override
	{
		static char buf[128];

		sprintf_s(buf, 128, "Failure with HRESULT of 0X%08X", result);
		return buf;
	}

};

inline void ThrowIfFailed(HRESULT hr)
{
	if (FAILED(hr))
	{
		throw com_exception(hr);
	}
}


class D2DFramework
{
protected:
	Microsoft::WRL::ComPtr<ID2D1Factory> mspD2DFactory{};
	Microsoft::WRL::ComPtr<ID2D1HwndRenderTarget> mspRenderTarget{};

public:
	virtual HRESULT Init(HWND hwnd);
	virtual void Release();
	virtual void Render();

	static void ShowErrorMsg(LPCWSTR msg, LPCWSTR title = L"Error");

};

