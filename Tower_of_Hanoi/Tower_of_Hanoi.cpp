#include <iostream>
void Move(int n, int a[], int c[])
{
    c[n-1] = a[n-1];
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
        Move(n, a, c);
        Hanoi(n - 1, b, a, c);
    }
    

}

int main()
{
    int a[]{ 1, 2, 3, 4, 5 }, b[5]{}, c[5]{};
    Hanoi(5, a, b, c);
    for (int i = 0; i < 5; i++)
    {
        std::cout << c[i] << std::endl;
    }
}
