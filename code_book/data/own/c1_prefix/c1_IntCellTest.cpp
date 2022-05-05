#include "IntCell.h"
#include <iostream> 

using namespace std;

int main() 
{
	IntCell a;

	a.WriteData(5);

	cout << "IntCell contain value: " << a.ReadData() << endl;

	return 0;

}
