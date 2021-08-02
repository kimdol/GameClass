#include <iostream>
#include "hanoi.h"
void Move(int n, int a[], int c[])
{
    c[n - 1] = a[n - 1];
}
void Hanoi(int n, int a[], int b[], int c[])
{
    if (n == 1)
    {
        Move(n, a, c);
    }
    else
    {
        Hanoi(n - 1, a, c, b);
        Move(n, a, c);  // n번째에 있는 원판을 C에 놓기
        Hanoi(n - 1, b, a, c);
    }
}
void Move2(int n, char a, char c)
{
    static int cnt{ 0 };
    std::cout << ++cnt << " : ";
    std::cout  << a << " 에서" << c << "로 " << n << " 번째 원반을 옮깁니다. " << std::endl;
}
void Hanoi2(int n, char a, char b, char c)
{
    if (n == 1)
    {
        Move2(n, a, c);
    }
    else 
    {
        Hanoi2(n - 1, a, c, b);
        Move2(n, a, c);
        Hanoi2(n - 1, b, a, c);
    }
}
// 재귀 호출이 안되는 부분
void Making(int n)
{
    // 원판 n번째에 있는 것을 출력
    // 입력
    // 입력 결과 출력
}
void HanoiMake(int n)
{
    HanoiMake(n - 1); // 원판 2개인 하노이의 탑 게임자체를 만들기
    // 원판 1개가지고 하노이의 탑 게임 자체를 만듬
    Making(n);
}  