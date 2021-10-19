#include <iostream>
#include <tuple>
#include <functional>
#include <regex>
#include <thread>
#include <mutex>
#include <future>

std::mutex gMutex;

// 함수
void MyFunction(int arg1, int arg2) {}

// 객체 - 함수 연산자 () 오버로딩
class MyClass
{
public:
    void operator()(int) {};
};

//void Move()
//{
//    while (네트워크수신완료 ? )
//    {
//        수신
//    }
//    player.Move();
//}

void PrintInt()
{
    for (int i = 0; i < 9999; )
    {
        if (gMutex.try_lock())
        {
            i++;
            std::cout << "worker1 : " << i << std::endl;
            gMutex.unlock();
        }
    }
}

void PrintAscii()
{
    for (int repeat = 0; repeat < 90; repeat++)
    {
        for (int i = 33; i < 126; )
        {
            if (gMutex.try_lock())
            {
                i++;
                std::cout << "worker2 : " << char(i) << std::endl;
                gMutex.unlock();
            }
        }
    }
}

int main()
{
    // 튜플
    /*std::tuple<int, std::string, int> student{ 1, "Kim", 50 };

    student = std::make_tuple(2, "lee", 10);

    std::cout << std::get<0>(student) << std::endl;
    std::cout << std::get<1>(student) << std::endl;
    std::cout << std::get<2>(student) << std::endl;*/
    // 함수 포인터(스크립트를 제작할 때 유용함)
    /*std::function<void(int, int)> functor1 = MyFunction;
    std::function<void(int)> functor2 = MyClass();
    std::function<void()> functor3 = []() {};

    functor1(10, 1);
    functor2(4);
    functor3();

    auto funtor1 = std::bind(MyFunction,
        std::placeholders::_1,
        std::placeholders::_2);
    funtor1(1, 2);*/
    // 정규표현식(       \"([^\"]*)\"        )
    std::cout << "hello" << " " << "world!" << std::endl;
    // 정규표현식2
    /*std::cout << "이메일 : ";
    std::string email;
    std::cin >> email;

    std::regex pattern(R"((\w+[\w\.]*)@(\w+[\w\.]*)\.([A-Za-z]+))");

    if (std::regex_match(email, pattern))
    {
        std::cout << "올바른" << std::endl;
    }
    else
    {
        std::cout << "잘못된" << std::endl;
    }*/
    // 멀티테스킹
    /*std::thread job1(PrintInt);
    std::thread job2(PrintAscii);

    job1.join();
    job2.join();*/
    // 비동기
    std::future<void> async1 = std::async(PrintInt);
    std::future<void> async2 = std::async(PrintAscii);

    std::cout << "작업 끝!" << std::endl;

    async1.get();
    std::cout << "Worker1 완료 " << std::endl;

}
