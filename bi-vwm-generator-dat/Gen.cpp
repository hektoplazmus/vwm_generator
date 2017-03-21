#include <iostream>

#include "Gen.h"

#pragma warning(disable:4996)

using namespace std;

CGen::CGen (const string &outputFile)
{
	m_FS.open (outputFile);
	vector<string> tmp;

	tmp.push_back ("I3");
	tmp.push_back ("I5");
	tmp.push_back ("I7");
	m_MetaData.insert (pair < string, vector<string>> ("CPU", tmp));

	tmp.clear ();
	tmp.push_back ("2 GB");
	tmp.push_back ("3 GB");
	tmp.push_back ("4 GB");
	tmp.push_back ("6 GB");
	tmp.push_back ("8 GB");
	tmp.push_back ("12 GB");
	tmp.push_back ("16 GB");
	tmp.push_back ("24 GB");
	tmp.push_back ("32 GB");
	m_MetaData.insert (pair < string, vector<string>> ("RAM", tmp));

	tmp.clear ();
	tmp.push_back ("320 GB HDD");
	tmp.push_back ("500 GB HDD");
	tmp.push_back ("750 GB HDD");
	tmp.push_back ("1 000 GB HDD");
	tmp.push_back ("128 GB SSD");
	tmp.push_back ("240 GB SSD");
	tmp.push_back ("256 GB SSD");
	tmp.push_back ("320 GB SSD");
	tmp.push_back ("512 GB SSD");
	m_MetaData.insert (pair < string, vector<string>> ("HDD", tmp));

	tmp.clear ();
	tmp.push_back ("10\"");
	tmp.push_back ("11\"");
	tmp.push_back ("12\"");
	tmp.push_back ("13\"");
	tmp.push_back ("13,3\"");
	tmp.push_back ("14\"");
	tmp.push_back ("15,6\"");
	tmp.push_back ("17,3\"");
	m_MetaData.insert (pair < string, vector<string>> ("Display size", tmp));

	tmp.clear ();
	tmp.push_back ("1280x800");
	tmp.push_back ("1366x768");
	tmp.push_back ("1600x900");
	tmp.push_back ("1680x1050");
	tmp.push_back ("1920x1080");
	tmp.push_back ("2560x1440");
	tmp.push_back ("2880x1800");
	tmp.push_back ("3840x2160");
	m_MetaData.insert (pair < string, vector<string>> ("Display resolution", tmp));
}

CGen::~CGen (void)
{
	if (m_FS.is_open ())
		m_FS.close ();
}

void CGen::generateRecords (uint32_t recordsCount)
{
	for (uint32_t i = 0; i < recordsCount; i++)
		writeRecordIntoOutputFile (generateOneRecord ());
}

CRecord CGen::generateOneRecord (void)
{
	vector<string> tmp = m_MetaData.find ("CPU")->second;
	string cpu = tmp [rand () % tmp.size ()];
	tmp = m_MetaData.find ("RAM")->second;
	string ram = tmp [rand () % tmp.size ()];
	tmp = m_MetaData.find ("HDD")->second;
	string hdd = tmp [rand () % tmp.size ()];
	tmp = m_MetaData.find ("Display size")->second;
	string displaySize = tmp [rand () % tmp.size ()];
	tmp = m_MetaData.find ("Display resolution")->second;
	string displayResolution = tmp [rand () % tmp.size ()];

	string delimither = ";";

	return CRecord (cpu, ram, hdd, displaySize, displayResolution, delimither);
}

void CGen::writeRecordIntoOutputFile (const CRecord &record)
{
	m_FS << record << endl;
}
