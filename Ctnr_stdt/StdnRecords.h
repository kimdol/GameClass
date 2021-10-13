#pragma once
class StdnRecords
{
public:
	struct Record
	{
		int mNumber;
		int mScore;
		std::string mName;
	};
private:
	std::vector<Record> mVRecords;
	std::map<std::string, int> mMRecords;
public:
	StdnRecords();
	~StdnRecords();

	void AllPrint();
	void Add();
	void Remove();
	void ScorePrint();
	void NormalStdnPrint();
};

