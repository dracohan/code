/* printf.cc
* 2014/09/02 update
*/
#include <iostream>
using namespace std;

int main() {
	printf("abcd"
		"efg\n");

	char* var[] = {
		"adf",
		"def" //没有逗号，故自动连接在一起
		"ghi",
	};

	//sizeof(var)为8
	//sizeof(var[0])为4
	printf("size of var is: %d\n", sizeof(var)/sizeof(var[0]));

	for(size_t sz = 0; sz < sizeof(var)/sizeof(var[0]); sz++)
		cout << var[sz] << endl;

	int p = 2;
	size_t apple = sizeof(int) * p;
	printf("apple is: %d\n", apple);

	int q = 3;
	int res = p+++q;
	printf("res is: %d\n", res);	

	struct pig_id {
		unsigned int a;
	};
	return 0;
}

