#include "Stack.h"

Stack::Stack() : mTop{ nullptr }
{
}

Stack::~Stack()
{
	DeleteAll();

	mTop = nullptr;
}

void Stack::Push(std::string name, int hp)
{
	// ���ο� monster �����
	Monster* elem{ new Monster{name, hp, nullptr} };
	// top�� ���ο� monster ����
	elem->nxt = mTop;
	mTop = elem;

	// ����� ���� ��
	mHead = elem;
}

void Stack::Pop()
{
	if (mTop != nullptr)
	{
		Monster* nxt{ mTop->nxt };
		// top�� �ִ°� delete
		delete mTop;
		// top �̵�
		mTop = nxt;

		// ����� ���� ��
		mHead = nxt;
	}
}

/*void Stack::PrintStack()
{
	Monster* elem{ mTop };

	while (elem)
	{
		std::cout <<
			elem->name << " : " << elem->hp
			<< std::endl;
		elem = elem->nxt;
	}
}*/

//void Stack::AllDelete()
//{
//	Monster* elem{ mTop }, *next{};
//
//	while (elem)
//	{
//		next = elem->nxt;
//		delete elem;
//		elem = next;
//	}
//}
