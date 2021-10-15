#include <iostream>

// 구조체 메모리 지정
//struct alignas(1) MyStruct
//{
//    char val2;
//    int val1;
//};

int main()
{
    // 람다식
    {
        // 매개변수를 2개 int를 받는 익명함수
        auto expr1 = [](int a, int b) {};
        // 매개변수 int 1개와 반환값 float을 돌려주는 익명함수
        [](int a) -> float { return 0.0f; };
    }
    // 화면에 "'\'" 출력하라(유용한 방법은 로우 리터럴)
    {
        std::cout << "\"\'\\\'\"" << std::endl;
        std::cout << R"( s "'\'" s )" << std::endl;
    }
}
