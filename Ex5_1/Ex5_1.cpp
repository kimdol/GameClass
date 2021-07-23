#include <iostream>
/*함수기초 1-1*/
double Max(double in1, double in2)
{
    return (in1 >= in2) ? in1 : in2;
}
/*함수기초 1-2*/
int ReadValue()
{
    int input;
    std::cout << "값을 입력하시오. ";
    std::cin >> input;

    return input;
}
void WriteValue(int input)
{
    std::cout << "넘겨받은 값 : " << input << std::endl;
}
/*함수기초 1-3*/
int Quotient(int in1, int in2)
{
    return in1 / in2;
}
int Remainder(int in1, int in2)
{
    return in1 % in2;
}
/*함수기초 1-4*/
void Gugudan(int dan)
{
    for (int i = 1; i <= 9; i++)
    {
        for (int k = 1; k <= dan; k++)
        {
            std::cout << k << " x " << i << " = " << k * i << "\t";
        }
        std::cout << "\n";
    }
}
int main()
{
    /*함수기초 1-1*/
    /*{
        double in1{ 0.0 }, in2{ 0.0 }, output{ 0.0 };
        std::cout << "값 2개를 입력하시오. ";
        std::cin >> in1 >> in2;

        output = Max(in1, in2);

        std::cout << output;

    }*/
    /*함수기초 1-2*/
    /*{
        int input{ 0 };

        input = ReadValue();
        WriteValue(input);
    }*/
    /*함수기초 1-3*/
    /*{
        std::cout << "몫 : " << Quotient(8, 2) << " 나머지 : " << Remainder(8, 2) << std::endl;
    }*/
    /*함수기초 1-4*/
    {
        Gugudan(3);
    }
}

/// <summary>
/// 숫자를 출력하기
/// </summary>
/// <param name="x"> 출력할 숫자 </param>
void PrintNumber(int x)
{

}
