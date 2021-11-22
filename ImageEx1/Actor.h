#pragma once
#include "D2DFramework.h"

// Object
class Actor
{
protected:
	D2DFramework* mpFramework;
	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap;

	float mX;
	float mY;
	float mOpacity;

public:
	Actor() = delete;
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename,
		float x, float y, float opacity = 1.0f);
	virtual ~Actor(); // ²À virtual!

private:
	HRESULT LoadWICImage(LPCWSTR filename);
	void Draw(float x, float y, float opacity = 1.0f);

public:
	virtual void Draw();
	void SetPostion(float x, float y) { mX = x; mY = y; }
	void SetOpacity(float o) { mOpacity = 0; }


};


