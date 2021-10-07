#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// stl 사용법2
void TestPrint(const std::string& str)
{
    const char* pStr{ str.c_str() };

    std::cout 
        << strlen(pStr)
        << " : "
        << str.length()
        << " : "
        << str
        << std::endl;
}

int main()
{
    // STL 사용법1
    /*std::string s1, s2;

    s1 = s2;
    s1 += s2;
    s1[0] = 'a';
    s1 = s1 + s2;
    s1 == s2;

    s1.c_str(); // char *(c스타일로 get함)
    s1.insert(pos, s2);
    s1.appedn(s2);*/
    // STL 사용법2
    /*std::string empty;
    TestPrint(empty);

    std::string sized(10, '\0');
    TestPrint(sized);

    std::string s1("test");
    TestPrint(s1);
    std::cout
        << s1[0] << s1[1] << s1[2] << s1[3]
        << std::endl;
    s1[0] = 'T';
    std::cout << s1 << std::endl;

    std::string s2(s1);
    std::string s3 = s1 + s2;
    TestPrint(s3);

    empty = s3;
    TestPrint(empty);

    empty = empty;
    TestPrint(empty);*/
    // STL 사용법 고급1
    /*int number{123};
    std::string str;

    // int -> string
    str = std::to_string(number);
    // string -> int
    number = std::stoi(str);

    std::cout << str << " : " << number << std::endl;
    */
    // stl 사용법 고급2
    /*std::string str{"가나다"};
    TestPrint(str);

    // char ch = '가'; // 한글자 x
    // wchar_t ch = L'가'; // 한글자 o

    std::wstring wStr = L"가나다"; // 유니코드
    std::wcout
        << wStr.length() << " : " << wStr
        << std::endl;*/
    // stl 사용법 고급3
    /*char output[255];

    // c스타일
    sprintf_s(output, 255, "Hello World %d %.3f", 10, 10.1f);
    // c++ 스타일(그저 c++이 만들었을뿐이다)
    snprintf(output, sizeof(output), "Hello World %d %.3f", 10, 10.1f);
    // 리얼 c++ 스타일
    std::ostringstream oss;
    oss << "Hello World " << 10 << 10.1f
        << std::endl;
    std::cout << oss.str() << std::endl;*/
    // stl 고급4
    /*  int myInt{123};
    float myFloat{ 3.141592f };
    bool myBool{ true };

    std::cout << myBool << std::endl;
    std::cout << std::boolalpha
        << myBool << std::endl;
    // boolalpha가 계속 유지됨
    std::cout << false << std::endl;

    std::cout << std::dec << myInt << std::endl;
    std::cout << std::hex << myInt << std::endl;
    std::cout << std::oct << myInt << std::endl;

    std::cout.precision(3);
    std::cout << myFloat << std::endl;

    std::cout.width(10);
    std::cout << std::dec << myInt << std::endl;

    std::cout.fill('0');
    std::cout.width(10);
    std::cout << myInt << std::endl;
    // 한번 흘러보내면 영원히 지속이고,
    // 함수로 지정하면 1회용으로 쓰고 바이바이임
    */

    /*본격적인 STL 사용법1(벡터)*/
    std::vector<int> v1{ 1, 2, 3, 4, 5 };
    std::vector<std::string> v2{ "doggy", "kitty" };
    std::vector<int> v3(5);

    std::cout << v1[0];
    v1[0] = 10;
    v1[10] = 10; // 런타임 에러


}
