#include "Warrior.h"

Warrior::Warrior()
{
	std::cout << "+[Warrior]"
		<< std::endl;
}

Warrior::~Warrior()
{
	std::cout <<
		"-[Warrior]"
		<< std::endl;
}

void Warrior::Attack() const
{
	std::cout <<
		"\t Àü»ç´Â °ËÀ» ÈÖµÑ·¶´Ù!"
		<< std::endl;
}

void Warrior::DoubleSwing() const
{
	std::cout <<
		"\t Àü»ç´Â °ËÀ» µÎ¹ø ÈÖµÑ·¶´Ù!"
		<< std::endl;
}
