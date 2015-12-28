#include <iostream>
using namespace std;

int
main()
{
	int* pi		=	new int(0);
	int* pia	=	new int[10];

	while(*pi < 10) {
		pia[*pi] = *pi;
		cout << "pia[" << *pi << "]"
			<< "=" << *pi << endl;
		*pi = *pi + 1;
	}

	delete pi;
	delete [] pia;
}