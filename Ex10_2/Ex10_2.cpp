#include <iostream>
#include "Dog.h"

class ClassA
{
public:
    void func(int i) {}
    void func(float f, int i) {}
    void func1()
    {
        std::cout <<
            "ClassA::func1()"
            << std::endl;
    }
    virtual void func2() 
    {
        std::cout << "ClassA::func2()"
            << std::endl;
    }
};

class ClassB : public ClassA
{
public:
    void func(int i) {}
    void func(float f, int i) {} // 오류 해결2222
    void func1()
    {
        std::cout <<
            "ClassB::func1()"
            << std::endl;
    }
    void func2()
    {
        std::cout << "ClassB::func2()"
            << std::endl;
    }
};

int main()
{
    /*파생 연습1*/
    /*Dog happy;

    happy.SetBreed(Dog::BREED::HUSKY);
    happy.SetAge(15);

    happy.Sound();
    happy.Roll();*/
    /*기반 생성자, 파생 생성자 같이 쓰기*/
    /*Dog happy(Dog::HUSKY, 3, 10);
    */
    /*오버 라이딩*/
    /*Dog happy(Dog::HUSKY, 3, 10);
    happy.Sound();*/
    /* 오버 라이딩 오류실험 */
    /*ClassB b;
    b.func(10.0f, 1); 오류남
    b.ClassA::func(10.0f, 1); 오류 해결1111
    하지만 코드가 안이쁨*/
    /* 다형성
    (모든 final들을 받는 함수를 만들기 위함) */
    /*ClassA* p1 = new ClassA;
    ClassB* p2 = new ClassB;

    ClassA* pM = p2;
    pM->func1();
    pM->func2();

    delete p2;
    delete p1;*/
}
