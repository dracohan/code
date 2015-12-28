#include <iostream>
using namespace std;

struct s_tag { int a[100]; };
s_tag fa, sa, ua;
s_tag multiple(s_tag s) {
	int j;
	for(j = 0; j < 100; j++)
		s.a[j] *= 2; 
	return s;
}

int main() {
	for(int i = 0; i < 100; i++) fa.a[i] = i;
	for(int i = 0; i < 100; i++) cout << fa.a[i] << " ";
	sa = multiple(fa);
	cout << endl;
	for(int i = 0; i < 100; i++) cout << sa.a[i] << " ";
	ua = sa;
	cout << endl;
	for(int i = 0; i < 100; i++) cout << ua.a[i] << " ";
	
	return 0;
}

