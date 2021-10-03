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
	// 새로운 monster 만들기
	Monster* elem{ new Monster{name, hp, nullptr} };
	// top에 새로운 monster 삽입
	elem->nxt = mTop;
	mTop = elem;

	// 상속을 위한 것
	mHead = elem;
}

void Stack::Pop()
{
	if (mTop != nullptr)
	{
		Monster* nxt{ mTop->nxt };
		// top에 있는거 delete
		delete mTop;
		// top 이동
		mTop = nxt;

		// 상속을 위한 것
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
