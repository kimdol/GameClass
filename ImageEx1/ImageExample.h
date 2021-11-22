#pragma once

#include <wincodec.h>
#include "D2DFramework.h"

// ���� -> �ٸ� ����
//      ��ȣȭ(endcoding) - �ڵ�(Codec) MPEG4
//      <-
//      ��ȣȭ(decoding)

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

