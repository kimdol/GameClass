#include <iostream>

int main()
{
    /*1 동적배열의 크기를 다음과 같이 3개로 줄여 봅시다*/
    /*int* pNumbers{ new int[5] {4, 8, 5, 3, 1} };

    if (pNumbers)
    {
        delete[] pNumbers;
        pNumbers = nullptr;
    }

    pNumbers = new int[3];
    pNumbers[0] = 4;
    pNumbers[1] = 8;
    pNumbers[2] = 5;

    if (pNumbers)
    {
        for (int i = 0; i < 3; i++)
        {
            std::cout << pNumbers[i] << " ";
        }
        delete[] pNumbers;
        pNumbers = nullptr;
    }*/
    
    /*2 이름이 가장 큰 놈을 출력하는 프로그램을 만들라*/
    size_t studentNum{ 0 };
    std::string maxName{};
    std::cout << "학생 수를 입력하시오 ";
    std::cin >> studentNum;

    std::string* pStd{ new std::string[studentNum]};

    if (pStd)
    {
        for (int i = 0; i < studentNum; i++)
        {
            std::cout << "친구 #" << i+1 << " 학생 이름을 입력하시오 ";
            std::cin >> pStd[i];

            if (maxName.size() < pStd[i].size())
            {
                maxName = pStd[i];
            }
        }

        std::cout << "이름이 가장 긴 친구는 " << maxName << "입니다."
            << std::endl;

        delete[] pStd;
        pStd = nullptr;
    }
}
