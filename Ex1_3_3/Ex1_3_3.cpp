#include <iostream>

int main()
{
    int x, y, tmp;

    std::cout << "x와 y를 입력하시오. (space바 이용)" << std::endl;
    std::cin >> x >> y;

    std::cout << "몫 : " << x / y <<
        "\n나머지 : " << x % y << std::endl;



    std::cout << "x와 y를 또 입력하시오. (space바 이용)" << std::endl;
    std::cin >> x >> y;

    x = (x << 8) | y;

    y = (x >> 8) & 0xFF;
    x = x & 0xFF;
    
    std::cout << "x : " << x <<
        "\ny : " << y << std::endl;




    std::cout << "x와 y를 또또 입력하시오. (space바 이용)" << std::endl;
    std::cin >> x >> y;

    tmp = x;
    x = y;
    y = tmp;

    std::cout << "x : " << x <<
        "\ny : " << y << std::endl;


}
