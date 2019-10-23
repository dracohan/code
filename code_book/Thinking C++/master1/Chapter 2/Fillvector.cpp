//: C02:Fillvector.cpp
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> v;
	ifstream in("/home/suiyuan/github/code/code_book/Thinking C++/master1/Chapter 2/FillString.cpp");
	string line;
	while ( getline(in, line) )
		v.push_back(line);	
	for (int i = 0; i < v.size(); i++)
		cout << i << ": " << v[i] << endl;
	// cout << v << endl; // can't output vector directly
} ///:~