#include "Character.h"

Character::Character() : mHP{ 0 }
{
	std::cout << "+[Character]"
		<< std::endl;
}

Character::~Character()
{
	std::cout << "-[Character]"
		<< std::endl;
}

void Character::Attack() const
{
	std::cout <<
		"\t Basic Attack!"
		<< std::endl;
}
