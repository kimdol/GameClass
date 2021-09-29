#pragma once
#include <iostream>

class Animal
{
protected:
	int		mAge;
	int		mWeight;

public:
	void	Sound();

public:
	int		GetAge() const;
	void	SetAge(int age);
	int		GetWeight() const;
	void	SetWeight(int weight);

public:
	Animal();
	~Animal();
};