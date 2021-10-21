#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

//bool LoadFile(const char* filename)
//{
//    // 1. 파일 스트림 객체(입력)
//    std::ifstream ifs(filename);
//    if (!ifs)
//    {
//        std::cout << filename << "을 찾을 수 없습네다" << std::endl;
//        return false;
//    }
//    // 2. 작업 (데이터 꺼내오기)
//    char ch;
//    while (ifs >> ch)
//    {
//        std::cout << ch;
//    }
//    // 3. 객체 제거(파일 닫기)
//    ifs.close();
//    return true;
//}
class Monster
{
private:
    std::string mName;
    int mLevel;
    int mHp;
    int mMp;
public:
    Monster() : Monster("?", -1, -1, -1)
    {}
    Monster(std::string name, int level, int hp, int mp) :
        mName{ name }, mLevel{ level }, mHp{ hp }, mMp{ mp }
    {

    }
    ~Monster() {

    }

    void SetName(const std::string& name)
    {
        mName = name;
    }
    void SetLevel(const int& level)
    {
        mLevel = level;
    }
    void SetHP(const int& hp)
    {
        mHp = hp;
    }
    void SetMP(const int& mp)
    {
        mMp = mp;
    }

    void Print()
    {
        std::cout << mName << ", " << mLevel << ", "
            << mHp << ", " << mMp
            << std::endl;
    }

    friend std::istream& operator >> (std::istream& is, Monster& monster);
    friend std::ostream& operator<< (std::ostream& os, Monster& monster);
};
std::istream& operator >> (std::istream& is, Monster& monster)
{
    std::string buffer;
    try
    {
        std::getline(is, buffer, ',');
        monster.mName = buffer;
        std::getline(is, buffer, ',');
        monster.mLevel = stoi(buffer);
        std::getline(is, buffer, ',');
        monster.mHp = stoi(buffer);
        std::getline(is, buffer);
        monster.mMp = stoi(buffer);
    } catch(std::exception e)
    {
        std::cout << "데이터 형식이 잘못되었습니다!" << std::endl;
        std::cout << e.what() << std::endl;
    }
    return is;
}
std::ostream& operator << (std::ostream& os, Monster& monster)
{
    try
    {
        os << monster.mName << "," <<
            monster.mLevel << "," <<
            monster.mHp << "," <<
            monster.mMp << "," <<
            std::endl;
    }
    catch (std::exception e)
    {
        std::cout << "스트림에 저장할 때 오류가 발생했습니다."
            << std::endl;
    }
    return os;
}
bool LoadFile(const char* filename, std::vector<Monster>& vector)
{
    // 1. 파일 스트림 객체(입력)
    std::ifstream ifs;
    ifs.exceptions(std::ifstream::badbit);

    try
    {
        ifs.open(filename);

        std::string buffer;

        std::getline(ifs, buffer);
        while (!ifs.eof())
        {
            Monster mon;
            ifs >> mon;
            vector.push_back(mon);


        }
        ifs.close();
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;

        ifs.close();
        return false;
    }
    return true;
}

bool SaveFile(const char* filename, std::vector <Monster>& monsters)
{
    std::ofstream ofs;
    ofs.exceptions(std::ofstream::badbit);

    try
    {
        ofs.open(filename);

        ofs << "--- MONSTER DATA ---" << std::endl;
        for (auto& e : monsters)
        {
            ofs << e;
        }
        ofs.close();
    }
    catch (std::exception e)
    {
        std::cout << "파일 저장 도중 오류가 발생했습니다." << std::endl;
        std::cout << e.what() << std::endl;
        ofs.close();
        return false;
    }

    return true;
}

int main()
{
    // 파일 스트림
    {
        //LoadFile("F:\\DirectX_Class\\GameClass\\Ex15_1\\Data\\SimpleData.txt");

        std::vector<Monster> monsters;
        LoadFile("Data/SimpleData.txt", monsters);

        for (auto& e : monsters)
        {
            e.Print();
        }

        monsters.push_back({ "ORC", 20, 20, 20 });

        SaveFile("Data/SimpleData.txt", monsters);
        
    }
}