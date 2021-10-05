#include <iostream>
class MyFunctions
{
public:
    static int NormalFunction(int x)
    {
        return x;
    }

    static int SquareFunction(int x)
    {
        return x * x;
    }
};
using FuncPtr = int (*)(int);
using FunctionPtr = int (MyFunctions::*)(int);

int Sigma(FuncPtr f, int m, int n)
{
    int sum{};
    for (int k = m; k <= n; k++)
    {
        sum += (*f)(k);
        // sum += (instance.*f)(k);
    }

    return sum;
}

int main()
{
    std::cout <<
        Sigma(&MyFunctions::NormalFunction, 1, 10)
        << std::endl;
    std::cout <<
        Sigma(&MyFunctions::SquareFunction, 1, 10)
        << std::endl;
}
