#include <iostream>
#include "Dog.h"

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

int main()
{
    /*Dog class*/
    /*Dog happy;
    happy.GetAge();*/
    /*Warrior class*/
    Warrior player1, player2;
    // 초기값 설정
    player1.Setting(10, 5, 0);
    player2.Setting(5, 10, 0);
    // 공격 1 -> 2
    player1.Attack(player2);
    // p1 스킬 on
    player1.Skill();
    // p1 스킬 off
    player1.Skill();



}
