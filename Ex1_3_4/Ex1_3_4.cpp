#include <iostream>

int main()
{
    int inputNum;

    std::cout << "숫자를 입력하시오. ";
    std::cin >> inputNum;
    
    int absoluteNum;

    absoluteNum = inputNum < 0 ? -inputNum : inputNum;

    std::cout << "절대값 : " << absoluteNum << std::endl;



}
