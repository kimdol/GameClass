#pragma once

#include <fstream>
#include <string>

class Monster
{
private:
    std::string mName;
    int mLevel;
    int mHp;
    int mMp;
public:
    Monster() : mName{}, mLevel{}, mHp{}, mMp{}
    {}
    Monster(std::string name, int level, int hp, int mp) :
        mName{ name }, mLevel{ level }, mHp{ hp }, mMp{ mp }
    {

    }
    ~Monster() {

    }

    std::ifstream& ReadBinary(std::ifstream& ifs);
    std::ofstream& WriteBinary(std::ofstream& ofs);
};

std::ifstream& Monster::ReadBinary(std::ifstream& ifs)
{
    int strLen{};
    ifs.read(reinterpret_cast<char*>(&strLen), sizeof(int));
    mName.resize(strLen);
    ifs.read(&mName[0], strLen);

    ifs.read(reinterpret_cast<char *>(&mLevel), sizeof(int));
    ifs.read(reinterpret_cast<char*>(&mHp), sizeof(int));
    ifs.read(reinterpret_cast<char*>(&mMp), sizeof(int));

    return ifs;
}

std::ofstream& Monster::WriteBinary(std::ofstream& ofs)
{
    //          nmae,        level,  hp, mp
    // 문자열 길이 + 문자열    4     4    4
    int strLen{ static_cast<int>(mName.size()) };
    ofs.write(reinterpret_cast<char*>(&strLen), sizeof(int));
    ofs.write(mName.c_str(), strLen);

    ofs.write(reinterpret_cast<char*>(&mLevel), sizeof(int));
    ofs.write(reinterpret_cast<char*>(&mHp), sizeof(int));
    ofs.write(reinterpret_cast<char*>(&mHp), sizeof(int));

    return ofs;
}

std::ifstream& operator >> (std::ifstream& ifs, Monster& monster)
{
    return monster.ReadBinary(ifs);
}

std::ofstream& operator << (std::ofstream& ofs, Monster& monster)
{
    return monster.WriteBinary(ofs);
}
