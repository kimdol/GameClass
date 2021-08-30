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
/*selection 정렬 1(JuHo 수도코드로 의해서 탄생됨)*/
void SelectionSortJuHo(int input[], int cnt)
{
    int mark{ 0 }, indexmin{ 1 }, tmp{ 0 };
    while (indexmin < cnt)
    {
        for (int i = indexmin; i < cnt; i++)
        {
            if (input[mark] > input[i])
            {
                mark = i;
            }
        }
        tmp = input[indexmin - 1];
        input[indexmin - 1] = input[mark];
        input[mark] = tmp;
        indexmin += 1;
    }
}
/*selection 정렬*/
void SelectionSort(int input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;

        for (int j = i; j < size; j++)
        {
            if (input[j] < input[minIndex])
            {
                minIndex = j;
            }
        }
        Swap(input[i], input[minIndex]);
    }
}
/*bubble 정렬*/
void BubbleSort(int input[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        for (int i = 0; i < (size - step - 1); i++)
        {
            if (input[i] > input[i + 1])
            {
                Swap(input[i], input[i + 1]);
            }
        }
    }
}
/*insertion 정렬*/
void InsetionSort(int input[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j{ i };
        int target = { input[i] };

        while (--j >= 0 && target < input[j])
        {
            input[j + 1] = input[j];
            input[j] = target;
        }
    }
}
/*Merge  sort*/
void Merge(int input[], int start, int half, int end, int temp[])
{
    int i{ start };
    int j{ half + 1 };
    int k{};

    while (i <= half && j <= end)
    {
        // 한개씩 꺼내기
        // 작은거 왼쪽, 큰거  오른쪽
        if (input[i] < input[j])
        {
            temp[k++] = input[i++];
        }
        else
        {
            temp[k++] = input[j++];
        }
    }

    //왼쪽이 남았냐? 오른쪽이 나았냐?(남은 친구들 병합)
    while (i <= half)
    {
        temp[k++] = input[i++];
    }
    while (j <= end)
    {
        temp[k++] = input[j++];
    }
    // 상위 함수에게 알려주기 위해서 어쩔수없이 복사
    k = 0;
    for (int i = start; i <= end; i++)
    {
        input[i] = temp[k++];
    }
}
void MergeSort(int input[], int start, int end, int temp[])
{
    // base case
    if (start >= end)
    {
        return;
    }

    // recursive case
    int half{ (start + end) / 2 };
    MergeSort(input, start, half, temp);
    MergeSort(input, half + 1, end, temp);

    Merge(input, start, half, end, temp);
}
/*퀵 정렬*/
void QuickSort(int input[], int left, int right)
{
    int i { left }, j{ right };
    int pivot{ input[(left + right) / 2] };

    do
    {
        while (input[i] < pivot)
        {
            i++;
        }
        while (input[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            Swap(input[i], input[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j)
    {
        QuickSort(input, left, j);
    }

    if (i < right)
    {
        QuickSort(input, i, right);
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
    /*JuHo 정렬*/
    /*const int ARRAY_SIZE{5};
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
    //JuhoPrt(array, ARRAY_SIZE, one, ten);*/
    /*selection 정렬*/
    /*const int ARRAY_SIZE{5};
    int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };
    // SelectionSortJuHo(array, ARRAY_SIZE); juho의 수도코드
    SelectionSort(array, ARRAY_SIZE);
    PrintArray(array, ARRAY_SIZE);*/
    /*bubble 정렬*/
    /*const int ARRAY_SIZE{ 5 };
    int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };
    BubbleSort(array, ARRAY_SIZE);
    PrintArray(array, ARRAY_SIZE);*/
    /*insertion 정렬*/
    /*const int ARRAY_SIZE{ 5 };
    int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };
    InsetionSort(array, ARRAY_SIZE);
    PrintArray(array, ARRAY_SIZE);*/
    /*Merge  sort*/
    /*const int ARRAY_SIZE{ 5 };
    int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };
    int temp[ARRAY_SIZE]{};
    MergeSort(array, 0, ARRAY_SIZE - 1, temp);
    PrintArray(array, ARRAY_SIZE);*/
    /*퀵 정렬*/
    const int ARRAY_SIZE{ 5 };
    int array[ARRAY_SIZE]{ 8, 7, 2, 3, 1 };
    int temp[ARRAY_SIZE]{};
    QuickSort(array, 0, ARRAY_SIZE - 1);
    PrintArray(array, ARRAY_SIZE);
    

}
