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
        Move(n, a, c);  // n��°�� �ִ� ������ C�� ����
        Hanoi(n - 1, b, a, c);
    }
}
void Move2(int n, char a, char c)
{
    static int cnt{ 0 };
    std::cout << ++cnt << " : ";
    std::cout  << a << " ����" << c << "�� " << n << " ��° ������ �ű�ϴ�. " << std::endl;
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
// ��� ȣ���� �ȵǴ� �κ�
void Making(int n)
{
    // ���� n��°�� �ִ� ���� ���
    // �Է�
    // �Է� ��� ���
}
void HanoiMake(int n)
{
    HanoiMake(n - 1); // ���� 2���� �ϳ����� ž ������ü�� �����
    // ���� 1�������� �ϳ����� ž ���� ��ü�� ����
    Making(n);
}  