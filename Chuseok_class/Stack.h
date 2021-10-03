#pragma once
#include <iostream>
#include "SingleLinkedList.h"

class Stack : public SingleLinkedList
{
private:
	Monster* mTop;

public:
	Stack();
	~Stack();

	void Push(std::string name, int hp);
	void Pop();
	// void PrintStack();
	// void AllDelete();

};

