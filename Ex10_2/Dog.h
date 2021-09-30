#pragma once
#include "Animal.h"
class Dog : public Animal
{
public:
	enum BREED
	{
		BEAGLE, DOBERMAN, BERNARD, 
		CHIHUAHUA, HUSKY, RETRIEVER
	};

private:
	BREED mBreed;

public:
	void Roll();

public:
	BREED GetBreed() const;
	void SetBreed(BREED breed);

	void Sound();

public:
	Dog();
	Dog(BREED breed, int age, int weight);
	~Dog();
};

