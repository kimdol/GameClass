#include <iostream>
#include "MyArray.h"

// 대리생성자 활용
class MyClass
{
private:
    int mVal1;
    int mVal2;

public:
    MyClass() : MyClass(1, 1)
    {

    }

    MyClass(int v1, int v2) : mVal1{ v1 }, mVal2{ v2 }
    {

    }

    MyClass operator+(MyClass);
    MyClass& operator ++();
    MyClass operator ++(int); // 매개변수를 아무거나 입력하면 됨
    MyClass operator <<(int);
    friend std::ostream& operator << (std::ostream& os, MyClass a);

};

// 전역함수 연산자
int operator +(MyClass, MyClass)
{
    return 1;
}
// 멤버함수 연산자 오버로딩(+)
MyClass MyClass::operator +(MyClass)
{
    return MyClass();
}
// 멤버함수 연산자 오버로딩(전위 ++)
MyClass& MyClass::operator ++()
{
    mVal1++;
    mVal2++;

    return (*this); // 굳이 객체를 안만들어도 됨
}
// 멤버함수 연산자 오버로딩(후위 ++)
MyClass MyClass::operator ++(int asdf)
{
    MyClass temp(mVal1, mVal2);
    
    ++(*this);

    return temp; // 후위의 특성을 고려함
}
/*멤버함수 연산자(<<)*/
MyClass MyClass::operator<<(int aa)
{
    return MyClass();
}
std::ostream& operator << (std::ostream& os, MyClass a)
{
    os << "(" << a.mVal1 << ")" << "\n";
    return os;
}

int main()
{
    MyClass a{ 1, 1 };
    MyClass b;
    b = ++a;

    MyArray arr1{ 3 };
    MyArray arr2{ 1 };
    
    
    arr1 - arr2;
    --arr1;

    std::cout << arr1[2] << std::endl;

    std::cout << (int)arr2 << std::endl;


}
