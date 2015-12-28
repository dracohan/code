#include <iostream>

using namespace std;

int main() {
	
	string word;
	
	while(cin >> word) 
		cout << word;

	cout << "ok: no more word to read. Bye!" << endl;
	
	/*
	//as a continuous stream,不删除空格
	char ch;
	while(cin.get(ch) != EOF)
		cout.put(ch);
	*/
	return 0;
}

//additional info

//test input is legal
int int_item;
cin >> int_item;
if(!cin)
	cerr << "error: int is needed!";

//osstringstream
#include <iostream>
#include <sstream>
using namespace std;
int main(){
	string program_name("our_program");
	string program_version("1.0");
	ostringstream out_message;
	out_message << "asdfasdf" << program_name + "asdfasdfasdf" << program_version;
	cout << out_message.str();

	int ival = 1024; int *pival = &ival;
	double dval = 3.1415926; double *pdval = &dval;
	out_message << ival << " " << pival << " " 
				<< dval << " " << pdval << " ";
	cout << out_message.str();

}

//ostream_iterator<string>
string pool[] = {
	"Tigger", "Piget", "Eye", "Rabit"
};
vector<string> vec_pool(pool, pool+4);
vector<string>::iterator iter = vec_pool.begin();
vector<string>::iterator iter_end = vec_pool.end();
ostream_iterator<string> output(cout, "");
copy(iter, iter_end, output);

//istream_iterator
istream_iterator<string> in(cin), eos;
vector<string> text;
copy(in, eos, back_inserter(text));

//tips to output address of a string 
const string str("Vonnod");
cout << static_cast<void*>(const_cast<char*>(str));

//other input/output method
const int linesize = 1024;
char inbuf[linesize];
while(cint.getline(inbuf, linesize))
{
	int readin = cin.getcount();
	cout.write(inbuf, readin).put('\n').put('\n');
}
