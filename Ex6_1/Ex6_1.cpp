#include <iostream>

void Swap(int* a, int* b)
{
	int tmp{ *a };
	*a = *b;
	*b = tmp;
}

int Sum(int a, int b)
{
	return a + b;
}

int Fun(float f)
{
	return 0;
}

using funcion_ptr = int(*)(float);
// 정렬
void Sort(int numbers[], int count)
{
	int tmp{};

	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[i] < numbers[j]) // 이부분을 함수로 만들어서 내림차순, 오름차순을 변경한다
			{
				tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}
		}
	}
}

void Traverse(int start, int end, int* arr);

int main()
{
	/*포인터 기초*/
	/*int a{ 0 }, b{ 0 };
	int* p;

	p = &a;
	p = &b;*/
	/*포인터 기초2*/
	/*int a{ 1 };
	int* p{ &a };

	std::cout << p << std::endl;
	std::cout << p + 1 << std::endl;
	std::cout << p + 2 << std::endl;*/
	/*포인터 기초3*/
	/*int a{ 1025 };
	int* pa{ &a };

	char* p0{ (char*)pa };

	for (int i = 0; i < 4; i++)
	{
		std::cout << (void*)p0 << " : " << (int)*p0 << std::endl;

		p0++;
	}*/
	/*포인터 기초4*/
	/*int x{ 10 }, y{ 20 };

	Swap(&x, &y);

	std::cout << x << ", " << y << std::endl;*/
	/*포인터 기초5*/
	/*int a{}, b{}, arr[3]{};

	std::cout << &a << " ," << &b << std::endl;
	std::cout << &Sum << " ," << &main << std::endl;
	std::cout << Sum << " ," << main << std::endl;

	std::cout << arr << " ," << &arr << std::endl;*/
	/*함수 포인터 기초 1*/
	/*const int NumArray = 5;
	int scores[NumArray]{ 20, 10, 40, 15, 30 };

	Sort(scores, NumArray);
	for (int i = 0; i < 5; i++)
	{
		std::cout << scores[i] << ", ";
	}
	std::cout << std::endl;*/
	/*배열과 포인터 관계*/
	/*int arr[5]{};
	int* p;

	p = arr;

	for (int i = 0; i < 5; i++)
	{
		std::cout << &arr[i] << std::endl;
	}

	std::cout << arr << " ," << p << std::endl;*/
	/*배열과 포인터 기초1*/
	/*int arr[2][3];

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << &arr[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
	/*1. 배열을 순회(traverse)해 봅시다.*/
	int array1[5]{ 1, 2, 3, 4, 5 };

	for (int i = 0; i < 5; i++)
	{
		std::cout << *(array1 + i) << " ";
	}
	std::cout << std::endl;

	/*2. 배열을 순회(traverse)해 봅시다.*/
	int array2[2][3]{
		{ 1, 2, 3 },
		{ 4, 5, 6 }
	};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << *(*(array2 + i) + j) << " ";
		}
		std::cout << std::endl;
	}


}

void Prt(int n, int* arr)
{
	std::cout << *(arr + n) << " ";
}

void Traverse(int start, int end, int* arr)
{
	if (start == end)
	{
		Prt(start, arr);
	}
	else
	{
		Prt(start, arr);
		Traverse(start + 1, end, arr);
	}
}
