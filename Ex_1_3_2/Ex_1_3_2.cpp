#include <iostream>

int main()
{
	/*
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
	*/

	// 여기서 알수있는 부분은 곱하기 2가 된다는 것이다.
	// 이러한 비트연산자는 RGB에 씀
	// RGB + 알파(투명도) = 4byte

	int alpha { 255 };
	int red { 128 };
	int green{ 64 };
	int blue{ 32 };

	unsigned int color{ 0 };

	// color <= argb
	color = color | (alpha << 24);

	color = color | (red << 16);

	color = color | (green << 8);

	color = color | blue;

	std::cout << color << std::endl;

	// color => argb
	blue = color & 0xFF;
	green = (color >> 8) & 0xFF;
	red = (color >> 16) & 0xFF;
	alpha = (color >> 24) & 0xFF;

	std::cout << alpha << std::endl;
	std::cout << red << std::endl;
	std::cout << green << std::endl;
	std::cout << blue << std::endl;


}
