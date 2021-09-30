#include "Dog.h"

void Dog::Roll()
{
	std::cout << "Rolling ..."
		<< std::endl;
}

Dog::BREED Dog::GetBreed() const
{
	return mBreed;
}

void Dog::SetBreed(BREED breed)
{
	mBreed = breed;
}

void Dog::Sound()
{
	std::cout << "Woof Woof ..." <<
		std::endl;
}

Dog::Dog() : mBreed{ HUSKY }
{
}

Dog::Dog(BREED breed, int age, int weight) : 
	Animal(age, weight),
	mBreed{ breed }
{

}

Dog::~Dog()
{
}
