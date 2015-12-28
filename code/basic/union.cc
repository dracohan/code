#include <iostream>
using namespace std;

//作用1，如果只是存a，20000000 个s_tag节约20M空间
union s_tag { int a[100];
char aaa; };
s_tag fa, sa, ua;
s_tag multiple(s_tag s) {
	int j;
	for(j = 0; j < 100; j++)
		s.a[j] *= 2; 
	return s;
}

//作用2，将同样一块32位内存解释为int或者分为四块解释为char
union bit32_tag{
	int whole;
	struct {char c0, c1, c2, c3; } byte;
} v;

int main() {
	fa.aaa = 'a';
	//for(int j = 0; j < 100; j++)
	//	fa.a[j] = j; 
	for(int j = 0; j < 100; j++)
		cout << fa.a[j] << endl; 
	cout << "aaa:" << fa.aaa << endl;

	//'A'
	v.whole = 65;
	cout << "v.byte.c0: " << v.byte.c0 << endl;
	cout << "v.byte.c1: " << v.byte.c1 << endl;
	cout << "v.byte.c2: " << v.byte.c2 << endl;
	cout << "v.byte.c3: " << v.byte.c3 << endl; 

	return 0;
}

