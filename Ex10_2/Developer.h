#pragma once
#include <iostream>

/*�Ļ� Ŭ������ ��� Ŭ����*/
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

