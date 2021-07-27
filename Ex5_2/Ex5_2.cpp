#include <iostream>
int Sum(int num[5])
{
    int total{ 0 };

    for (int i = 0; i < 5; i++)
    {
        total += num[i];
    }
    return total;
}


int main()
{
    /* 함수 기본 */
    /*{
        std::cout << pow(2, 2) << std::endl;

    }*/
    /*함수에 매개변수로 배열을 사용해 봅시다*/
    {
        int num[]{ 1, 2, 3, 4, 5 };

        std::cout << Sum(num) << std::endl;
    }
    return 0;
}
