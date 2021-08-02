#include <iostream>
#include "hanoi.h"

struct Top
{
    int dish[3][3]
    {
        {1, 0, 0},
        {2, 0, 0},
        {3, 0, 0}
    };
    char place[3]
    { 'A', 'B', 'C' };
} hanoi_Top;
void Result();
bool Input(char *from, char *to);
int Search(int pos);
bool Move(char from, char to);
bool End();

int main()
{
    /* 원반 놓을 곳을 배열로 비유해서 해결*/
    /*
    const int MAX{ 10 };
    int a[MAX]{}, b[MAX]{}, c[MAX]{}, input{ 0 };

    std::cout << "원반 갯수를 입력하라. ";
    std::cin >> input;

    for (int i = 0; i < input; i++)
    {
        a[i] = i + 1;
    }

    Hanoi(input, a, b, c);

    for (int i = 0; i < input; i++)
    {
        std::cout << c[i] << std::endl;
    }
    */
    /* 원반 놓을 곳을 문자로 비유해서 해결*/
    /*const int MAX{ 10 };
    int input{ 0 };
    
    std::cout << "원반 갯수를 입력하라. ";
    std::cin >> input;
    
    Hanoi2(input, 'A', 'B', 'C');*/
    /*============하노이 탑 실제로 만들어 보자===============*/
    char from{'a'}, to{'a'};
    while (1)
    {
        // 게임 결과를 그림으로 보여준다.
        Result();
        // from과 to를 입력 받겠지
        if (!Input(&from, &to))
        {
            std::cout << "\n 입력을 다시 해주세요" << std::endl;
        }
        // 주문받은대로 원판을 옮긴다.
        if (!Move(from, to))
        {
            std::cout << " \n 거기로 옮길 수 없습니다. " << std::endl;
        }
        // 게임 종료 조건이면 박수와 함꼐 종료한다.
        if (End())
        {
            std::cout << "====================================================================" << std::endl;
            Result();
            std::cout << "\n정답입니다. \n게임이 종료됩니다" << std::endl;
            std::cout << "====================================================================" << std::endl;
            break;
        }
    }
    
}

void Result()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            std::cout << hanoi_Top.dish[i][k] << "\t";
        }
        std::cout << "\n";
    }
    for (int i = 0; i < 3; i++)
    {
        std::cout << hanoi_Top.place[i] << "\t";
    }
}

bool Input(char* from, char* to)
{
    std::cout << "\nfrom과 to를 입력하라.";
    std::cin >> *from >> *to;
    // from과 to가 같을 때
    if (*from == *to)
    {
        return false;
    }
    // from과 to가 지정된 장소를 입력하지 않았을 때
    if (*from < 'a' || *from > 'c' || *to < 'a' || *to >'c')
    {
        return false;
    }



    return true;
}
// 제일 윗칸의 원반찾기
int Search(int pos)
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        if (hanoi_Top.dish[i][pos])
        {
            return i;
        }
    }
    return i-1;
}

bool Move(char from, char to)
{
    int fromPos{ from - 'a' }, fromMax{ Search(fromPos) };
    int toPos{ to - 'a' }, toMax{ Search(toPos) };
    // from에 있는 원반이 to보다 클 때
    if (hanoi_Top.dish[fromMax][fromPos] > hanoi_Top.dish[toMax][toPos])
    {
        if (hanoi_Top.dish[toMax][toPos])
        {
            return false;
        } else
        {
            
        }
    }

    if (!hanoi_Top.dish[toMax][toPos])
    {
        hanoi_Top.dish[toMax][toPos] = hanoi_Top.dish[fromMax][fromPos];
        hanoi_Top.dish[fromMax][fromPos] = 0;
    } else
    {
        hanoi_Top.dish[toMax - 1][toPos] = hanoi_Top.dish[fromMax][fromPos];
        hanoi_Top.dish[fromMax][fromPos] = 0;
    }
    
    return true;
}

bool End()
{
    int placePos{ 'c' - 'a' }, dishPos{ 0 };
    if (hanoi_Top.dish[dishPos][placePos])
    {
        return true;
    }
    return false;
}
