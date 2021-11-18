#pragma once
#include "D2DFramework.h"

// 가상의 그래픽카드
    // FrameBuffer : 1024 X 768 BITMAP
    // BackBuffer : 메모리
    // BackBuffer -> FrameBuffer
    // 시뮬레이션 FrameBuffer를 그려보면 됨

const int BITMAP_WIDTH = 1024;
const int BITMAP_HEIGHT = 768;
const int BITMAP_BYTECOUNT = 4; // RGBA

class BitMapExample :
    public D2DFramework
{
    Microsoft::WRL::ComPtr<ID2D1Bitmap> mspFrameBitmap{};
    std::unique_ptr<UINT8[]> mspBackBuffer{};

public:
	virtual HRESULT Initialize(HINSTANCE hInstance,
		LPCWSTR title = L"MyFramework",
		UINT width = 1024,
		UINT height = 768
	) override;
	virtual void Render() override;

    void PresentBuffer();
    void ClearBuffer(D2D1::ColorF color);
    void DrawPixelToBuffer(int x, int y, D2D1::ColorF color);
    void FillRectToBuffer(int left, int top, int width, int height,
        D2D1::ColorF color);
    void DrawCircleToBuffer(int x, int y, int r, D2D1::ColorF color);
    void DrawLineToBuffer(int x1, int y1, int x2, int y2, D2D1::ColorF color);
};