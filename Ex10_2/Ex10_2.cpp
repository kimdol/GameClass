#include <iostream>
#include "Dog.h"

int main()
{
    Dog happy;

    happy.SetBreed(Dog::BREED::HUSKY);
    happy.SetAge(15);

    happy.Sound();
    happy.Roll();
}
