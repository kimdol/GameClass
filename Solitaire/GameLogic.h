#pragma once
#include "Card.h"
#include <list>

//Game
//40���� ī�� ����(5x8)
//Ŭ�� ��
//��� �׸��� + ī�� �׸���
// ���� ����
// Ŭ���� ī�� üũ

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
