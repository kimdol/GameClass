#include <iostream>
#include <fstream>

bool LoadFile(const char* filename)
{
    // 1. 파일 스트림 객체(입력)
    std::ifstream ifs(filename);
    if (!ifs)
    {
        std::cout << filename << "을 찾을 수 없습네다" << std::endl;
        return false;
    }
    // 2. 작업 (데이터 꺼내오기)
    char ch;
    while (ifs >> ch)
    {
        std::cout << ch;
    }
    // 3. 객체 제거(파일 닫기)
    ifs.close();
    return true;
}

int main()
{
    // 파일 스트림
    {
        LoadFile("F:\\DirectX_Class\\GameClass\\Ex15_1\\Data\\SimpleData.txt");
        
        
    }
}