#include <iostream>
#include <map>

using fibo_history = std::map<int, int64_t>;

int64_t Fibonacci(int n, fibo_history& h)
{
    // 정답이 존재하면 해답을 돌려주라
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

int FindPath(int m, int n)
{
    // int m과 n이 각각 키에 포함이 된 경우 그냥 해답을 돌려주면 된다.
    
    // base case
    if (m == 0 || n == 0)
    {
        return 0;
    }

    if (m == 1 && n == 1)
    {
        return 1;
    }

    // recursive case
    // key(m, n)에 대한 답을 넣는다.
    return FindPath(m - 1, n) + FindPath(m, n - 1);
}

int main()
{
    fibo_history h;
    std::cout << Fibonacci(50, h) << std::endl;

    std::cout << FindPath(20, 30) << std::endl;

}
