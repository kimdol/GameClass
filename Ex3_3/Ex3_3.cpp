#include <iostream>

int main()
{
    float money, krMoney{ 0.0f };
    char mark;
    const float STOKRW{ 1145.18f }, YTOKRW{ 10.38f }, ETOKRW{ 1358.55f }, PTOKRW{ 1590.33f };

    std::cout << "10S 형태로 입력하십시오.(S:달라, Y:엔, E:유로, P:파운드) ";
    std::cin >> money >> mark;

    switch(mark)
    {
        case 'S':
            krMoney = STOKRW * money;
            break;
        case 'Y':
            krMoney = YTOKRW * money;
            break;
        case 'E':
            krMoney = ETOKRW * money;
            break;
        case 'P':
            krMoney = PTOKRW * money;
            break;
        default:
            std::cout << "잘못 입력하셨습니다" << std::endl;
    }

    std::cout << "우리나라 돈으로 계산하면 " << krMoney << "원 입니다." << std::endl;




}
