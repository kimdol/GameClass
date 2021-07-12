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
    float usdMoney, krwMoney;
    std::string evenOdd;
    const float EXCHANGERATE{ 1146.57f };   // 유니폼 초기화 할 때, 리터럴을 꼬옥! 써줘야한다.

    std::cout << "홀수 짝수 구별 할 숫자를 입력하시오. ";
    std::cin >> inputNum;

    evenOdd = (inputNum % 2 == 0) ? "짝수" : "홀수";
    std::cout << "결과는 " << evenOdd << "입니다." << std::endl;


    std::cout << "KRW로 바꿀 USD를 입력하시오. ";
    std::cin >> usdMoney;

    krwMoney = usdMoney * EXCHANGERATE;
    std::cout << "결과는 " << krwMoney << "원 입니다." << std::endl;





}
