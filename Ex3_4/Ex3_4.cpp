#include <iostream>

int main()
{

    /* {
        int i = 5;

        for (int i = 1; i < 10; i++)
        {
            std::cout << "\n";
        }
        std::cout << i << std::endl;
    }

    */
    /* 1-1번 문제 */
    /*{
        for (int n = 1; n <= 5; n++)
        {
            std::cout << n << std::endl;
        }
    }*/
    /* 1-2번 문제 */
    /*{
        for (int n = 1; n <= 9; n++)
        {
            if (n % 2 != 0)
            {
                std::cout << n << std::endl;
            }
        }
    }*/
    /* 1-3번 문제 */
    /*{
        for (int n = 1; n <= 2; n++)
        {
            for (int i = 1; i <= 3; i++)
            {
                std::cout << n << "   " << i << std::endl;
            }
        }
    }*/
    /* 1-4번 문제 */
    /*{
        for (char i = 'a'; i <= 'z'; i++)
        {
            std::cout << i << std::endl;
        }
    }*/
    /* 1-5번 문제 */
    /*{
        for (int n = 1; n <= 9; n++)
        {
            std::cout << "2 X " << n << " = " << 2 * n << std::endl;
        }
    }*/
    /* 1-6번 문제 */
    /*{
        int inputDan{ 0 };

        std::cout << "몇 단을 출력할까요? ";
        std::cin >> inputDan;

        for (int n = 1; n <= 9; n++)
        {
            std::cout << inputDan << " X " << n << " = " << inputDan * n << std::endl;
        }
    }*/
    /* 1-7번 문제 */
    /*{
        for (int i = 2; i <= 9; i++)
        {
            for (int k = 1; k <= 9; k++)
            {
                std::cout << i << " X " << k << " = " << i * k << std::endl;
            }
        }
    }*/
    /* 2-7번 문제 */
    /*{
        for (int n = 1; n <= 5; n++)
        {
            std::cout << n << "  " << 6 - n << std::endl;
        }
    }*/
    /* 2-8번 문제 */
    /*{
        int input{ 0 };
        for (;;)
        {
            std::cout << "입력 : ";
            std::cin >> input;
            if (input == 6)
            {
                std::cout << "어머낫 정답입니다~ \n";
                break;
            }
            else if (input < 6)
            {
                std::cout << "더 큰 수를 입력하시오 \n";
            }
            else if (input > 6)
            {
                std::cout << "더 작은 수를 입력하시오 \n";
            }
        }
    }*/
    /* 2-9번 문제 */
    /*{
        int width, height;
        std::cout << "너비 : ";
        std::cin >> width;
        std::cout << "높이 : ";
        std::cin >> height;
        for (int i = 1; i <= height; i++)
        {
            for (int k = 1; k <= width; k++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
        }

    }
    */
    /* 2-10번 문제 */
    /*{
        for (int i = 1; i <= 5; i++)
        {
            for (int k = 1; k <= i; k++)
            {
                std::cout << k;
            }
            std::cout << "\n";
        }

    }
    */
    /* 2-11번 문제 */
    {
        for (int i = 4; i >= 0; i--)
        {
            for (int j = 1; j <= i; j++)
            {
                std::cout << " ";
            }
            for (int k = 0; k < 5-i; k++)
            {
                std::cout << "* ";
            } 
            std::cout << "\n";
        }
    }

}
