#include <iostream>
#include <map>
#include <string>
#include <vector>

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

using path_history = std::map<std::string, int>;
int FindPath(int m, int n, path_history& h)
{
    // int m과 n이 각각 키에 포함이 된 경우 그냥 해답을 돌려주면 된다.
    std::string key{ std::to_string(m) + "," + std::to_string(n) };
    if (h.count(key) == 1)
    {
        return h[key];
    }

    std::string rkey = std::to_string(n) + "," + std::to_string(m);
    if (h.count(rkey) == 1)
    {
        return h[rkey];
    }

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
    h[key] = FindPath(m - 1, n, h) + FindPath(m, n - 1, h);
    return h[key];
}

// 정수의 배열 numbers에서 숫자를 조합하여 sum을 만들 수 있는 지 확인
// {2, 3, 5} 8을 만들 수 있나? o
// {5, 3, 7} 13을 만들 수 있나? o
// { 1 } 24를 만들 수 있나? o
using int_vector = std::vector<int>;
using accum_history = std::map<int, std::shared_ptr<int_vector>>;

std::shared_ptr<int_vector> CanAccumulate
(int sum, const int_vector& numbers, accum_history& h)
{
    if (h.count(sum) == 1)
    {
        return h[sum];
    }


    // base case
    if (sum == 0)
    {
        return std::make_shared<int_vector>();
    }
    if (sum < 0)
    {
        return nullptr;
    }

    // recursive case
    int remain{};

    std::shared_ptr<int_vector> shortest = nullptr;

    for (auto e : numbers)
    {
        remain = sum - e;
        auto ret = CanAccumulate(remain, numbers, h);
        if ( ret != nullptr )
        {
            std::shared_ptr<int_vector> v = std::make_shared<int_vector>();
            v->resize(ret->size());
            std::copy(ret->begin(), ret->end(), v->begin());

            v->push_back(e);

            if (shortest == nullptr || v->size() < shortest->size())
            {
                shortest = v;
            }
        }
    }

    h[sum] = shortest;
    return h[sum];
}

void Print(int_vector* v)
{
    if (v == nullptr)
    {
        std::cout << "{}" << std::endl;
        return;
    }

    std::cout << "{ ";
    for (auto e : *v)
    {
        std::cout << e << ",";
    }
    std::cout << " }" << std::endl;
}

int main()
{
    fibo_history h;
    std::cout << Fibonacci(50, h) << std::endl;

    path_history h1;
    std::cout << FindPath(20, 20, h1) << std::endl;

    accum_history h11;
    Print(CanAccumulate(8, { 2, 3, 5 }, h11).get());

}
