#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

class Sprite
{
public:
    std::string n;
    int         x;
    int         y;
    int         w;
    int         h;
};

void LoadXML(const char* filename, std::vector<Sprite>& sprites)
{
    sprites.clear();

    // 파일 열기
    std::ifstream ifs(filename, std::ifstream::binary);

    // 정규표현식 패턴 생성
    std::regex pattern("\"([^\"]*)\"");

    // 파일 끝까지
    while (!ifs.eof())
    {
        std::string line{};

        // 한 줄
        std::getline(ifs, line);

        auto result = line.find("<sprite");
        if (result != std::string::npos)
        {
            // 패턴 검색
            std::sregex_iterator current(line.begin(), line.end(), pattern);
            std::sregex_iterator end;
            // 대입을 하기 위한 준비작업
            Sprite sprite;
            int index{ 0 };

            while (current != end)
            {
                // sprite의 속성(멤버변수) 대입
                std::string token = (*current)[1];
                switch (index)
                {
                    case 0:
                        sprite.n = token;
                        break;

                    case 1:
                        sprite.x = std::stoi(token);
                        break;

                    case 2:
                        sprite.y = std::stoi(token);
                        break;

                    case 3:
                        sprite.w = std::stoi(token);
                        break;

                    case 4:
                        sprite.h = std::stoi(token);
                        break;
                }
                // 일치하는 다음 패턴
                current++;
                index++;
            }

            if (index > 4)
            {
                sprites.push_back(sprite);
            }
        }
    } 
}

int main()
{
    // 우리가 만든 것
   /* std::vector<Sprite> sprites;
    LoadXML("Data/mydata.xml", sprites);

    for (auto e : sprites)
    {
        std::cout << e.n << " : "
            << e.x << ","
            << e.y << ","
            << e.w << ","
            << e.h << std::endl;
    }*/
    // 다른 사람이 만든 것을 분석

}
