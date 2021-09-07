#pragma once
#include <iostream>

enum Command
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};

struct Element
{
	int value;
	Element* pNext;
};

struct Stack
{
	int count;
	Element* top;
};

/*게임 프로그래밍에서 필수 함수*/
void Initialize(Stack& stack);
void Release(Stack& stack);
/*일반 함수*/
void Push(Stack& stack, int value);
bool Pop(Stack& stack);
void Print(Stack& stack);
