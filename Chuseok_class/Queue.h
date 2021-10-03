#pragma once
#include <iostream>
#include "SingleLinkedList.h"

class Queue : public SingleLinkedList
{
//private:
//	Monster* mHead;
//	Monster* mTail;

public:
	Queue();
	~Queue();

	void Enqueue(std::string name, int hp);
	void Dequeue();
	// void PrintQueue();
	// void AllDelete();
};

