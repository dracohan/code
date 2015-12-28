#include <iostream>

using namespace std;

int main() 
{
	int maxNumber = 1000;
	int person = 8;
	for(int i = 1; i < maxNumber; i++) {
		if(((i%3) == 0) || (i%10 == 3))
			cout << "Person " << ((i-1)%8 + 1) << ": pa " << endl;
		else
			cout << "Person " << ((i-1)%8 + 1) << ": say " << i << endl;
	}
}
