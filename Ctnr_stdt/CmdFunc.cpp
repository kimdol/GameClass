#include <iostream>
#include <vector>
#include <map>
#include "CmdFunc.h"
#include "Student.h"

void Input(int& input)
{
	std::cout <<
		"================================\n";
	std::cout <<
		"\
1. 학생 추가\n\
2. 학생 제거\n\
3. 전체 학생 출력\n\
4. 평균 및 총점 출력\n\
5. 평균 이상 학생 출력\n\
6. 종료"
		<< std::endl;
	std::cout <<
		"================================\n";
	std::cout <<
		" > ";
	std::cin >> input;
}

void Add(std::vector<Student>& Record)
{
	int num{}, score{};
	std::string name{};

	std::cout <<
		"[번호 학생이름 시험성적]";
	std::cout << " >> ";
	std::cin >> num >> name >> score;

	Record.push_back({ num, name, score });
}

void Remove(std::vector<Student>& Record)
{
	Record.pop_back();
}

void AllPrint(std::vector<Student>& Record)
{
	for (auto e : Record)
	{
		e.Print();
	}
}

float Sum(std::vector<Student>& Record)
{
	float sum{};
	for (auto e : Record)
	{
		sum += e.mScore;
	}
	return sum;
}

void ScorePrint(std::vector<Student>& Record)
{
	float sum{ Sum(Record) };

	std::cout << "총 합 : "
		<< sum
		<< " ,평균 : "
		<< sum / Record.size()
		<< std::endl;
}

void NormalStdnPrint(std::vector<Student>& record)
{
	float mean{ Sum(record) / record.size() };
	for (auto e : record)
	{
		if (mean <= e.mScore)
		{
			e.Print();
		}
	}

}
/*******************Map*****************************/
void MAdd(std::map<int, Student>& Record)
{
	int num{}, score{};
	std::string name{};

	std::cout <<
		"[번호 학생이름 시험성적]";
	std::cout << " >> ";
	std::cin >> num >> name >> score;

	Record.insert({ num, {num, name, score} });
}
void MRemove(std::map<int, Student>& Record)
{
	int num;
	std::cout <<
		"[삭제할 학생 번호]";
	std::cout << " >> ";
	std::cin >> num;

	Record.erase(num);
}
void MAllPrint(std::map<int, Student>& Record)
{
	for (auto pair : Record)
	{
		pair.second.Print();
	}
}
float MSum(std::map<int, Student>& Record)
{
	float sum{};
	for (auto pair : Record)
	{
		sum += pair.second.mScore;
	}
	return sum;
}
void MScorePrint(std::map<int, Student>& Record)
{
	float sum{ MSum(Record) };

	std::cout << "총 합 : "
		<< sum
		<< " ,평균 : "
		<< sum / Record.size()
		<< std::endl;
}
void MNormalStdnPrint(std::map<int, Student>& record)
{
	float mean{ MSum(record) / record.size() };
	for (auto pair : record)
	{
		if (mean <= pair.second.mScore)
		{
			pair.second.Print();
		}
	}
}




