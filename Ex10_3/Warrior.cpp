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
		"\t ����� ���� �ֵѷ���!"
		<< std::endl;
}

void Warrior::DoubleSwing() const
{
	std::cout <<
		"\t ����� ���� �ι� �ֵѷ���!"
		<< std::endl;
}
