#include <iostream>
using namespace std;

int main()
{
#if 0
	//devide by 0
	int i = 1;
	int j = 0;
	double d = i/j;
#endif	

#if 1
	//allocate large memory, NOK
	char* pc = new char[1000000000];
#endif

#if 0
	//change const memory, OK
	char* pc1 = "stack";
	pc1[0] = 'a';
	cout << pc1 << endl;
#endif

#if 0
	//access invalid address£¬ OK
	char pc3[] = {'a', 'b', 'c'};
	pc3[3] = 'd';	
	cout << pc3 << endl;
#endif

#if 0 
	//stack overflow, NOK
	char pc4[8];
	cout << "Please enter yoour name: " << endl;
	cin >> pc4; //enter AAAAAAAAAAAAAAAAAAAAAAA
	cout << "Your name is: " << pc4 << endl;
#endif

#if 0
	//delete pointer not from new, NOK
	int i;
	int* pi = &i;
	delete pi;
#endif

}
