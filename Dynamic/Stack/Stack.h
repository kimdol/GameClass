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

/*���� ���α׷��ֿ��� �ʼ� �Լ�*/
void Initialize(Stack& stack);
void Release(Stack& stack);
/*�Ϲ� �Լ�*/
void Push(Stack& stack, int value);
bool Pop(Stack& stack);
void Print(Stack& stack);
