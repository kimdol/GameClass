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
/*juhoSort(Ot(n))*/
/*배열 n개를 자리수에 맞게 차곡차곡 넣어라*/
void JuhoSort(int input[], int cnt, int one[10], int (*ten)[10])
{
    if (cnt == 0)
    {
        return;
    }

    // n번째에 있는 거를 자리수에 맞게 차곡차곡 넣어라
    if (0 <= input[cnt - 1] && 9 >= input[cnt - 1])
    {
        one[input[cnt - 1]] += 1;
    }
    else if (10 <= input[cnt - 1] && 99 >= input[cnt - 1])
    {
        ten[(input[cnt - 1] / 10)][(input[cnt - 1] % 10)] += 1;
    }
    // n - 1개를 자리 수에 맞게 차곡차곡 넣어라
    JuhoSort(input, cnt - 1, one, ten);
}
void JuhoPrt(int input[], int cnt, int one[10], int(*ten)[10])
{
    int arrcnt{ 0 };
    for (int i = 0; i < 10; i++)
    {
        std::cout << one[i] << std::endl;
        if (one[i] > 0)
         {
            input[arrcnt++] = i--;
         }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (ten[i][j] > 0)
            {
                input[arrcnt++] = i * 10 + j;
                j--;
            }
        }
    }
    PrintArray(input, cnt);
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
    const int ARRAY_SIZE{ 5 };
    int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };
    int one[10]{}, ten[10][10]{};
    JuhoSort(array, 5, one, ten);
    for (int i = 0; i < 10; i++)
    {
      std::cout << "[" << i << "] : " << one[i] << "\t";
    }
    std::cout << "\n\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            std::cout << "[" << i << "]" << "[" << j << "] : " << ten[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    //JuhoPrt(array, ARRAY_SIZE, one, ten);
}
