#include <iostream>

int Sum(int arr[5], int start, int end)
{
    if (start == end)
    {
        return arr[end];
    }
    return arr[end] + Sum(arr, start, end - 1);
}
int Factor(int n)
{
    if (n <= 0)
    {
        return 1;
    }

    return n * Factor(n - 1);
    
}
int Fibonacci(int n)
{
    if (n < 2)
    {
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
    /*재귀함수 연습*/
    /*{
        int arr[]{ 1, 2, 3, 4, 5 };

        std::cout << Sum(arr, 0, 4) << std::endl;
    }*/
    /*재귀호출 기초 문제 1-1*/
    /*{
        int input{}, res{ 1 };

        std::cout << "구할 팩토리얼 숫자를 입력하십시오. ";
        std::cin >> input;
        std::cout << Factor(input) << std::endl;

        for (int i = input; i > 0; i--)
        {
            res *= i;
        }
        std::cout << res << std::endl;
    }*/
    /*재귀호출 기초 문제 1-2*/
    {
        int input{ 0 }, cnt{ 0 };

        std::cout << "구할 피보나치의 자리를 입력하십시오. ";
        std::cin >> input;
        std::cout << Fibonacci(input) << std::endl;

        std::cout << "끝낼 피보나치의 숫자를 입력하십시오. ";
        std::cin >> input;
        while (Fibonacci(cnt++) <= input)
        {
            std::cout << Fibonacci(cnt - 1);
        }
        std::cout << std::endl;


    }
}
