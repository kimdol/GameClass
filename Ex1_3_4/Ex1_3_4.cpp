#include <iostream>

int main()
{/*
    int inputNum;

    std::cout << "숫자를 입력하시오. ";
    std::cin >> inputNum;
    
    int absoluteNum;

    absoluteNum = inputNum < 0 ? -inputNum : inputNum;

    std::cout << "절대값 : " << absoluteNum << std::endl;*/

    int inputNum;
    float money, krwMoney;
    char kind;
    std::string evenOdd;
    const float USDTOWON{ 1146.57f };   // 유니폼 초기화 할 때, 리터럴을 꼬옥! 써줘야한다.
    const float JPYTOWON{ 10.41f };

    std::cout << "홀수 짝수 구별 할 숫자를 입력하시오. ";
    std::cin >> inputNum;

    evenOdd = (inputNum % 2 == 0) ? "짝수" : "홀수";
    std::cout << "결과는 " << evenOdd << "입니다." << std::endl;


    std::cout << "달러(S) 혹은 엔(Y)를 입력하시오. ";
    std::cin >> money >> kind;

    if (kind == 'S')
    {
        krwMoney = money * USDTOWON;
        std::cout << "결과는 " << krwMoney << "원 입니다." << std::endl;
    }
    else if (kind == 'Y')
    {
        krwMoney = money * JPYTOWON;
        std::cout << "결과는 " << krwMoney << "원 입니다." << std::endl;
    }
    





}
