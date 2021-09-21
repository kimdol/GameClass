#pragma once
#include <iostream>

struct Monster
{
	std::string name{};
	int hp{};

	Monster* nxt{};
};

class Stack
{
private:
	Monster* mTop;

public:
	Stack();
	~Stack();

	void Push(std::string name, int hp);
	void Pop();
	void PrintStack();
	void AllDelete();

};

