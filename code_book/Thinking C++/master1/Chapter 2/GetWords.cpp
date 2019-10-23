//: C02:GetWords.cpp
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
	vector<string> words;
	ifstream in("/home/suiyuan/github/code/code_book/Thinking C++/master1/Chapter 2/input");
	string word;
	while (in >> word)
		words.push_back(word);
	for (int i = 0; i < words.size(); i++)
		cout << words[i] << endl;
} ///:~