#include <iostream>

// 구조체 메모리 지정
//struct alignas(1) MyStruct
//{
//    char val2;
//    int val1;
//};

class MyClass
{
public:
    int mValue;
};

class MySong
{
public:
    int             mTrackno;
    std::string     mName;

    MySong(int no, std::string name) : 
        mTrackno{ no }, mName{ name }
    {}
};

class Image
{

};

class Demon
{
    std::shared_ptr<Image> mspImage;

public:
    Demon(std::shared_ptr<Image> img)
        : mspImage{ img }
    {}
};

class MyNumber
{
public:
    MyNumber operator +(int a)
    {
        return *this;
    }
};

void function(MyNumber&& a)
{

}


int main()
{
    // 람다식
    /*   {
        // 매개변수를 2개 int를 받는 익명함수
        auto expr1 = [](int a, int b) {};
        // 매개변수 int 1개와 반환값 float을 돌려주는 익명함수
        [](int a) -> float { return 0.0f; };
    }*/
    // 화면에 "'\'" 출력하라(유용한 방법은 로우 리터럴)
    /*{
        std::cout << "\"\'\\\'\"" << std::endl;
        std::cout << R"( s "'\'" s )" << std::endl;
    }*/
    // 스마트 포인터 (유니크)
    /*   {
        // std::unique_ptr<MyClass> p{ new MyClass };
        // std::unique_ptr<MyClass> p{ std::make_unique<MyClass>() };

        auto spSong = std::make_unique<MySong>(1, "BattleBGM");

        std::cout << spSong->mTrackno << " : "
            << spSong->mName << std::endl;

        spSong.release();
    }*/
    // 스마트 포인터 (share)
    /*{
        std::shared_ptr<Image> spImage
        { std::make_shared<Image>() };

        {
            auto demon1 = std::make_shared<Demon>(spImage);
            {
                auto demon2 = std::make_shared<Demon>(spImage);
                {
                    auto demon3 = std::make_shared<Demon>(spImage);
                }
            }
        }
    }*/
    // 스마트 포인터 (weak)
    {
        auto p = std::make_unique<MyNumber>();

        function(*p.get()+10);
    }
}
