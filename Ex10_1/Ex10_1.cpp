#include <iostream>
#include "String.h"

/*일반 생성자, 복사 생성자*/
class MyClass
{
public:
    MyClass(int value)
    {
        std::cout << "일반 생성자" << std::endl;
    }

    // 복사 생성자
    MyClass(const MyClass& from)
    {
        std::cout << "복사 생성자" << std::endl;
    }
};
/*얇은 복사, 깊은 복사*/
class Dog
{

};
class DogHouse
{
    Dog* owner;

public:
    DogHouse()
    {
        owner = new Dog();
    }

    DogHouse(const DogHouse& house)
    {
        // swallow(얇은 복사)
        owner = house.owner;

        // deep(깊은 복사)
        owner = new Dog();
    }

    ~DogHouse()
    {
        delete owner;
    }
};
/**/
int main()
{
    /*일반, 복사 생성자*/
    //MyClass c1{ MyClass{1} };
    /*string 클래스 제작 결과*/
    String str1{ "hello" }, str2{ "Hi" }, str3{ "Good" };

    // str2 = str1 + str3;
    // str2 += str3;
    // str1[2] = 'a';
     char c = str1[1];

    std::cout << str1
        << str2
        << str3
        << c << std::endl;



}
