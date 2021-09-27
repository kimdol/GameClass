#include <iostream>

/*일반 생성자, 복사 생성자*/
class MyClass
{
    int mValue;
public:
    MyClass(int value) : mValue{ value }
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
    MyClass c1{ MyClass{1} };
    /*얇은 복사, 깊은 복사*/




}
