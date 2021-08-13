#include <iostream>

struct Status
{
    int HP;
    float attack;
};

void MyFunction1();
void MyFunction2();

char gString[]{ "MEMORY LAYOUT" };
int gInteger;

int main()
{
    /*구조체 동적 할당*/
    /*Status* pStatus{ new Status };

    delete pStatus;*/
    /* 배열 구조체 할당*/
    /*int* pArray = new int[5];

    delete[] pArray;*/
    /*dangling pointer(안전하게 방지)*/
    /*int* p{ new int };

    delete p;
    p = nullptr;

    *p = 3;*/
    /*RAM 영역*/
    /*std::cout << (void*)gString << std::endl;
    std::cout << &gInteger << std::endl;

    int* p = new int;

    std::cout << "main::p - " << p << std::endl;

    MyFunction1();

    delete p;*/
    /*사용자에게 배열의 크기를 입력받아서*/
    /*해당 크기의 배열을 생성한 후 모든 원소를*/
    /*0로 초기화하는 프로그램을 작성하라*/
    /*완벽한 동적할당*/
    /*int arrSize{ 0 };
    std::cout << "배열의 크기를 입력하시오 ";
    std::cin >> arrSize;
    int* pArr{ new int[arrSize] };

    if (pArr)
    {
        for (int i = 0; i < arrSize; i++)
        {
            pArr[i] = 0;
        }
        delete[] pArr;
        pArr = nullptr;
    }*/
    /*윗 문제 추가적인 동적할당 방법1*/
    /*int arrSize{ 0 };
    std::cout << "배열의 크기를 입력하시오 ";
    std::cin >> arrSize;
    int* pArr{ (int *)calloc(arrSize, sizeof(int)) };

    if (pArr)
    {
        free(pArr);
        pArr = nullptr;
    }*/
    /*윗 문제 추가적인 더더 완벽한 동적할당 방법2*/
    /*size_t arrSize{ 0 };
    std::cout << "배열의 크기를 입력하시오 ";
    std::cin >> arrSize;

    int* pArr{ new int[arrSize] {} };

    if (pArr)
    {
        delete[] pArr;
        pArr = nullptr;
    }*/
}

void MyFunction1()
{
    int local;

    std::cout << "MyFunction1:local - " << &local << std::endl;

    MyFunction2();
}
void MyFunction2()
{
    int local;

    std::cout << "MyFunction2:local - " << &local << std::endl;
}