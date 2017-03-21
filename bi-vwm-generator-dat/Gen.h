#pragma once
#include <fstream>
#include <string>
#include <map>
#include <vector>

#include "Record.h"

using namespace std;

class CGen
{
public:
	CGen (const string &outputFile);
	~CGen (void);

	void generateRecords (uint32_t recordsCount);

private:
	ofstream m_FS;
	FILE *m_OutputFile;
	map<string, vector<string>> m_MetaData;

	CRecord generateOneRecord (void);
	void writeRecordIntoOutputFile (const CRecord &record);
};

