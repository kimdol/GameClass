#include "Animal.h"

void Animal::Sound()
{
	std::cout << "Make Some Noise..."
		<< std::endl;
}

int Animal::GetAge() const
{
	return mAge;
}

void Animal::SetAge(int age)
{
	mAge = age;
}

int Animal::GetWeight() const
{
	return mWeight;
}

void Animal::SetWeight(int weight)
{
	mWeight = weight;
}

Animal::Animal() : mAge{ 0 }, mWeight{ 0 }
{
}

Animal::~Animal()
{
}
