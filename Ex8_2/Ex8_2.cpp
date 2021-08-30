#include <iostream>
/*JuHo_Stack1*/
bool push(int array[], int size, int value, int *nxt)
{
    if ((*nxt) + 1 >= size)
    {
        std::cout << "stack is full" << std::endl;
        return false;
    }
    array[(*nxt)++] = value;
    return true;
}
bool pop(int array[],  int *prev)
{
    if ((*prev) - 1 < 0)
    {
        std::cout << "stack is empty" << std::endl;
        return false;
    }
    array[--(*prev)] = 0;
    (*prev)++; // 커서의 균형을 맞추기 위함
    return true;
}
void ArrPrint(int array[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        std::cout << array[i] << std::endl;
    }
}
/*JuHo_Stack2*/
struct StackNubbin
{
    int value;
    StackNubbin* nxt;
    StackNubbin* prev;
};
bool push(StackNubbin *nubbin, int value)
{
    while (nubbin->nxt)
    {
        nubbin = nubbin->nxt;
    }
    nubbin->nxt = new StackNubbin{ value, nullptr, nubbin };
    return true;
}
bool pop(StackNubbin *nubbin)
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
void stackDelte(StackNubbin* nubbin)
{
    while (nubbin->nxt)
    {
        nubbin = nubbin->nxt;
    }
    while (nubbin->prev)
    {

    }
}
int main()
{
    /*push*/
    //const int ARR_SIZE{ 10 };
    //int array[ARR_SIZE]{};
    //int order{ 0 };
    //push(array, ARR_SIZE, 5, &order);
    /*push*/
    StackNubbin start{1, nullptr, nullptr};
    push(&start, 5);
    push(&start, 6);
    push(&start, 7);
    /*pop*/
    //pop(array, &order);
    /*pop*/
    pop(&start);
    /*print*/
    //ArrPrint(array, ARR_SIZE);
    push(&start, 5);
    ArrPrint(&start);
}
