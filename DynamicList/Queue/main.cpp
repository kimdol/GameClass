#include <iostream>
#include "Queue.h"

void PrintInfo()
{
	std::cout << "<QUEUE>" << std::endl;
	std::cout << "[1] enqueue" << std::endl;
	std::cout << "[2] dequeue" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "----------------------" << std::endl;
}

void ProcessUserInput(Queue& queue)
{
	int command{ -1 };
	while (true)
	{
		Print(queue);

		std::cout << std::endl;
		std::cout << "> ";
		std::cin >> command;
		switch (command)
		{
			case ENQUEUE:
			{
				int value;
				std::cout << "    enqueue value : ";
				std::cin >> value;
				Enqueue(queue, value);
				break;
			}

			case DEQUEUE:
				Dequeue(queue);
				break;

			case EXIT:
				return;
				break;

			default:
				std::cout <<
					"잘못된 명령입니다."
					<< std::endl;
				break;
		}
	}
}

int main()
{
	Queue myQueue;

	Initialize(myQueue);
	PrintInfo();

	ProcessUserInput(myQueue);

	Release(myQueue);
}