#include <iostream>

int main()
{
	//int number1{ 3 }, number2{ 2 };

	//std::cout << number1 + number2 << std::endl;
	//std::cout << number1 % number2 << std::endl;

	int number = 0b0001;

	// number = number >> 1; // 0001로 밀림
	
	number = number << 1;
	std::cout << number << std::endl;

	number = number << 1;
	std::cout << number << std::endl;

	number = number << 1;
	std::cout << number << std::endl;

	// 여기서 알수있는 부분은 곱하기 2가 된다는 것이다.
	// 이러한 비트연산자는 RGB에 씀
	// RGB + 알파(투명도) = 4byte


}
