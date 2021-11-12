#include "GameLogic.h"
#include <vector>
#include <random>
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
		mBackground.reset(); // 이시점에서 스마트 포인터 수동제거
	}
	void GameLogic::Draw(Gdiplus::Graphics& graphics)
	{
		graphics.DrawImage(mBackground.get(), 0, 0, mBackground->GetWidth(), mBackground->GetHeight());

		for (auto& card : mDeck)
		{
			card.Draw(graphics);
		}

		Gdiplus::SolidBrush brush(Gdiplus::Color::HotPink);
		Gdiplus::Font font(L"밝은 고딕", 20);
		Gdiplus::PointF pos(895.0f, 20.0f);

		graphics.DrawString(L"클릭수:", -1, &font, pos, &brush);
		Gdiplus::StringFormat format;
		format.SetAlignment(Gdiplus::StringAlignmentCenter);
		format.SetLineAlignment(Gdiplus::StringAlignmentCenter);
		graphics.DrawString(std::to_wstring(mFlipCount).c_str(), -1, &font, BOARD_COUNT_RECT, &format, &brush);
	}
	void GameLogic::OnClick(int cursorX, int cursorY)
	{
		Card* pCard{};

		for (auto& card : mDeck)
		{
			if (card.CheckClicked(cursorX, cursorY))
			{
				pCard = &card;
				break;
			}
		}

		if (pCard)
		{
			mFlipCount++;
			RECT rct{
				BOARD_COUNT_RECT.GetLeft(), BOARD_COUNT_RECT.GetTop(),
				BOARD_COUNT_RECT.GetRight(), BOARD_COUNT_RECT.GetBottom()

			};
			InvalidateRect(mHwnd, &rct, false);

			if (mpSelectedCard == nullptr)
			{
				mpSelectedCard = pCard;
			}
			else
			{
				if (mpSelectedCard == pCard)
				{
					mpSelectedCard == nullptr;
				}
				else
				{
					if (mpSelectedCard->GetType() == pCard->GetType())
					{
						pCard->Invalidate();
						mpSelectedCard->Invalidate();

						mDeck.remove_if([&](Card& card) {
							return (card.GetIndex() == mpSelectedCard->GetIndex()
								|| card.GetIndex() == pCard->GetIndex()
								);
						});
						mpSelectedCard = nullptr;
					}
					else
					{
						UpdateWindow(mHwnd);
						// ms
						// 1s == 1000ms
						Sleep(500);

						pCard->Flip(false);
						mpSelectedCard->Flip(false);

						mpSelectedCard = nullptr;
					}
				}
			}
		}

		
	}
	void GameLogic::CreateCards()
	{
		std::vector<Type> types;
		while(types.size() < static_cast<size_t>(BOARD_ROW) * BOARD_COLUMN)
		{
			int mod = types.size() % 6;

			// 0, 2, 4, 5, 8, 10, 12
			switch (mod)
			{
				case 0:
					types.push_back(Type::Bear);
					types.push_back(Type::Bear);
					break;
				case 2:
					types.push_back(Type::Wolf);
					types.push_back(Type::Wolf);
					break;
				case 4:
					types.push_back(Type::Dragon);
					types.push_back(Type::Dragon);
					break;
			}
		}
		std::random_device rd;
		std::mt19937 gen{ rd() };   // funtor(함수 + 객체)
		// std::uniform_int_distribution<> dist(0, deck.size() - 1);
		std::shuffle(types.begin(), types.end(), gen);

		int posX{ 15 }, posY{ 10 };
		int index = 0;
		for (int x = 0; x < BOARD_COLUMN; x++)
		{
			posY = 10;
			for (int y = 0; y < BOARD_ROW; y++)
			{
				mDeck.push_back(solitaire::Card(mHwnd, index, types[index++], posX, posY));
				posY += 140 + 10;
			}
			posX += 100 + 10;
		}


		// mDeck.push_back(solitaire::Card(mHwnd, solitaire::Type::Bear, 0, 0));
	}
}
