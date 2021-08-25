#include <iostream>

void PrintArray(int input[], int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << input[i] << std::endl;
    }
}
void Swap(int& x, int& y)
{
    int temp{ x };
    x = y;
    y = temp;
}
void SequentialSort(int input[], int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (input[i] < input[j])
            {
                Swap(input[i], input[j]);
            }
        }
    }
}
int main()
{
    /*기본 정렬*/
    /*const int ARRAY_SIZE{5};
    int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };
    // 정렬
    SequentialSort(array, 5); // 어찌되었든 빅오는 n^2
    PrintArray(array, ARRAY_SIZE);*/
    /*새로운 정렬*/
}
