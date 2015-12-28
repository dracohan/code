#include <iostream>
using namespace std;


int main()
{
	//initilization
	string			str("abc.ddd");
	const	string 	cstr("fff.ccc");
	string substr1(str, 2); //c.ddd
	string substr2(str, 2, 3); //c.d
	string substr3("abcdefg", 2); //ab
	cout << "the value of substr1 is: " << substr1 << endl;
	cout << "the value of substr2 is: " << substr2 << endl;
	cout << "the value of substr3 is: " << substr3 << endl;

	//compare
	if(str > cstr)
		cout << "abc.ddd is larger than fff.ccc." << endl;
	else
		cout << "abc.ddd is less than fff.ccc." << endl;
	if(str.compare(cstr) > 0)
		cout << "abc.ddd is larger than fff.ccc." << endl;
	else
		cout << "abc.ddd is less than fff.ccc." << endl;

	//assign
	str = "sadfasdf";
	str.assign("a",5); //a,\0,\0,\0,\0
	str.assign(5,'a'); //a, a, a, a, a
	cout << "the value of str is: " << str << endl; //aaaaa

	//append
	str.append("bcd");
	cout << "the value of s after append is: " << str << endl; //aaaaabcd
	
	//insert
	//s.insert(1, 'd'); NOK!
	str.insert(1, "ddd"); //adddaaaabcd
	cout << "the value of s after append is: " << str << endl;
	
	//find
	string::size_type idx = str.find(".");
	cout << "the index of . is: " << idx << endl; //3

	//substring
	string basestr = str.substr(0, idx); //abc
	string extestr = str.substr(idx + 1, string::npos); //ddd
	cout << "the substr of str.substr(0, idx) is: " << basestr << endl;
	cout << "the substr of str.substr(idx, string::npos) is: " << extestr << endl;

	//compare
	if(extestr == "ddd")
		cout << "ddd file is found!" << endl;
	else
		cout << "ddd file is not found!" << endl;
	
	//replace
	string tmpname(str.replace(idx + 1, string::npos, "xxx")); //abc.xxx
	cout << "the string after replace extention is: " << tmpname << endl;

	//erase
	str = "internal";
	str.replace(0,2,"ex"); //external
	str.erase(5);
	str.erase(2,2);
	cout << "the string after erase is: " << str << endl;

	//clear
	str.clear();
	cout << "the string after clear is: " << str << endl;
	if(str.empty())
		cout << "the string is empty." << endl;
	else
		cout << "the string is not empty." << endl;
	if(str.begin() == str.end())
		cout << "equal." << endl;
	else
		cout << "unequal" << endl;

	//reverse
	str = "abcd";
	reverse(str.begin(), str.end());
	cout << "the string after reverse is: " << str << endl;
	str.assign(str.rbegin(), str.rend());
	cout << "the string after reverse is: " << str << endl;

	//data
	const char* pa = str.data();

	//size(), length()
	cout << "the size of str is: " << str.size() << endl;
	cout << "the size of str is: " << str.length() << endl;

	//[], at()
	char& r = str[2];
	char* p = &str[3];
	cout << "the 3rd char of str is: " << r << endl;
	cout << "the 4rd char of str is: " << *p << endl;
	str = "new value";
	//reference is invalid after str is re-assigned
	r = 'X';
	cout << "The value of str is: " << str << endl;

	//advanced find	
	//Input: I was a deer
	//Output: reed a saw I
	const string delims(" \t,.;");
	string line;
	cout << "Please input a sentence: " << endl;
	getline(cin, line,'\n');
	cout << "The input sentence is: " << line << endl;
	//while find a word
	string::size_type begIdx, endIdx;
	begIdx = line.find_first_not_of(delims);
	while(begIdx != string::npos){
		endIdx = line.find_first_of(delims, begIdx); 
		if(endIdx == string::npos);
			//endIdx = line.length();
		for(int i = endIdx - 1; i >= static_cast<int>(begIdx); --i)
			cout << line[i];
		cout << ' '; 
		begIdx = line.find_first_not_of(delims, endIdx);

	}
	cout << endl;

}