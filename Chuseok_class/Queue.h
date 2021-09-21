#pragma once
#include <iostream>

struct Monster
{
	std::string name{};
	int hp{};

	Monster* nxt{};
	Monster* prev{};
};
class Queue
{
private:
	Monster* mHead;
	Monster* mTail;

public:
	Queue();
	~Queue();

	void Enqueue(std::string name, int hp);
	void Dequeue();
	void PrintQueue();
	void AllDelete();
};

