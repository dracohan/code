#include <fstream>
#include <iostream>
#include <sstream>
#include <stdio.h>

using namespace std;

int main() {
	//define
	ifstream infile("in_file");
	ofstream outfile("out_file");

	//check the result
	if(!infile){
		cerr << "Input file open error!" << endl;
		return -1;
	}

	if(!outfile){
		cerr << "Output file open error!" << endl;
		return -2;
	}

	//get the input and output to file
	char ch;
	while(cin.get(ch))
		outfile.put(ch);

	return 0;

}
/*
	string word;
	while(infile >> word)
		outfile << word;

	infile.clear();
	infile.seekg(0);

	ostringstream buf;
	char ch; 
	while(buf && infile.get(ch))
		buf.put(ch);
	cout << buf.str();


//additional info
char ch;
ofstream outFile("out_file");
while(cin.get(ch))
	outFile.put(ch);

//osfstream direct output
ofstream outFile("outfile");
outFile.put("1").put(")").put(' ');
outFile << "1+1=" << (1+1) << endl;

//2nd way to define fstream, open later
ifstream inFile;
ofstream outFile;
inFile.open(filename.c_str());
outFile.open(filename.c_str());
inFile.close();
outFile.close();

//fstream
fstream file;
file.open(filename.c_str(), ios_base::in);
file>>stringname;
file.close();
file.open(filename.c_str(), ios_base::out);
file<<stringname;
file.close();

//fstream 
fstream inOut("copy.out", ios_base::in |ios_base::out);
inOut.seek(0);
while(inOut.get(ch))
{
	ios_base::pos_type mark = inOut.tellg();
	inOut << cnt;
	inOut.seekg(mark);
}
inOut.clear();
inOut << cnt << endl;

//file operation example
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

	int lcnt = 0;
	string line;

	ifstream inFile("in_file");
	while(getline(inFile, line))
	{
		lcnt++;
		int readIn = line.size();
		cout << "Line #" << lcnt << " Char read:" << readIn << endl;
		cout << line << endl;
	}

}
*/