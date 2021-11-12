#include "GameLogic.h"
#include <string>

namespace solitaire
{
	void GameLogic::initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mFlipCount = 0;
		mDeck.clear();

		mBackground = std::make_unique<Gdiplus::Image>(L"Data/bg_blank.png");
		CreateCards();
	}
	void GameLogic::Release()
	{
		mDeck.clear();
		mBackground.reset(); // �̽������� ����Ʈ ������ ��������
	}
	void GameLogic::Draw(Gdiplus::Graphics& graphics)
	{
		graphics.DrawImage(mBackground.get(), 0, 0, mBackground->GetWidth(), mBackground->GetHeight());

		for (auto& card : mDeck)
		{
			card.Draw(graphics);
		}

		Gdiplus::SolidBrush brush(Gdiplus::Color::HotPink);
		Gdiplus::Font font(L"���� ���", 20);
		Gdiplus::PointF pos(895.0f, 20.0f);

		graphics.DrawString(L"Ŭ����:", -1, &font, pos, &brush);
		Gdiplus::StringFormat format;
		format.SetAlignment(Gdiplus::StringAlignmentCenter);
		format.SetLineAlignment(Gdiplus::StringAlignmentCenter);
		graphics.DrawString(std::to_wstring(mFlipCount).c_str(), -1, &font, BOARD_COUNT_RECT, &format, &brush);
	}
	void GameLogic::OnClick(int cursorX, int cursorY)
	{
		for (auto& card : mDeck)
		{
			if (card.CheckClicked(cursorX, cursorY))
			{

			}
		}
	}
	void GameLogic::CreateCards()
	{
		// TODO : ī�� �����ؾ� ��
		mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Bear, 0, 0));
		mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Wolf, 150, 0));
		mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Dragon, 300, 0));
	}
}
