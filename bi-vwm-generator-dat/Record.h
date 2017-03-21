#pragma once

#include <string>
#include <iostream>

using namespace std;

class CRecord
{
public:
	CRecord (const string &cpu,
					 const string &ram,
					 const string &hdd,
					 const string &displaySize,
					 const string &displayResolution,
					 double price,
					 const string &delimither);
	~CRecord (void);
	
private:
	string m_CPU;
	string m_RAM;
	string m_HDD;
	string m_DispalySize;
	string m_DispalyResolution;
	double m_Price;

	string m_Delimither;

	friend ostream &operator<< (ostream &os, const CRecord &record);
};

