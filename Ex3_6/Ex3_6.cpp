#include <iostream>
//#include <sstream>
//#include <iomanip>
// #include <string.h>

int main()
{
    /*구식 문자열 처리 함수(인터넷 코드에서 종종 발견됨)*/
    //{
    //    char output[128]{};
    //    int a{};
    //    char b[]{ "Lee" };
    //    float c{ 1.1f };
    //    // 주로 사용함(해커들이 주로 오버플로우내서 _s가 발명되고 문자열을 받아들이는 함수임)
    //    sprintf_s(output, 128, "%d 번의 학생 %s가 평균 %f입니다", a, b, c);
    //    std::cout << output;
    //}
    /*문자열 연습*/
    /*{
        std::ostringstream oss;

        char output[128]{};
        int a{};
        char b[]{ "Lee" };
        float c{ 1.1f };
        oss << a << "번 학생"
            << b << "라는 학생"
            << "성적은 " << c;

        std::cout << oss.str() << std::endl;

    }*/
    /*문자열다루기 문제 1-1*/
    /*{
        char input[100]{};
        char tmp{ '\0' };
        int pos{ 0 }, posMax{ 0 };

        std::cout << "문자열을 입력하시오. ";
        std::cin >> input;

        for (int i = 0; i < 100; i++)
        {
            if (input[i] == '\0')
            {
                break;
            }
            pos++;
        }

        posMax = pos-1;
        for (int i = 0; i < (pos / 2); i++)
        {
            tmp = input[i];
            input[i] = input[posMax];
            input[posMax] = tmp;
            posMax -= 1;
        }

        std::cout << input << std::endl;
        
    }*/
    /*문자열다루기 문제 1-2*/
    /*{
        char input1[50]{}, input2[50]{};
        char tmp{ '\0' };
        int pos{ 0 }, posMax{ 0 };

        std::cout << "문자열1을 입력하시오. ";
        std::cin >> input1;
        std::cout << "문자열2을 입력하시오. ";
        std::cin >> input2;

        for (int i = 0; i < 100; i++)
        {
            if (input1[i] == '\0')
            {
                break;
            }
            pos++;
        }

        int k = 0;
        for (int i = pos; i < 100; i++)
        {
            if (input2[k] == '\0')
            {
                break;
            }
            input1[i] = input2[k];
            k++;
        }

        std::cout << input1;
    }*/
    /*문자열다루기 문제 1-3*/
    /*{
        char input[50]{};
        char tmp{ '\0' };
        int pos{ 0 }, posMax{ 0 };

        std::cout << "문자열을 입력하시오. ";
        std::cin >> input;

        for (int i = 0; i < 100; i++)
        {
            if (input[i] == '\0')
            {
                break;
            }
            input[i] = input[i] - 32;
        }

        std::cout << input;
    }*/
   
}
