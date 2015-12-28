#include <iostream>
using namespace std;

char *string1, *string2;

int main() {
	string1 = "abcd"; string2 = "abcd";
	if(string1 == string2) printf("strings are shared!\n");
	else printf("strings are NOT shared!\n");
	//有可能运行时错误
	//string1[0] = '1';
	if(*string1 == '1') printf("string are writable!\n");
	else printf("string are NOT writable!\n");

	return 0;
}

