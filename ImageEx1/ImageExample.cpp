#include<fstream>
#include <vector>
#include "ImageExample.h"

#pragma commnet(lib, "WindowCodecs.lib")

HRESULT ImageExample::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
	HRESULT hr;

	// COM
	hr = CoInitialize(nullptr);
	ThrowIfFailed(hr);

	hr = ::CoCreateInstance(CLSID_WICImagingFactory,
		nullptr,
		CLSCTX_INPROC_SERVER,
		IID_PPV_ARGS(mspWICFactory.GetAddressOf())
		);
	ThrowIfFailed(hr);
	// �������̽� ����ϱ� ���� �غ����� ������� ��


	D2DFramework::Initialize(hInstance, title, width, height);

	//hr = LoadBMP(L"Data/32.bmp", mspBitmap.GetAddressOf());
	hr = LoadWICImage(L"Data/32.bmp", mspBitmap.GetAddressOf());

	return hr;
}

void ImageExample::Release()
{
	D2DFramework::Release();

	mspWICFactory.Reset();

	CoUninitialize();
}

void ImageExample::Render()
{
	mspRenderTarget->BeginDraw();
	mspRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Aquamarine));

	mspRenderTarget->DrawBitmap(mspBitmap.Get());

	mspRenderTarget->EndDraw();
}

HRESULT ImageExample::LoadBMP(LPCWSTR filename, ID2D1Bitmap** ppBitmap)
{
	// 1. ���� ����
	std::ifstream file;
	file.open("Data/32.bmp", std::ifstream::binary);

	// 2. BITMAPFILEHEADER
	BITMAPFILEHEADER bmh;
	file.read(reinterpret_cast<char*>(&bmh), sizeof(BITMAPFILEHEADER));

	// 3. BITMAPFILEHEADER
	BITMAPINFOHEADER bmi;
	file.read(reinterpret_cast<char*>(&bmi), sizeof(BITMAPINFOHEADER));

	if (bmh.bfType != 0x4D42)
	{
		return  E_FAIL;
	}
	if (bmi.biBitCount != 32)
	{
		return E_FAIL;
	}

	// 4. bfOffBits ����ŭ �ǳʶٱ�
	file.seekg(bmh.bfOffBits);

	// 5. �ȼ� ������ �б�
	std::vector<char>pPixels(bmi.biSizeImage);
	int pitch = bmi.biWidth * (bmi.biBitCount / 8);
	
	/*for (int h = (bmi.biHeight - 1); h >= 0; h--)
	{
		file.read(&pPixels[h * pitch], pitch);
	}*/
	for (int y = (bmi.biHeight - 1); y >= 0; y--)
	{
		int index = y * pitch;
		for (int x = 0; x < bmi.biWidth; x++)
		{
			char r{}, g{}, b{}, a{};

			file.read(&b, 1);
			file.read(&g, 1);
			file.read(&r, 1);
			file.read(&a, 1);

			if (b == (char)250 && g == (char)199 && r == (char)30)
			{
				r = g = b = a = 0;
			}

			pPixels[index++] = b;
			pPixels[index++] = g;
			pPixels[index++] = r;
			pPixels[index++] = a;

		}
	}
	

	HRESULT hr = mspRenderTarget->CreateBitmap(
		D2D1::SizeU(bmi.biWidth, bmi.biHeight),
		D2D1::BitmapProperties(
			D2D1::PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED)
		),
		ppBitmap
	);
	ThrowIfFailed(hr);

	hr = (*ppBitmap)->CopyFromMemory(
		nullptr,
		&pPixels[0],
		pitch
	);
	ThrowIfFailed(hr);

	file.close();

	return hr;
}

HRESULT ImageExample::LoadWICImage(LPCWSTR filename, ID2D1Bitmap** ppBitmap)
{
	// WIC
	// 1. ���ڴ��� ����
	
	// 2. ������ ����
	
	// 3. Format Converter (R8G8B8A8...)
	
	// 4. �츮�� ���ϴ� BGRA8888 �������� �ȼ� �迭



	return E_NOTIMPL;
}
