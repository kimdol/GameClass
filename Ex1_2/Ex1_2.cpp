#include <iostream>

int main()
{
    // 선언 (declaration)
    int myInteger;  // 이름 + 형 이여야한다.

    // 대입 (assignment)
    myInteger = 1;

    int x;

    x = myInteger;  // l-value, r-value

    char myChar;
    myChar = 'A';

    std::cout << myChar;

}