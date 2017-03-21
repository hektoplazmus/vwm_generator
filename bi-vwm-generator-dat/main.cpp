#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include "Gen.h"

int main (void)
{
	uint32_t recordsCount;

	cout << "How many records do you want to generate?" << endl;
	cin >> recordsCount;

	string outPutFileName = "C:/Users/Deny/Desktop/data.txt";

	CGen generator (outPutFileName);

	generator.generateRecords (recordsCount);

	cout << "Complete!" << endl;
	// Windows :)
	system ("pause");
	return 0;
}