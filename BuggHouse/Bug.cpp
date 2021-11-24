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

	mDir = Direction::UP;
	mSteps = 0;
}

void Bug::Draw()
{
	if (mSteps++ > 10)
	{
		mSteps = 0;

		// 방향전환
		int dir = static_cast<int>(mDir);
		int count = static_cast<int>(Direction::COUNT);

		dir += (rand() % 3 - 1);
		dir = (dir + count) % count;
		mDir = static_cast<Direction>(dir);
	}

	switch (mDir)
	{
		case Direction::UP:
			mY--;
			break;
		case Direction::UP_RIGHT:
			mY--;
			mX++;
			break;
		case Direction::RIGHT:
			mX++;
			break;
		case Direction::DOWN_RIGHT:
			mY++;
			mX++;
			break;
		case Direction::DOWN:
			mY++;
			break;
		case Direction::DOWN_LEFT:
			mY++;
			mX--;
			break;
		case Direction::LEFT:
			mX--;
			break;
		case Direction::UP_LEFT:
			mY--;
			mX--;
			break;
	}

	mX += static_cast<float>(rand() % 3 - 1);
	mY += static_cast<float>(rand() % 3 - 1);

	Actor::Draw();
}
