#pragma once
#include <iostream>

class Character
{
protected:
	int mHP;

public:
	Character();
	virtual ~Character();

public:
	virtual void Attack() const = 0;
};

