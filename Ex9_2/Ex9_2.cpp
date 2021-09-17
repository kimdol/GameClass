#include <iostream>

// 대리생성자 활용
class MyClass
{
public:
    int mVal1;
    int mVal2;

    MyClass() : MyClass(1, 1)
    {

    }

    MyClass(int v1, int v2) : mVal1{ v1 }, mVal2{ v2 }
    {

    }
};

int main()
{
    
}
