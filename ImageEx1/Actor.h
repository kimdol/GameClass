#pragma once
#include "D2DFramework.h"

// Object
class Actor
{
protected:
	D2DFramework* mpFramework;
	ID2D1Bitmap* mpBitmap;

	float mX;
	float mY;
	float mOpacity;

public:
	Actor() = delete;
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename,
		float x, float y, float opacity = 1.0f);
	virtual ~Actor(); // ?? virtual!

private:
	void Draw(float x, float y, float opacity = 1.0f);

public:
	virtual void Draw();
	void SetPostion(float x, float y) { mX = x; mY = y; }
	void SetOpacity(float o) { mOpacity = 0; }


};


