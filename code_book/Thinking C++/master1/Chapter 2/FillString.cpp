//: C02:FillString.cpp
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream in("/home/suiyuan/github/code/code_book/Thinking C++/master1/Chapter 2/FillString.cpp");
	string s, line;
	while ( getline(in, line) )
		// s += line;
		s += line + "\n";
	cout << s;
} ///:~