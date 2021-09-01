#include <iostream>
//
/*Class_Que*/
enum QueCommand
{
	ENQUEUE = 1,
	DEQUEUE = 2,
	EXIT = 3
};
const int QUE_SIZE{ 5 };
struct Queue
{
	int head{ 0 };
	int tail{ 0 };
	int container[QUE_SIZE]{};
};
void PrintInfo(Queue& que)
{
	std::cout << "<STACK>" << std::endl;
	std::cout << "[1] enqueue" << std::endl;
	std::cout << "[2] dequeue" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "-----------------queue----------------" << std::endl;

	int i = que.head;
	while (i != que.tail)
	{
		i = (i + 1) % QUE_SIZE;
		std::cout << que.container[i]
			<< std::endl;
	}

	if (que.head == que.tail)
	{
		std::cout << "--------------------------------------" << std::endl;
	}
}
bool Input(QueCommand& input)
{
	int command;
	std::cout << std::endl;
	std::cout << "> ";
	std::cin >> command;

	if ((command > 3) || (command < 1))
	{
		std::cout << "잘못된 명령입니다"
			<< std::endl;
		return false;
	}

	input = (QueCommand)command;
	return true;
}
int ValueIn()
{
	int value;
	std::cout << "    push value >> ";
	std::cin >> value;

	return value;
}
void Enqueue(Queue& que, int value)
{
	if ((que.tail + 1) % QUE_SIZE == que.head)
	{
		std::cout << "--------------------------------\n";
		std::cout << "que is full"
			<< std::endl;
		std::cout << "--------------------------------\n\n";
		return;
	}
	que.tail = (que.tail + 1) % QUE_SIZE;
	que.container[que.tail] = value;
}
void Dequeue(Queue& que)
{
	if (que.head == que.tail)
	{
		std::cout << "--------------------------------\n";
		std::cout << "que is 빔"
			<< std::endl;
		std::cout << "--------------------------------\n\n";
		return;
	}
	std::cout << "--------------------------------\n";
	que.head = (que.head + 1) % QUE_SIZE;
	std::cout << que.container[que.head]
		<< " POP!" << std::endl;
	std::cout << "--------------------------------\n\n";
}
bool QueProcess(const QueCommand& command, Queue& que)
{
	switch (command)
	{
		case ENQUEUE:
			Enqueue(que, ValueIn());
			break;

		case DEQUEUE:
			Dequeue(que);
			break;

		case EXIT:
			return true;
			break;

		default:
			std::cout << "잘못된 명령어입니다!"
				<< std::endl;
			break;
	}
	return false;
}
int main()
{
	/*Class_Que*/
	Queue myQue;
	while (true)
	{
		// 화면 출력
		PrintInfo(myQue);
		// 입력
		QueCommand input;
		if (Input(input))
		{
		}
		// 입력된 기능 수행(큐, 종료 포함)
		if (QueProcess(input, myQue))
		{
			std::cout << "Queue를 종료합니다. "
				<< std::endl;
			break;
		}
	}
}
