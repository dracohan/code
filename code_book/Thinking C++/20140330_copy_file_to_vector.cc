#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int
main()
{
	vector<string> intv;
	string line;
	ifstream infile("in.log");
	while(getline(infile, line))
		intv.push_back(line);

	vector<string>::iterator iter;
	for(iter = intv.begin(); iter != intv.end(); iter++)
		cout << *iter << "	";

	return 0;
}