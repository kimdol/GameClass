#include "Bug.h"

// ������ �������� 5��(5�ȼ������� �״�� �̵�)
// ������ȯ ( 45�� ���� )
// 8 ����( UP, UP & RIGHT, RIGHT, DOWN & RIGHT ... )


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
// �׷���ī�尡 ��İ� ���Ϳ� ���õ� ������ ������(����, SetTransform..)
void Bug::Draw()
{
	// ȸ��
	if (mSteps++ > 10) // 10������
	{
		mSteps = 0;
		mRotation += (rand() % 3 - 1) * 45;
	}
	// ����
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
