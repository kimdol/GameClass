#include <iostream>
/*JuHo_Stack2*/
//struct StackNubbin
//{
//    int value;
//    StackNubbin* nxt;
//    StackNubbin* prev;
//};
//bool push(StackNubbin* nubbin, int value)
//{
//    while (nubbin->nxt)
//    {
//        nubbin = nubbin->nxt;
//    }
//    nubbin->nxt = new StackNubbin{ value, nullptr, nubbin };
//    return true;
//}
//bool pop(StackNubbin* nubbin)
//{
//    while (nubbin->nxt)
//    {
//        nubbin = nubbin->nxt;
//    }
//
//    nubbin->prev->nxt = nullptr;
//    delete nubbin;
//
//    return true;
//}
//void ArrPrint(StackNubbin* nubbin)
//{
//    while (nubbin)
//    {
//        std::cout << nubbin->value << " ";
//        nubbin = nubbin->nxt;
//    }
//    std::cout << std::endl;
//}
//void stackDelte(StackNubbin** nubbin)
//{
//    StackNubbin* del{ *nubbin };
//    StackNubbin* tmp{ *nubbin };
//    *nubbin = nullptr;
//
//    while (del)
//    {
//        tmp = tmp->nxt;
//        delete del;
//        del = tmp;
//    }
//}
/*Class Stack*/
//const int STACK_SIZE{ 10 };
//enum Command
//{
//    PUSH = 1,
//    POP = 2,
//    EXIT = 3
//};
//struct Stack
//{
//    int container[STACK_SIZE]{};
//    int topIndex{ -1 };
//};
//void PrintInfo()
//{
//    std::cout << "<STACK>" << std::endl;
//    std::cout << "[1] push" << std::endl;
//    std::cout << "[2] POP" << std::endl;
//    std::cout << "[3] exit" << std::endl;
//    std::cout << "-----------------------------------" << std::endl;
//}
//void PrintStack(const Stack& stack)
//{
//    std::cout << "--- stack ---" << std::endl;
//
//    if (stack.topIndex < 0)
//    {
//        return;
//    }
//
//    for (int i = stack.topIndex; i >= 0; --i)
//    {
//        std::cout << stack.container[i] << std::endl;
//    }
//
//    std::cout << "---------------" << std::endl;
//}
//void Push(Stack& stack, int value)
//{
//    if (stack.topIndex >= STACK_SIZE - 1)
//    {
//        std::cout << "스택이 가득 찼습니다."
//            << std::endl;
//        return;
//    }
//
//    stack.container[++stack.topIndex] = value;
//}
//void Pop(Stack& stack)
//{
//    if (stack.topIndex < 0)
//    {
//        std::cout << "스택이 비었습니다."
//            << std::endl;
//        return;
//    }
//    std::cout << "pop : "
//        << stack.container[stack.topIndex--]
//        << std::endl;
//}
//bool ProcessUserInput(Stack& stack)
//{
//    int command{ -1 };
//
//    std::cout << std::endl;
//    std::cout << "> ";
//    std::cin >> command;
//
//    switch (command)
//    {
//        case PUSH:
//        {
//            int value{};
//            std::cout << "    push value >> ";
//            std::cin >> value;
//            Push(stack, value);
//            break;
//        }
//
//        case POP:
//            Pop(stack);
//            break;
//
//        case EXIT:
//            return false;
//            break;
//
//        default:
//            std::cout << "잘못된 명령어입니다!"
//                << std::endl;
//            break;
//    }
//}
/*JuHo_Que*/
enum QueCommand
{
	PUSH = 1,
	POP = 2,
	EXIT = 3
};
const int QUE_SIZE{ 5 };
struct Queue
{
	int head{ -1 };
	int tail{ -1 };
	int container[QUE_SIZE]{};
};
void PrintInfo(Queue& que)
{
	int nxt{ que.head };
	std::cout << "<STACK>" << std::endl;
	std::cout << "[1] push" << std::endl;
	std::cout << "[2] POP" << std::endl;
	std::cout << "[3] exit" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	while (nxt < que.tail)
	{
		std::cout << que.container[nxt + 1]
			<< " ";
		nxt++;
	}
	std::cout << std::endl;
	// 만약 head가 QUE_SIZE 넘어가면 초기화
	if ((que.tail >= QUE_SIZE - 1) && (que.head >= QUE_SIZE - 1))
	{
		que.tail = -1;
		que.head = -1;
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
void Push(Queue& que, int value)
{
	if (que.tail >= QUE_SIZE - 1)
	{
		std::cout << "que is full"
			<< std::endl;
		return;
	}
	que.container[++que.tail] = value;
}
void Pop(Queue& que)
{
	if (que.head >= que.tail)
	{
		std::cout << "que is 빔"
			<< std::endl;
		return;
	}
	std::cout << que.container[(que.head)++]
		<< " POP!" << std::endl;
}
bool QueProcess(const QueCommand& command, Queue& que)
{
	switch (command)
	{
		case PUSH:
			Push(que, ValueIn());
			break;

		case POP:
			Pop(que);
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
	/*JuHo_Que*/
	Queue que;
	while (true)
	{
		// 화면 출력
		PrintInfo(que);
		// 입력
		QueCommand input;
		if (Input(input))
		{
		}
		// 입력된 기능 수행(큐, 종료 포함)
		if (QueProcess(input, que))
		{
			std::cout << "Queue를 종료합니다. "
				<< std::endl;
			break;
		}
	}
}
