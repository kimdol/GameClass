﻿#include <iostream>
#include <fstream>
#include <sstream>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include "Monster.h"

using namespace rapidjson;

bool SaveToJSON(const char* filename, std::vector<Monster>& monsters)
{
    StringBuffer sb;
    PrettyWriter<StringBuffer> writer(sb);

    // CODE(핵심)
    writer.StartObject();   // {
    writer.Key("monsters"); // "monsters" :
    writer.StartArray();    // [

    for (auto& monster : monsters)
    {
        writer.StartObject();
        writer.Key("name");
        writer.String(monster.GetName().c_str());
        // status
        writer.Key("status");
        {
            writer.StartObject();
            Status status = monster.GetStatus();
            writer.Key("level");    writer.Int(status.mLevel);
            writer.Key("hp");    writer.Int(status.mHP);
            writer.Key("mp");    writer.Int(status.mMP);
            writer.EndObject();
        }
        // drops
        writer.Key("items");
        {
            writer.StartArray();
            for (auto item : monster.GetDropItems())
            {
                writer.StartObject();
                writer.Key("name"); writer.String(item.mName.c_str());
                writer.Key("gold"); writer.Int(item.mGold);
                writer.EndObject();
            }
            writer.EndArray();
        }

        writer.EndObject();
    }


    writer.EndArray();      // ]
    writer.EndObject();     // }
    
                            
    // 핵심 끝
    std::ofstream ofs;
    ofs.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
        ofs.open(filename);
        ofs << sb.GetString();
        ofs.close();
    }
    catch (std::exception e)
    {
        std::cerr << "파일 저장 중에 예외가 발생했습니다." << std::endl;
        std::cerr << e.what() << std::endl;
        ofs.close();
        return false;
    }
    return true;
}

bool LoadFromJSON(const char* filename, std::vector<Monster>& monsters)
{
    std::ifstream ifs;
    ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    std::stringstream ss;

    try
    {
        ifs.open(filename);
        ss << ifs.rdbuf();
        ifs.close();
    }
    catch(std::exception e)
    {
        std::cerr << "파일을 읽는 도중에 예외가 발생했습니다." << std::endl;
        std::cerr << e.what() << std::endl;
        ifs.close();
        return false;
    }

    Document doc;
    doc.Parse(ss.str().c_str());

    for (auto& elem : doc["monsters"].GetArray())
    {
        Monster monster;

        monster.SetName(elem["name"].GetString());
        auto status = elem["status"].GetObject();
        monster.SetStatus({
            status["level"].GetInt(),
            status["hp"].GetInt(),
            status["mp"].GetInt()
            });
        for (auto& item : elem["items"].GetArray())
        {
            monster.AddDropItem({
                item["name"].GetString(),
                item["gold"].GetInt()
                });
        }

        monsters.push_back(monster);
    }

    return true;
}

int main()
{
    std::vector<Monster> monsters;

    Monster monster;

    monster.SetName("슬라임");
    monster.SetStatus({ 1, 1, 1 });
    monster.AddDropItem({ "끈적한젤리",1 });
    monsters.push_back(monster);
    monster.GetDropItems().clear();

    monster.SetName("늑대인간");
    monster.SetStatus({ 5, 5, 5 });
    monster.AddDropItem({ "발톱",2 });
    monster.AddDropItem({ "가죽",5 });
    monsters.push_back(monster);
    monster.GetDropItems().clear();

    monster.SetName("악마");
    monster.SetStatus({ 10, 10, 10 });
    monster.AddDropItem({ "날개",15 });
    monster.AddDropItem({ "암흑",20 });
    monsters.push_back(monster);
    monster.GetDropItems().clear();

    SaveToJSON("Data/monsters.json", monsters);

    monsters.clear();
    LoadFromJSON("Data/monsters.json", monsters);
}
