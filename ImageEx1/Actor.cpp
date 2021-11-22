#include "Actor.h"

Actor::Actor(D2DFramework* pFramework, LPCWSTR filename) :
    mpFramework{pFramework},
    mspBitmap{},
    mX{},
    mY{},
    mOpacity{ 1.0f }
{
    LoadWICImage(filename);
}

Actor::Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity) :
    Actor(pFramework, filename) // 대리 생성자
{
    mX = x;
    mY = y;
    mOpacity = opacity;
}

Actor::~Actor()
{
    mspBitmap.Reset();
}

HRESULT Actor::LoadWICImage(LPCWSTR filename)
{
	auto pWICFactory{ mpFramework->GetWICFactory() };
	if (pWICFactory == nullptr)
	{
		return E_FAIL;
	}

	// WIC
	// 1. 디코더를 생성
	Microsoft::WRL::ComPtr<IWICBitmapDecoder>bitmapDecoder;
	HRESULT hr;

	hr = pWICFactory->CreateDecoderFromFilename(
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
	hr = pWICFactory->CreateFormatConverter(converter.GetAddressOf());
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
	auto pRenderTarget{ mpFramework->GetRenderTarget() };
	if (pRenderTarget == nullptr)
	{
		return E_FAIL;
	}
	hr = pRenderTarget->CreateBitmapFromWicBitmap(
		converter.Get(),
		mspBitmap.GetAddressOf()
	);
	ThrowIfFailed(hr);

	return hr;
    return E_NOTIMPL;
}

void Actor::Draw(float x, float y, float opacity)
{
	auto size{ mspBitmap->GetPixelSize() };
	D2D1_RECT_F rect{
		x, y,
		static_cast<float>(x + size.width),
		static_cast<float>(y + size.height)
	};

	mpFramework->GetRenderTarget()->DrawBitmap(
		mspBitmap.Get(),
		rect,
		opacity
	);
}

void Actor::Draw()
{
	Draw(mX, mY, mOpacity);
}
