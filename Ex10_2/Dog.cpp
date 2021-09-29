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

Dog::Dog() : mBreed{ HUSKY }
{
}

Dog::~Dog()
{
}
