#include <iostream>

/*JuHo_Stack2*/
struct StackNubbin
{
    int value;
    StackNubbin* nxt;
    StackNubbin* prev;
};
bool push(StackNubbin* nubbin, int value)
{
    while (nubbin->nxt)
    {
        nubbin = nubbin->nxt;
    }
    nubbin->nxt = new StackNubbin{ value, nullptr, nubbin };
    return true;
}
bool pop(StackNubbin* nubbin)
{
    while (nubbin->nxt)
    {
        nubbin = nubbin->nxt;
    }

    nubbin->prev->nxt = nullptr;
    delete nubbin;

    return true;
}
void ArrPrint(StackNubbin* nubbin)
{
    while (nubbin)
    {
        std::cout << nubbin->value << " ";
        nubbin = nubbin->nxt;
    }
    std::cout << std::endl;
}
void stackDelte(StackNubbin** nubbin)
{
    StackNubbin* del{ *nubbin };
    StackNubbin* tmp{ *nubbin };
    *nubbin = nullptr;

    while (del)
    {
        tmp = tmp->nxt;
        delete del;
        del = tmp;
    }
}
/*Class Stack*/
const int STACK_SIZE{ 10 };
enum Command
{
    PUSH = 1,
    POP = 2,
    EXIT = 3
};
struct Stack
{
    int container[STACK_SIZE]{};
    int topIndex{ -1 };
};
void PrintInfo()
{
    std::cout << "<STACK>" << std::endl;
    std::cout << "[1] push" << std::endl;
    std::cout << "[2] POP" << std::endl;
    std::cout << "[3] exit" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
}
void PrintStack(const Stack& stack)
{
    std::cout << "--- stack ---" << std::endl;

    if (stack.topIndex < 0)
    {
        return;
    }

    for (int i = stack.topIndex; i >= 0; --i)
    {
        std::cout << stack.container[i] << std::endl;
    }

    std::cout << "---------------" << std::endl;
}
void Push(Stack& stack, int value)
{
    if (stack.topIndex >= STACK_SIZE - 1)
    {
        std::cout << "스택이 가득 찼습니다."
            << std::endl;
        return;
    }

    stack.container[++stack.topIndex] = value;
}
void Pop(Stack& stack)
{
    if (stack.topIndex < 0)
    {
        std::cout << "스택이 비었습니다."
            << std::endl;
        return;
    }
    std::cout << "pop : "
        << stack.container[stack.topIndex--]
        << std::endl;
}
bool ProcessUserInput(Stack& stack)
{
    int command{ -1 };

    std::cout << std::endl;
    std::cout << "> ";
    std::cin >> command;

    switch (command)
    {
        case PUSH:
        {
            int value{};
            std::cout << "    push value >> ";
            std::cin >> value;
            Push(stack, value);
            break;
        }
           
        case POP:
            Pop(stack);
            break;

        case EXIT:
            return false;
            break;

        default:
            std::cout << "잘못된 명령어입니다!"
                << std::endl;
            break;
    }
}

int main()
{
    /*Stack*/
    Stack myStack;
    // 화면 출력
    PrintInfo();
    // 무한루프
    while (true)
    {
        PrintStack(myStack);
        // 입력 받기, // 입력에 대한 기능(push, pop), // 종료
        if (ProcessUserInput(myStack) == false)
        {
            break;
        }
    }
    
}
