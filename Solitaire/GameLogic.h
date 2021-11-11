#pragma once
#include "Card.h"
#include <list>

//Game
//40장의 카드 관리(5x8)
//클릭 수
//배경 그리기 + 카드 그리기
// 게임 판정
// 클릭된 카드 체크

namespace solitaire
{
	class GameLogic
	{
	private:
		HWND mHwnd;
		const int BOARD_ROW = 5;
		const int BOARD_COLUMN = 0;
		const Gdiplus::RectF BOARD_COUNT_RECT{ 885.0f, 60.0f, 120.0f, 30.0f };

		std::unique_ptr<Gdiplus::Image> mBackground;
		std::list<Card> mDeck;

		int mFlipCount;

	public:
		void initialize(HWND hwnd);
		void Release();
		void Draw(Gdiplus::Graphics& gragics);
		void OnClick(int cursorX, int cursorY);

	private:
		void CreateCards();
	};
}
