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
	/* 배열의 기초 문제*/
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
	/*배열 연습문제 1-1*/
	/*{
		const int CLASSNUM{ 5 };
		int reportCard[CLASSNUM]{};
		int bigScore{ 0 }, smallScore{ 100 };

		std::cout << "학생 점수를 입력하라 \n";
		std::cout << "입력 : ";

		for (int i = 0; i < CLASSNUM; i++)
		{
			std::cin >> reportCard[i];
			if (reportCard[i] > bigScore)
			{
				bigScore = reportCard[i];
			}
			if (reportCard[i] < smallScore)
			{
				smallScore = reportCard[i];
			}
		}

		std::cout << "최저 점수 : " << smallScore << "\n"
			<< "최고 점수 : " << bigScore << std::endl;

	}*/
	/*배열 연습문제 1-2*/
	/*{
		const int CLASSNUM{ 5 };
		int reportCard[CLASSNUM]{}, ranking[CLASSNUM]{}, scoreTmp[CLASSNUM]{};
		int rank{ 1 }, top[2]{ 0, 0 };

		std::cout << "학생 점수를 입력하라 \n";
		std::cout << "입력 : ";

		for (int i = 0; i < CLASSNUM; i++)
		{
			std::cin >> reportCard[i];
			scoreTmp[i] = reportCard[i];
		}

		for (int i = 0; i < CLASSNUM; i++)
		{
			for (int k = 0; k < CLASSNUM; k++)
			{
				if (top[0] < scoreTmp[k])
				{
					top[0] = scoreTmp[k];
					top[1] = k;
				}
			}
			top[0] = 0;
			scoreTmp[top[1]] = 0;
			ranking[top[1]] = rank++;
		}

		for (int i = 0; i < CLASSNUM; i++)
		{
			std::cout << reportCard[i] << "\t";
		}
		std::cout << "\n";
		for (int i = 0; i < CLASSNUM; i++)
		{
			std::cout << ranking[i] << "\t";
		}


	}*/
	/*배열 연습문제 1-3*/
	{
		const int CLASSNUM{ 5 };
		int reportCard[CLASSNUM]{};
		int scoreTmp{ 0 };
		
		std::cout << "학생 점수를 입력하라 \n";
		std::cout << "입력 : ";

		for (int i = 0; i < CLASSNUM; i++)
		{
			std::cin >> reportCard[i];
		}

		for (int i = (CLASSNUM - 1); i > 0; i--)
		{
			for (int k = 0; k < i; k++)
			{
				if (reportCard[k] > reportCard[k+1])
				{
					scoreTmp = reportCard[k + 1];
					reportCard[k + 1] = reportCard[k];
					reportCard[k] = scoreTmp;
				}
			}
		}

		for (int i = 0; i < CLASSNUM; i++)
		{
			std::cout << reportCard[i] << "\t";
		}

	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	///* 문자열 공부 */
	//{
	//	char array[6]{ 'd', 'o', 'g', 'g', 'y' };

	//	//array[5] = '\0';
	//	std::cout << array << std::endl;

	//	char myStr[10];
	//	std::cout << "Input String : ";
	//	// 넘치게 입력하면 오버플로우가 일어나서 stack(메모리에 올라가는 그 스택)이 손상됨
	//	std::cin >> myStr;
	//	std::cout << "your string is \"" << myStr << "\"" <<
	//		std::endl;


	//}
}
