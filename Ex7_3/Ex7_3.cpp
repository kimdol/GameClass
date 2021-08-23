#include <iostream>
#include <chrono> // 시간과 관련된 헤더

using Comparison = bool (*)(int, int);

bool Ascending(int x, int y)
{
    return x < y;
}
bool Descending(int x, int y)
{
    return x > y;
}
void Sort(int numbers[], int count, Comparison f)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (f(numbers[i], numbers[j]))
            {
                int  tmp = numbers[j];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }
}

int Sum(int scores[], int count)
{
    int total{};

    for (int i = 0; i < count; i++)
    {
        total += scores[i];
    }

    return total;
}

int main()
{
    /*sort 함수 시간 측정*/
    /*const int NumArray{ 10 };
    int scores[NumArray]{ 20, 10, 1, 3, 5, 3, 2, 1, 0 };

    auto startTime = std::chrono::system_clock::now();
    Sort(scores, NumArray, Ascending);
    auto endTime = std::chrono::system_clock::now();

    auto duration = endTime - startTime;
    std::cout << "Sort() : " << duration.count()
        << "ms" << std::endl;

    for (int i = 0; i < NumArray; i++)
    {
        std::cout << scores[i] << std::endl;
    }*/
    /*시간 복잡도*/
    int scores[5]{ 1, 2, 3, 4, 5 };

    std::cout << Sum(scores, 5) << std::endl;
}