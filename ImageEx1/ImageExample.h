#pragma once

#include <wincodec.h>
#include "D2DFramework.h"

// 글자 -> 다른 글자
//      암호화(endcoding) - 코덱(Codec) MPEG4
//      <-
//      복호화(decoding)

class ImageExample :
    public D2DFramework
{
    Microsoft::WRL::ComPtr<IWICImagingFactory> mspWICFactory;

    Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap[4];

public:
    virtual HRESULT Initialize(
        HINSTANCE hInstance,
        LPCWSTR title = L"Bitmap Example",
        UINT width = 1024,
        UINT height = 768
    ) override;

    virtual void Release() override;

    virtual void Render() override;

public:
    HRESULT LoadBMP(LPCWSTR filename, ID2D1Bitmap** ppBitmap);

    HRESULT LoadWICImage(LPCWSTR filename, ID2D1Bitmap** ppBitmap);

};

