#include <iostream>

int main()
{
	//int number1{ 3 }, number2{ 2 };

	//std::cout << number1 + number2 << std::endl;
	//std::cout << number1 % number2 << std::endl;

	int number = 0b0010;

	//number = number >> 1; // 0001로 밀림
	number = number << 2;

	std::cout << number << std::endl;

}

