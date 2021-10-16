#pragma once
#include <vector>
#include <map>
#include "Student.h"

void Input(int& input);
void Add(std::vector<Student>& Record);
void Remove(std::vector<Student>& Record);
void AllPrint(std::vector<Student>& Record);
float Sum(std::vector<Student>& Record);
void ScorePrint(std::vector<Student>& Record);
void NormalStdnPrint(std::vector<Student>& record);

void MAdd(std::map<int, Student>& Record);
void MRemove(std::map<int, Student>& Record);
void MAllPrint(std::map<int, Student>& Record);
float MSum(std::map<int, Student>& Record);
void MScorePrint(std::map<int, Student>& Record);
void MNormalStdnPrint(std::map<int, Student>& record);

