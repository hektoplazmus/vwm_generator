#include "Record.h"

using namespace std;

CRecord::CRecord (const string &cpu,
									const string &ram,
									const string &hdd,
									const string &displaySize,
									const string &displayResolution,
									double price,
									const string &delimither)
	: m_CPU (cpu),
		m_RAM (ram),
		m_HDD (hdd),
		m_DispalySize (displaySize),
		m_DispalyResolution (displayResolution),
		m_Price (price),
		m_Delimither (delimither)
{
}

CRecord::~CRecord ()
{
}

ostream & operator<<(ostream & os, const CRecord & record)
{
	{
		os << record.m_CPU << record.m_Delimither
			<< record.m_RAM << record.m_Delimither
			<< record.m_HDD << record.m_Delimither
			<< record.m_DispalySize << record.m_Delimither
			<< record.m_DispalyResolution << record.m_Delimither
			<< record.m_Price;
	}
	return os;
}
