#include <iostream>

int Sum(int *input, int size)
{
    int sum{};

    for (int i = 0; i < size; i++)
    {
        sum += input[i];
    }

    return sum;
}
int Sum2(int (*input)[3], int a, int b)
{
    int sum{};

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            sum += input[i][j];
        }
    }

    return sum;
}

int main()
{
    /*배열과 함수 기초 1*/
    /*int numbers[2][3]{
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << Sum(&numbers[0][0], 6) << std::endl;
    std::cout << Sum2(numbers, 2, 3) << std::endl;*/
    /*문자열 한글 처리*/
    wchar_t myStr[] = { L" 는 정수입니다." }; // L이 꼭 있어야함

    std::locale myLoc("kor");
    std::wcout.imbue(myLoc);

    std::wcout << myStr << std::endl;
    std::wcout << myStr + 5 << std::endl;

}
