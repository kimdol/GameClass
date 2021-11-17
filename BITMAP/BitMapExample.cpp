#include "BitMapExample.h"

HRESULT BitMapExample::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
    D2DFramework::Initialize(hInstance, title, width, height);

    // 가상 BackBuffer
    mspBackBuffer = std::make_unique<UINT8[]>(
        BITMAP_WIDTH * BITMAP_HEIGHT * BITMAP_BYTECOUNT
        );

    // 가상 FrameBuffer
    HRESULT hr = mspRenderTarget->CreateBitmap(
        D2D1::SizeU(BITMAP_WIDTH, BITMAP_HEIGHT),
        D2D1::BitmapProperties(
            D2D1::PixelFormat(DXGI_FORMAT_R8G8B8A8_UNORM, D2D1_ALPHA_MODE_IGNORE)
        ),
        mspFrameBitmap.GetAddressOf()
    );
    ThrowIfFailed(hr);

    return hr;
}

void BitMapExample::Render()
{
    mspRenderTarget->BeginDraw();
    mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

    ClearBuffer(D2D1::ColorF::LightPink);
    PresentBuffer();

    mspRenderTarget->DrawBitmap(mspFrameBitmap.Get());

    mspRenderTarget->EndDraw();
}

void BitMapExample::PresentBuffer()
{
    mspFrameBitmap->CopyFromMemory(nullptr, mspBackBuffer.get(), 
        BITMAP_WIDTH * BITMAP_BYTECOUNT);
}

void BitMapExample::ClearBuffer(D2D1::ColorF color)
{
    //mspBackBuffer -> 0 ~ 255

    for (int i = 0; i < BITMAP_WIDTH * BITMAP_HEIGHT * 4;)
    {
        mspBackBuffer[i++] = 255 * color.r;
        mspBackBuffer[i++] = 255 * color.g;
        mspBackBuffer[i++] = 255 * color.b;
        mspBackBuffer[i++] = 255 * color.a;
    }
    
    //color.r  0 ~ 1
}
