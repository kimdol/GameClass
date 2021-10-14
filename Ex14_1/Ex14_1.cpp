#include <iostream>

int main()
{
    // 람다식
    {
        // 매개변수를 2개 int를 받는 익명함수
        auto expr1 = [](int a, int b) {};
        // 매개변수 int 1개와 반환값 float을 돌려주는 익명함수
        [](int a) -> float { return 0.0f; };
    }
}
