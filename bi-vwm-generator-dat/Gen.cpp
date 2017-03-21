#include <iostream>

#include "Gen.h"

#pragma warning(disable:4996)

using namespace std;

CGen::CGen (const string &outputFile)
{
	m_FS.open (outputFile);

	vector<pair<string, double>> tmp;

	tmp.push_back (pair<string, double> ("Intel I3-5100U", 2000.0));
	tmp.push_back (pair<string, double> ("Intel I3-5200U", 2500.0));
	tmp.push_back (pair<string, double> ("Intel I5-5200U", 3000.0));
	tmp.push_back (pair<string, double> ("Intel I5-5500U", 3500.0));
	tmp.push_back (pair<string, double> ("Intel I7-5200U", 4000.0));
	tmp.push_back (pair<string, double> ("Intel I7-5500U", 4500.0));

	tmp.push_back (pair<string, double> ("Intel I3-6100U", 2250.0));
	tmp.push_back (pair<string, double> ("Intel I3-6200U", 2750.0));
	tmp.push_back (pair<string, double> ("Intel I5-6200U", 3250.0));
	tmp.push_back (pair<string, double> ("Intel I5-6500U", 3750.0));
	tmp.push_back (pair<string, double> ("Intel I7-6200U", 4250.0));
	tmp.push_back (pair<string, double> ("Intel I7-6500U", 4750.0));

	tmp.push_back (pair<string, double> ("Intel I3-7100U", 2500.0));
	tmp.push_back (pair<string, double> ("Intel I3-7200U", 3000.0));
	tmp.push_back (pair<string, double> ("Intel I5-7200U", 3500.0));
	tmp.push_back (pair<string, double> ("Intel I5-7500U", 4000.0));
	tmp.push_back (pair<string, double> ("Intel I7-7200U", 4500.0));
	tmp.push_back (pair<string, double> ("Intel I7-7500U", 5000.0));
	m_MetaData.insert (pair < string, vector<pair<string, double>>> ("CPU", tmp));

	tmp.clear ();
	tmp.push_back (pair<string, double> ("2", 300.0));
	tmp.push_back (pair<string, double> ("3", 500.0));
	tmp.push_back (pair<string, double> ("4", 700.0));
	tmp.push_back (pair<string, double> ("6", 1000.0));
	tmp.push_back (pair<string, double> ("8", 1300.0));
	tmp.push_back (pair<string, double> ("12", 1700.0));
	tmp.push_back (pair<string, double> ("16", 2000.0));
	tmp.push_back (pair<string, double> ("24", 3000.0));
	tmp.push_back (pair<string, double> ("32", 3500.0));
	m_MetaData.insert (pair < string, vector<pair<string, double>>> ("RAM", tmp));

	tmp.clear ();
	tmp.push_back (pair<string, double> ("320 GB HDD", 400.0));
	tmp.push_back (pair<string, double> ("500 GB HDD", 500.0));
	tmp.push_back (pair<string, double> ("750 GB HDD", 750.0));
	tmp.push_back (pair<string, double> ("1 000 GB HDD", 1000.0));
	tmp.push_back (pair<string, double> ("128 GB SSD", 1000.0));
	tmp.push_back (pair<string, double> ("240 GB SSD", 2000.0));
	tmp.push_back (pair<string, double> ("256 GB SSD", 2300.0));
	tmp.push_back (pair<string, double> ("320 GB SSD", 3500.0));
	tmp.push_back (pair<string, double> ("512 GB SSD", 6000.0));
	m_MetaData.insert (pair < string, vector<pair<string, double>>> ("HDD", tmp));

	tmp.clear ();
	tmp.push_back (pair<string, double> ("10", 5000.0));
	tmp.push_back (pair<string, double> ("11", 5000.0));
	tmp.push_back (pair<string, double> ("12", 5000.0));
	tmp.push_back (pair<string, double> ("13", 5000.0));
	tmp.push_back (pair<string, double> ("13.3", 5500.0));
	tmp.push_back (pair<string, double> ("14", 6000.0));
	tmp.push_back (pair<string, double> ("15.6", 7000.0));
	tmp.push_back (pair<string, double> ("17.3", 8000.0));
	m_MetaData.insert (pair < string, vector<pair<string, double>>> ("Display size", tmp));

	tmp.clear ();
	tmp.push_back (pair<string, double> ("1280x800", 5000.0));
	tmp.push_back (pair<string, double> ("1366x768", 5500.0));
	tmp.push_back (pair<string, double> ("1600x900", 5700.0));
	tmp.push_back (pair<string, double> ("1680x1050", 6000.0));
	tmp.push_back (pair<string, double> ("1920x1080", 7000.0));
	tmp.push_back (pair<string, double> ("2560x1440", 7500.0));
	tmp.push_back (pair<string, double> ("2880x1800", 8500.0));
	tmp.push_back (pair<string, double> ("3840x2160", 10000.0));
	m_MetaData.insert (pair < string, vector<pair<string, double>>> ("Display resolution", tmp));
}

CGen::~CGen (void)
{
	if (m_FS.is_open ())
		m_FS.close ();
}

void CGen::generateRecords (uint32_t recordsCount)
{
	m_FS << "CPU,RAM,HDD,Velikost displeje,Rozliseni displeje,Cena" << endl;

	for (uint32_t i = 0; i < recordsCount; i++)
		writeRecordIntoOutputFile (generateOneRecord ());
}

CRecord CGen::generateOneRecord (void)
{
	//map<string, vector<pair<string, double>>> m_MetaData;
	double price = 0.0;
	int randomIndex;
	vector<pair<string, double>> tmp;

	tmp = m_MetaData.find ("CPU")->second;
	randomIndex = rand () % tmp.size ();
	string cpu = tmp [randomIndex].first;
	price += tmp [randomIndex].second;

	tmp = m_MetaData.find ("RAM")->second;
	randomIndex = rand () % tmp.size ();
	string ram = tmp [randomIndex].first;
	price += tmp [randomIndex].second;

	tmp = m_MetaData.find ("HDD")->second;
	randomIndex = rand () % tmp.size ();
	string hdd = tmp [randomIndex].first;
	price += tmp [randomIndex].second;

	tmp = m_MetaData.find ("Display size")->second;
	randomIndex = rand () % tmp.size ();
	string displaySize = tmp [randomIndex].first;
	price += tmp [randomIndex].second;

	tmp = m_MetaData.find ("Display resolution")->second;
	randomIndex = rand () % tmp.size ();
	string displayResolution = tmp [randomIndex].first;
	price += tmp [randomIndex].second;

	price += (rand () % (int) price/4) + price/2;

	return CRecord (cpu, ram, hdd, displaySize, displayResolution, price, ",");
}

void CGen::writeRecordIntoOutputFile (const CRecord &record)
{
	m_FS << record << endl;
}
