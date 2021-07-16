#include <iostream>

int main()
{
	//int myInt{ 1000 };
	//unsigned char myChar = myInt;

	//std::cout << myInt << "\t" << (int)myChar << std::endl; // 위에서 이미 잘림

//	{
//		struct OneByte
//		{
//			char myChar;
//		};
//
//		std::cout << sizeof(OneByte) << std::endl;
//
//#pragma pack(push, 1)	// 1바이트로 바꾸기
//		struct FiveByte
//		{
//			char myChar;
//			int myInt;
//		};
//#pragma pack(pop)
//
//		std::cout << sizeof(FiveByte) << std::endl;
//	}
	/*{
		union MyUnion
		{
			int a;
			unsigned int b;
			long long c;
		};

		MyUnion u;

		u.c = 10;

		std::cout << u.a << std::endl;
		std::cout << u.b << std::endl;
		std::cout << u.c << std::endl;

	}*/
	/* 배열의 기초 문제1*/
	/*{
		const int CLASSNUM{ 5 };
		int input[CLASSNUM]{ 0, 0, 0, 0, 0 }, result{ 0 };
		for (int i = 0; i < 5; i++)
		{
			std::cout << "학생 " << i+1 << "번 : ";
			std::cin >> input[i];
			result += input[i];
		}

		std::cout << "총 합 : " << result <<
			"\n" << "평균 : " << result / CLASSNUM << std::endl;
	}*/
	/**/
	{

	}
}
