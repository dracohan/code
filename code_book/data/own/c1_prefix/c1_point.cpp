#include <iostream>
#include "IntCell.h"

int main()
{
	IntCell* m;
	
	m = new IntCell(0);

	m->WriteData(5);

	cout << "The store data of *m is: " << m->ReadData() << endl;

	delete m;

	return 0;
}
	



