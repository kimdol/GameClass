#include <iostream>

class Dog
{
private:
    int mAge;

public:
    int mWeight;

    void Function()
    {
        mAge = 1;
    }

};

int main()
{
    Dog happy;

    std::cout << sizeof(Dog) << std::endl;

}
