#include <iostream>

void Swap(int* a, int* b)
{
    int tmp{ *a };
    *a = *b;
    *b = tmp;
}

int main()
{
    /*포인터 기초*/
    /*int a{ 0 }, b{ 0 };
    int* p;

    p = &a;
    p = &b;*/
    /*포인터 기초2*/
    /*int a{ 1 };
    int* p{ &a };

    std::cout << p << std::endl;
    std::cout << p + 1 << std::endl;
    std::cout << p + 2 << std::endl;*/
    /*포인터 기초3*/
    /*int a{ 1025 };
    int* pa{ &a };

    char* p0{ (char*)pa };

    for (int i = 0; i < 4; i++)
    {
        std::cout << (void*)p0 << " : " << (int)*p0 << std::endl;

        p0++;
    }*/
    /*포인터 기초4*/
    
    int x{ 10 }, y{ 20 };
    
    Swap(&x, &y);

    std::cout << x << ", " << y << std::endl;

}
