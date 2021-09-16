#include <iostream>
#include "Dog.h"
#include "Point2D.h"
#include "DateClass.h"
#include "Student.h"

//class Dog
//{
//private:
//    int mAge;
//
//public:
//    int mWeight;
//
//    void Function()
//    {
//        mAge = 1;
//    }
//
//};

//struct Dog
//{
//    int mAge;
//};
//int GetAge(Dog dog)
//{
//    return dog.mAge;
//}

// class 첫 시작
class Dogg
{
private:
    int mAge;
public:
    int GetAge(Dogg& dog)
    {
        return dog.mAge;
    }
    // forward declearation 전방 선언
    // 안해도 됨
    void f1()
    {
        f2();
    }
    void f2()
    {
        
    }
};
/* 상수 멤버 함수(const member function)*/
class Calender
{
private:
    int mMonth;

public:
    // setter
    void SetMonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            mMonth = month;
        }
    }
    void SetMonth(std::string month)
    {
        if (month == "jan")
        {
            mMonth = 1;
        }
    }

    // getter (상수 멤버 함수)
    std::string GetMonth() const
    {
        switch (mMonth)
        {
            case 1:
                return "January";

            default :
                return "INVALID";
        }
    }
};
/*초기화 리스트를 가진 class*/
class Quest
{
private:
    const int mID;
    const int mExp;

public:
    // 초기화 리스트(Initializer List)
    Quest(int a = 1, int b = 2) : mID{ a }, mExp( b )
    {
        
    }

    void Print()
    {
        std::cout << "ID : " << mID << std::endl;
        std::cout << "EXP : " << mExp << std::endl;
    }
};
/*elegating 생성자를 가진 class*/
class Dele
{
private:
    int mID;
    int mExp;

public:
    // 초기화 리스트(Initializer List)
    Dele() : mID{ 1 }, mExp(1)
    {
        // 초기 행동
    }
    Dele(int a, int b) : Dele()
    {
        
    }

    void Print()
    {
        std::cout << "ID : " << mID << std::endl;
        std::cout << "EXP : " << mExp << std::endl;
    }
};
/*소멸자 활용*/
class MyArray
{
private:
    int mLength;
    int* mArray;

public:
    MyArray(int length) : mLength{ length }
    {
        mArray = new int[length];
    }

    ~MyArray()
    {
        delete[] mArray;
    }
};

int main()
{
    /*Dog class*/
    /*Dog happy;
    happy.GetAge();*/
    /*Warrior class*/
    /*  Warrior player1, player2;
    // 초기값 설정
    player1.Setting(10, 5, 0);
    player2.Setting(5, 10, 0);
    // 공격 1 -> 2
    player1.Attack(player2);
    // p1 스킬 on
    player1.Skill();
    // p1 스킬 off
    player1.Skill(); */
    /*point2D(pixel) class*/
    /*Point2D oneCel;
    oneCel.Setting(2, 2);

    oneCel.Print();
    oneCel.Length();*/
    /*생성자, 소멸자*/
    /*Point2D* pt = new Point2D{ 1, 3 };
    pt->Print();
    delete pt;*/
    /*기본 생성자를 사용한 인스턴스화*/
    /*Point2D pt1 = Point2D();
    * Point2D pt1{};
    pt1.Print();*/
    /*생성자를 사용해서 인스턴스화*/
    /*Point2D pt2(2, 3);
    Point2D pt2{ 2, 3 };
    pt2.Print();*/
    /*POD(11:간단, 00:간단x)*/
    /*std::cout << 
        std::is_trivial<Point2D>::value 
        << std::is_pod<Point2D>::value
        << std::endl;*/
    /*대리생성자 사용*/
    /*Dele d = Dele(2, 2);
    d.Print();*/
    /*Date, Student class 설계*/
    DateClass d{2021, 1, 1};
    d.Print();

    Student s{"홍길동", 95};
    s.Print();

}
