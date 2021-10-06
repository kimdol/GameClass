#include <iostream>
//#include "MyClass.h"

// 템플릿 시작
template<typename T>
T Function(T a, T b)
{
    T result{};

    result = a + b;

    return result;
}
// 템플릿 예시1
template<typename T>
void SequentialSort(T input[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (input[i] > input[j])
            {
                T temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
}
template<typename T>
void PrtArr(T input[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}
// 템플릿 예시2
template<typename T>
struct LikedList
{
    T* pHead;
    T* pTail;
};
// 템플릿 마지막
class MyClass
{
public:
    int mInt;
    // explicit = 명시적
    explicit MyClass(int val) : mInt{ val } {};
};

int main()
{
    // 템플릿 시작
    /*std::cout << Function(2, 3)
        << std::endl;
    std::cout << Function<float>(2.1f, 1.1f)
        << std::endl;*/
    // 템플릿 예시 1
    /*int iArr[] = { 3, 2, 1, 5, 4 };
    float fArr[] = { 1.0f, 2.0f, 5.0f, 3.0f };

    SequentialSort<int>(iArr, 5);
    PrtArr<int>(iArr, 5);

    SequentialSort<float>(fArr, 4);
    PrtArr<float>(fArr, 4);*/
    // 이상한 템플릿(cpp와 헤더를 따로 쓰면 에러남)
    /*MyClass<int> c1;
    c1.Function(10);*/
    // 템플릿 마지막(위에 꺼는 오류남)
    /*MyClass c = 1; 
    MyClass c = MyClass(1);*/
}
