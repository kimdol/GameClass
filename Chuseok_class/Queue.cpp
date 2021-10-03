#include "Queue.h"

Queue::Queue()
{
}

Queue::~Queue()
{
	DeleteAll();
	mHead = mTail = nullptr;
}

void Queue::Enqueue(std::string name, int hp)
{
	// 새로운 monster 만들기
	Monster* elem{ new Monster{name, hp, nullptr, nullptr} };
	// top에 새로운 monster 삽입
	if (!mHead)
	{
		mHead = mTail = elem;
	}
	else
	{
		mHead->prev = elem;
		elem->nxt = mHead;
		mHead = elem;
	}
}

void Queue::Dequeue()
{
	if (mHead == nullptr)
	{
		return;
	}
	if (mHead == mTail)
	{
		delete mHead;
		mHead = mTail = nullptr;
	}
	else
	{
		// tail 옮기기
		mTail = mTail->prev;
		// tail delete
		delete mTail->nxt;
		// tail prev의 next = tail의 next
		mTail->nxt = nullptr;
	}
}

//void Queue::PrintQueue()
//{
//	Monster* elem{ mHead };
//
//	std::cout <<
//		"Head => ";
//	while (elem)
//	{
//		std::cout <<
//			elem->name << ":" << elem->hp
//			<< " -> ";
//		elem = elem->nxt;
//	}
//	std::cout <<
//		"Tail" << std::endl;
//}
//
//void Queue::AllDelete()
//{
//	Monster* elem{ mHead }, * nxt{};
//
//	while (elem)
//	{
//		nxt = elem->nxt;
//		delete elem;
//		elem = nxt;
//	}
//}
