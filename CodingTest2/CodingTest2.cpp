#include <iostream>
#include <map>

using fibo_history = std::map<int, int64_t>;

int64_t Fibonacci(int n, fibo_history& h)
{
    if (h.count(n) == 1)
    {
        return h[n];
    }

    // base case
    if (n <= 2)
    {
        return 1;
    }

    // recursive case
    h[n] = Fibonacci(n - 1, h) + Fibonacci(n - 2, h);
    return h[n];
}

int main()
{
    fibo_history h;

    std::cout << Fibonacci(50, h) << std::endl;
}
