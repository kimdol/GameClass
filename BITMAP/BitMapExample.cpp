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
	FillRectToBuffer(0, 0, 100, 100, D2D1::ColorF::Red);
	FillRectToBuffer(50, 50, 100, 100, D2D1::ColorF(0, 1, 0, 0.5f));
	DrawCircleToBuffer(200, 200, 100, D2D1::ColorF::Red);
	DrawLineToBuffer(100, 0, 100, 200, D2D1::ColorF::Yellow);
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
	UINT8* pCurrent = &mspBackBuffer[0];    // get이랑 같음

	for (int i = 0; i < BITMAP_WIDTH * BITMAP_HEIGHT; i++)
	{
		*pCurrent = static_cast<UINT8>(255 * color.r);
		*(pCurrent + 1) = static_cast<UINT8>(255 * color.g);
		*(pCurrent + 2) = static_cast<UINT8>(255 * color.b);
		*(pCurrent + 3) = static_cast<UINT8>(255 * color.a);

		pCurrent += BITMAP_BYTECOUNT;
	}

	//color.r  0 ~ 1
}

void BitMapExample::DrawPixelToBuffer(int x, int y, D2D1::ColorF color)
{

	// index = y * w * 4 + x = y * pitch + x
	int pitch = BITMAP_WIDTH * BITMAP_BYTECOUNT;
	int index = pitch * y + x * BITMAP_BYTECOUNT;
	// 기존 색상 * (1 - a) + 신규생상 * a (Alpha Blending 공식)
	float inverse = 1.0f - color.a;
	UINT8 red = static_cast<UINT8>(color.r * 255);
	UINT8 green = static_cast<UINT8>(color.g * 255);
	UINT8 blue = static_cast<UINT8>(color.b * 255);

	mspBackBuffer[index] = static_cast<UINT8>(
		mspBackBuffer[index] * inverse + red * color.a
		);
	mspBackBuffer[index + 1] = static_cast<UINT8>(
		mspBackBuffer[index + 1] * inverse + green * color.a
		);
	mspBackBuffer[index + 2] = static_cast<UINT8>(
		mspBackBuffer[index + 2] * inverse + blue * color.a
		);
	mspBackBuffer[index + 3] = static_cast<UINT8>(color.a * 255);

}

void BitMapExample::FillRectToBuffer(int left, int top, int width, int height, D2D1::ColorF color)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			DrawPixelToBuffer(x + left, y + top, color);
		}
	}
}

void BitMapExample::DrawCircleToBuffer(int x, int y, int r, D2D1::ColorF color)
{
	// 내가 한 것
	/*float rad = 0.0f;

	for (int rr = r; rr > 0; rr--)
	{
		while (rad < 2 * 3.14)
		{
			DrawPixelToBuffer(static_cast<int>(cos(static_cast<long double>(rad)) * rr) + x, 
				static_cast<int>(sin(static_cast<long double>(rad)) * rr) + y, 
				color);
			rad += 0.001f;
		}
		rad = 0.0f;
	}*/
	// 쌤이 한 것
	const double pi{ 3.141592 };
	double theta;

	for (theta = 0; theta < 2 * pi; theta += 0.0001)
	{
		DrawPixelToBuffer(
			static_cast<int>(x + cos(theta) * r),
			static_cast<int>(y + sin(theta) * r),
			color
		);
	}
}

void BitMapExample::DrawLineToBuffer(int x1, int y1, int x2, int y2, D2D1::ColorF color)
{
	// 내가 한 것
	/*int x = x1;
	while (x != x2)
	{
		DrawPixelToBuffer(x, (y2 - y1) / (x2 - x1) * (x - x1) + y1, color);
		x++;
	}*/
	// 쌤이 한 것
	float dx = static_cast<float>(x2 - x1);
	float dy = static_cast<float>(y2 - y1);

	if (dx == 0 && dy == 0)
	{
		return;
	}

	int sign{};

	if (abs(dx) > abs(dy))
	{
		sign = (dx < 0) ? -1 : 1;
		for (int x = x1; x != x2; x += sign)
		{
			int y = static_cast<int>(dy / dx * (x - x1) + y1);
			DrawPixelToBuffer(x, y, color);
		}
	}
	else
	{
		sign = (dy < 0) ? -1 : 1;
		for (int y = y1; y != y2; y += sign)
		{
			int x = static_cast<int>(dx / dy * (y - y1) + x1);
			DrawPixelToBuffer(x, y, color);
		}
	}
}
