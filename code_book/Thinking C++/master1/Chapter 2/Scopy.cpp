//: C02:Scopy.cpp
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream in("Scopy1.cpp");	
	ofstream out("Scopy2.cpp");	
	string s;
	while ( getline(in, s) )	
		out << s << "\n";		
} ///:~