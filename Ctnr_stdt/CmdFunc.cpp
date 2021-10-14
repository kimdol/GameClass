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
1. �л� �߰�\n\
2. �л� ����\n\
3. ��ü �л� ���\n\
4. ��� �� ���� ���\n\
5. ��� �̻� �л� ���\n\
6. ����"
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
		"[��ȣ �л��̸� ���輺��]";
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

	std::cout << "�� �� : "
		<< sum
		<< " ,��� : "
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