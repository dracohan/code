///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   file_copy.cc
//  Version     :   0.10	created	2014/05/24 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <fstream>
#include <iostream>

using namespace std;

int main() 
{
	string inputfilename;
	cout << "Please enter the filename: " << endl;
	cin >> inputfilename;
	
	string outputfilename = inputfilename + ".out";

	ifstream inputfile(inputfilename.c_str());
	if(!inputfile){
		cerr << "Unable to open " << inputfilename << endl; return -1;
	}
		
	ofstream outputfile(outputfilename.c_str());
	if(!outputfile){
		cerr << "Unable to open " << outputfilename << endl; return -1;
	}
	
	char ch;
	while(inputfile.get(ch)){
		cout << "get : " << ch << "|";

		outputfile.put(ch);
	}
		

	return 0;
}
