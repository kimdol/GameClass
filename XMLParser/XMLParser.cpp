#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

#include "Monster.h"
#include "tinyxml2.h"

using namespace tinyxml2;
bool SaveToXML(const char* filename, const std::vector<Monster>& monsters)
{
    XMLDocument doc;
    
    XMLDeclaration* decl = doc.NewDeclaration(R"(xml version="1.0" encoding="EUC-KR")");
    doc.LinkEndChild(decl);

    XMLElement* pRootNode = doc.NewElement("monsters");
    
    for (auto monster : monsters)
    {
        XMLElement* pMonsterNode = doc.NewElement("monster");
        pMonsterNode->SetAttribute("name", monster.GetName().c_str());

        XMLElement* pStatusNode = doc.NewElement("status");
        const Status& status = monster.GetStatus();
        pStatusNode->SetAttribute("level", status.mLevel);
        pStatusNode->SetAttribute("hp", status.mHP);
        pStatusNode->SetAttribute("mp", status.mMP);
        pMonsterNode->LinkEndChild(pStatusNode);

        XMLElement* pItemsNode = doc.NewElement("items");
        for (auto item : monster.GetDropItems())
        {
            XMLElement* pItemNode = doc.NewElement("item");
            pItemNode->SetAttribute("name", item.mName.c_str());
            pItemNode->SetAttribute("gold", item.mGold);
            pItemsNode->LinkEndChild(pItemNode);
        }
        pMonsterNode->LinkEndChild(pItemsNode);

        pRootNode->LinkEndChild(pMonsterNode);
    }



    doc.LinkEndChild(pRootNode);

    return doc.SaveFile(filename) == XML_SUCCESS;
}
bool LoadFromXML(const char* filename, std::vector<Monster>& monsters)
{
    XMLDocument doc;

    if (doc.LoadFile(filename) != XML_SUCCESS)
    {
        return false;
    }

    XMLElement* pRootNode = doc.FirstChildElement("monsters");
    for (XMLElement* pMonsterNode = pRootNode->FirstChildElement();
        pMonsterNode != nullptr;
        pMonsterNode = pMonsterNode->NextSiblingElement())
    {
        Monster monster;

        monster.SetName(pMonsterNode->Attribute("name"));
        auto pStatusNode = pMonsterNode->FirstChildElement("status");
        Status status;
        status.mLevel = pStatusNode->IntAttribute("level");
        status.mHP = pStatusNode->IntAttribute("hp");
        status.mMP = pStatusNode->IntAttribute("hp");
        monster.SetStatus(status);

        auto pItemsNode = pMonsterNode->FirstChildElement("items");
        for (auto pItemNode = pItemsNode->FirstChildElement();
            pItemNode != nullptr;
            pItemNode = pItemNode->NextSiblingElement())
        {
            Item item;
            item.mName = pItemNode->Attribute("name");
            item.mGold = pItemNode->IntAttribute("gold");
            monster.AddDropItem(item);
        }

        monsters.push_back(monster);
    }


    return true;
}

//{
//    class Sprite
//    {
//    public:
//        std::string n;
//        int         x;
//        int         y;
//        int         w;
//        int         h;
//    };
//    void LoadXML(const char* filename, std::vector<Sprite>&sprites)
//    {
//        sprites.clear();
//
//        // 파일 열기
//        std::ifstream ifs(filename, std::ifstream::binary);
//
//        // 정규표현식 패턴 생성
//        std::regex pattern("\"([^\"]*)\"");
//
//        // 파일 끝까지
//        while (!ifs.eof())
//        {
//            std::string line{};
//
//            // 한 줄
//            std::getline(ifs, line);
//
//            auto result = line.find("<sprite");
//            if (result != std::string::npos)
//            {
//                // 패턴 검색
//                std::sregex_iterator current(line.begin(), line.end(), pattern);
//                std::sregex_iterator end;
//                // 대입을 하기 위한 준비작업
//                Sprite sprite;
//                int index{ 0 };
//
//                while (current != end)
//                {
//                    // sprite의 속성(멤버변수) 대입
//                    std::string token = (*current)[1];
//                    switch (index)
//                    {
//                        case 0:
//                            sprite.n = token;
//                            break;
//
//                        case 1:
//                            sprite.x = std::stoi(token);
//                            break;
//
//                        case 2:
//                            sprite.y = std::stoi(token);
//                            break;
//
//                        case 3:
//                            sprite.w = std::stoi(token);
//                            break;
//
//                        case 4:
//                            sprite.h = std::stoi(token);
//                            break;
//                    }
//                    // 일치하는 다음 패턴
//                    current++;
//                    index++;
//                }
//
//                if (index > 4)
//                {
//                    sprites.push_back(sprite);
//                }
//            }
//        }
//    }
//}

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
    {
        std::vector<Monster> monsters;

        Monster monster;
        monster.SetName("슬라임");
        monster.SetStatus(Status{ 1, 1, 1 });
        monster.AddDropItem(Item{ "끈적한 젤리", 1 });
        monsters.push_back(monster);

        monster.SetName("늑대인간");
        monster.SetStatus(Status{ 5, 5, 5 });
        monster.GetDropItems().clear();
        monster.AddDropItem(Item{ "발톱", 2 });
        monster.AddDropItem(Item{ "가죽", 2 });
        monsters.push_back(monster);

        monster.SetName("악마");
        monster.SetStatus(Status{ 10, 10, 10 });
        monster.GetDropItems().clear();
        monster.AddDropItem(Item{ "날개", 10 });
        monster.AddDropItem(Item{ "손톱", 5 });
        monsters.push_back(monster);

        SaveToXML("Data/monsters.xml", monsters);

        monsters.clear();
        LoadFromXML("Data/monsters.xml", monsters);
    }
}
