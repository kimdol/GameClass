#include <iostream>

int main()
{
	//int myInt{ 1000 };
	//unsigned char myChar = myInt;

	//std::cout << myInt << "\t" << (int)myChar << std::endl; // 위에서 이미 잘림

	struct OneByte
	{
		char myChar;
	};

	std::cout << sizeof(OneByte) << std::endl;

#pragma pack(push, 1)	// 1바이트로 바꾸기
	struct FiveByte
	{
		char myChar;
		int myInt;
	};
#pragma pack(pop)

	std::cout << sizeof(FiveByte) << std::endl;
}
