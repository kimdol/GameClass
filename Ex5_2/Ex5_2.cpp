#include <iostream>
#include <stdarg.h>    // 가변 인자 사용하기 위한 헤더

//int Sum(int num[5])
//{
//    int total{ 0 };
//
//    for (int i = 0; i < 5; i++)
//    {
//        total += num[i];
//    }
//    return total;
//}

void PrintInfo(); // 2번
/*애매모호한 함수 초기값과 오버로딩*/
int BoxArea(int w, int l = 1);
int BoxArea(int size);
/*가변 인자 함수*/
void funcion(int count, ...)
{
    va_list params;
    va_start(params, count);

    for (int i = 0; i < count; ++i)
    {
        std::cout << va_arg(params, int) << " ";
    }
}


int main()
{
    /* 함수 기본 */
    /*{
        std::cout << pow(2, 2) << std::endl;

    }*/
    /*함수에 매개변수로 배열을 사용해 봅시다*/
    /*{
        int num[]{ 1, 2, 3, 4, 5 };

        std::cout << Sum(num) << std::endl;
    }*/
    /*프로그램 만드는 과정*/
    //{
    //    // 1번(프로그램 정보 출력)
    //    PrintInfo();    // 일단 메인에 쓸 함수부터 적고 시작한다
    //}
    /*애매모호한 함수 초기값과 오버로딩*/
    /*{
        std::cout << BoxArea(5) << std::endl;
    }*/
    /*가변 인자 함수 사용중...*/
    /*{
        funcion(3, 1, 3, 4);
    }*/
    /*중간 점검 문제 1-1*/
    {
        struct monster
        {
            string type;
            
        };
    }
    return 0;
}
// 빠른 리펙토링 쓴것
void PrintInfo()
{

}

int BoxArea(int w, int l)
{
    return w * l;
}

int BoxArea(int size)
{
    return size * size;
}
