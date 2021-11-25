#include "Bug.h"

// 동일한 방향으로 5번(5픽셀까지는 그대로 이동)
// 방향전환 ( 45도 단위 )
// 8 방향( UP, UP & RIGHT, RIGHT, DOWN & RIGHT ... )


Bug::Bug(D2DFramework* pFramework) : 
	Actor(pFramework, L"Data/bug1_1.png")
{
	RECT rct{};
	GetClientRect(pFramework->GetWindowHandle(), &rct);

	mX = static_cast<float>(rand() % (rct.right - rct.left));
	mY = static_cast<float>(rand() % (rct.bottom - rct.top));

	mSteps = 0;
	mIsDelete = false;
}
// 그래픽카드가 행렬과 벡터에 관련된 연산을 수행함(가속, SetTransform..)
void Bug::Draw()
{
	// 회전
	if (mSteps++ > 10) // 10프레임
	{
		mSteps = 0;
		mRotation += (rand() % 3 - 1) * 45;
	}
	// 전진
	auto curDir = UPVECTOR * D2D1::Matrix3x2F::Rotation(mRotation);
	mX += curDir.x;
	mY += curDir.y;

	auto size{ mpBitmap->GetPixelSize() };
	D2D1_RECT_F rect{ 0, 0, 
		static_cast<float>(size.width),  static_cast<float>(size.height) };

	auto matTranslate = D2D1::Matrix3x2F::Translation(mX, mY);
	auto matRotation = D2D1::Matrix3x2F::Rotation(mRotation,
		{ size.width * 0.5f, size.height * 0.5f });

	auto pRT = mpFramework->GetRenderTarget();
	pRT->SetTransform(matRotation * matTranslate);
	pRT->DrawBitmap(
		mpBitmap,
		rect,
		mOpacity
	);
}

bool Bug::IsClicked(POINT& pt)
{
	auto size{ mpBitmap->GetPixelSize() };
	D2D1_RECT_F rect{
		mX, mY,
		static_cast<float>(mX + size.width), static_cast<float>(mY + size.height)
	};

	if (pt.x >= rect.left && pt.x <= rect.right &&
		pt.y >= rect.top && pt.y <= rect.bottom)
	{
		mIsDelete = true;
		return true;
	}
	return false;
}
