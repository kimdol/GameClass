#include <iostream>
#include <vector>
#include <map>
#include "Student.h"
#include "CmdFunc.h"

using Students = std::vector<Student>;

enum command
{
	cAdd = 1,
	cRemove,
	cAllPrint,
	cScorePrint,
	cNormalStdnPrint,
	cEnd
};
void System(Students& record)
{
	int input{ 100 };
	while (1)
	{
		Input(input);

		switch (input)
		{
			case cAdd:
				Add(record);
				break;
			case cRemove:
				Remove(record);
				break;
			case cAllPrint:
				AllPrint(record);
				break;
			case cScorePrint:
				ScorePrint(record);
				break;
			case cNormalStdnPrint:
				NormalStdnPrint(record);
				break;
			case cEnd:
				return;
				break;
			default:
				break;
		}
	}
	
}
int main()
{
	Students record;

	record.push_back({ 1, "Kim", 80 });
	record.push_back({ 2, "Lee", 20 });
	record.push_back({ 3, "Park", 50 });
	record.push_back({ 4, "Choi", 30 });

	System(record);
}
