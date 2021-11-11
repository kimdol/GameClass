#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include <memory>
//ī��
//����(3 : ��, ��, ����)
//�ո� / �޸�
//��ġ / ũ��(�׸��� ����)
//Ŭ���ϸ� ������
//����

namespace solitaire
{
	enum class Type
	{
		Wolf,
		Bear,
		Dragon
	};
	class Card
	{
	private:
		HWND mHwnd;
		Type mType;
		bool mIsFront; // �� : ��, ���� : �޸�
		int mX;
		int mY;

		std::unique_ptr<Gdiplus::Image> mBack;
		std::unique_ptr<Gdiplus::Image> mFront;

	public:
		Card(HWND hwnd, Type type, int x, int y);

		bool CheckClicked(int cursorX, int cursorY);
		void Flip(bool isFront);
		void Draw(Gdiplus::Graphics& graphics);
		void Invalidate();
	};
}

