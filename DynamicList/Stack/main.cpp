#include <iostream>
#include "Stack.h"
void PrintInfo()
{
	std::cout << "<STACK>" << std::endl;
	std::cout << "[1] push" << std::endl;
	std::cout << "[2] pop" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "-------------------------" << std::endl;
}

void ProcessUserInput(Stack& stack)
{
	int command{ -1 };

	while (true)
	{
		Print(stack);

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;

		switch (command)
		{
			case PUSH:
			{
				int value;
				std::cout << "   push value : ";
				std::cin >> value;
				Push(stack, value);
				break;
			}

			case POP:
				Pop(stack);
				break;

			case EXIT:
				return;
				break;

			default:
				std::cout << "잘못된 명령입니다."
					<< std::endl;
				break;
		}
	}
}

int main()
{
	Stack myStack;

	Initialize(myStack);

	PrintInfo();
	ProcessUserInput(myStack);

	Release(myStack);

}