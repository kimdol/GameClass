#include<fstream>
#include <vector>
#include "ImageExample.h"

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
	// 인터페이스 사용하기 위한 준비절차 여기까지 끝


	D2DFramework::Initialize(hInstance, title, width, height);

	//hr = LoadBMP(L"Data/32.bmp", mspBitmap.GetAddressOf());
	hr = LoadWICImage(L"Data/bg.png", mspBitmap[0].GetAddressOf());
	hr = LoadWICImage(L"Data/bg2.png", mspBitmap[1].GetAddressOf());
	hr = LoadWICImage(L"Data/enemy.png", mspBitmap[2].GetAddressOf());
	hr = LoadWICImage(L"Data/player.png", mspBitmap[3].GetAddressOf());

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

	mspRenderTarget->DrawBitmap(
		mspBitmap[0].Get(),
		D2D1::RectF(
			0,
			0,
			1000,
			500
		)
	);
	mspRenderTarget->DrawBitmap(
		mspBitmap[2].Get(),
		D2D1::RectF(
			0,
			0,
			300,
			500
		)
	);
	mspRenderTarget->DrawBitmap(
		mspBitmap[1].Get(),
		D2D1::RectF(
			0,
			0,
			300,
			500
		)
	);
	mspRenderTarget->DrawBitmap(
		mspBitmap[3].Get(),
		D2D1::RectF(
			500,
			0,
			300,
			500
		)
	);
	mspRenderTarget->DrawBitmap(
		mspBitmap[3].Get(),
		D2D1::RectF(
			500,
			100,
			300,
			500
		)
	);

	mspRenderTarget->EndDraw();
}

HRESULT ImageExample::LoadBMP(LPCWSTR filename, ID2D1Bitmap** ppBitmap)
{
	// 1. 파일 열기
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

	// 4. bfOffBits 값만큼 건너뛰기
	file.seekg(bmh.bfOffBits);

	// 5. 픽셀 데이터 읽기
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
	// 1. 디코더를 생성
	Microsoft::WRL::ComPtr<IWICBitmapDecoder>bitmapDecoder;
	HRESULT hr;

	hr = mspWICFactory->CreateDecoderFromFilename(
		filename,
		nullptr, // const GUID
		GENERIC_READ,
		WICDecodeMetadataCacheOnLoad, 
		bitmapDecoder.GetAddressOf()
		);
	ThrowIfFailed(hr);
	
	// 2. 프레임 선택
	Microsoft::WRL::ComPtr<IWICBitmapFrameDecode>frame;
	hr = bitmapDecoder->GetFrame(0, frame.GetAddressOf());
	ThrowIfFailed(hr);

	// 3. Format Converter (우리가 원하는 BGRA8888)
	Microsoft::WRL::ComPtr<IWICFormatConverter> converter;
	hr = mspWICFactory->CreateFormatConverter(converter.GetAddressOf());
	ThrowIfFailed(hr);

	hr = converter->Initialize(
		frame.Get(),
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		nullptr,
		0,
		WICBitmapPaletteTypeCustom
	);
	ThrowIfFailed(hr);

	// 4. 픽셀 배열
	hr = mspRenderTarget->CreateBitmapFromWicBitmap(
		converter.Get(),
		ppBitmap
	);
	ThrowIfFailed(hr);
	
	return hr;
}
