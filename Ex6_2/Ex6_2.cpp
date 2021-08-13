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
int Sum3(int input[][3], int a, int b)
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
int GetLength(char str[])
{
    int cnt{ 0 };
    while (1)
    {
        if (*(str + cnt++) == '\0')
        {
            return cnt-1;
        }
    }
}

int main()
{
    /*배열과 함수 기초 1*/
    /*int numbers[2][3]{
        {1, 2, 3},
        {4, 5, 6}
    };

    std::cout << Sum(&numbers[0][0], 6) << std::endl;
    std::cout << Sum2(numbers, 2, 3) << std::endl;
    std::cout << Sum3(numbers, 2, 3) << std::endl;*/
    /*문자열 한글 처리*/
    // L이 꼭 있어야함
    /*wchar_t myStr[] = { L" 는 정수입니다." };

    std::locale myLoc("kor");
    std::wcout.imbue(myLoc);

    std::wcout << myStr << std::endl;
    std::wcout << myStr + 5 << std::endl;*/
    /* 문자열의 길이 */
    /*char input[1000];
    std::cout << "문자열을 입력하라 ";
    std::cin >> input;

    std::cout << GetLength(input) << std::endl;*/
    /* 문자열 비교 */
    // ctrcmp 는 길이나 사이즈를 비교하는것이 아닌
    // 아스키코드를 비교한다.
    /* 메모리 동적 할당(차이점)*/
    //  현업에서도 아직까지 살아있을 수 도있음
    /*int array[100];

    int* buffer1, * buffer2;

    buffer1 = (int*)calloc(100, sizeof(int));
    // 게임 프로그래머 선호 - 속도(초기화를 안하기 때문)
    buffer2 = (int*)malloc(100 * sizeof(int));

    if (buffer1 == nullptr || buffer2 == nullptr)
    {
        return 0;
    }

    std::cout << buffer1[0] << ",  " << buffer2[0] <<
        std::endl;

    free(buffer1);
    free(buffer2);

    return 0;*/ 
    /*C++ 스타일  동적  할당*/
    /*int* p1{new int {4}};
        // int *p1;
        // p1 = new int;
        // *p1 = 4;
        // 와 같다.

    delete p1;*/


}
