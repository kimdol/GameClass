#pragma once
#include <iostream>

/*파생 클래스와 기반 클래스*/
class Developer
{
public:
    std::string     mName;
    int             mAge;

};
class Programmer : public Developer
{
public:
    void Coding();
    void Debugging();
};
class Designer : public Developer
{
public:
    void Documentation();
    void Presentation();
};
class CheifProgrammer : public Programmer
{
public:
    void Scheduling();
    void Architecture();
};

