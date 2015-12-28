#include "p35_IntArray.h"
#include "p35_IntArrayRC.h"
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int array[ 4 ] = {1, 2, 3, 4};
	IntArray ia = IntArray(array, 4); 
	IntArrayRC iarc = IntArrayRc(array, 4); 

	cout << ia[ 1 ] << endl;
	cout << iarc[ 1 ] << endl;

	cout << ia[ 4 ] << endl;
	cout << iarc[ 4 ] << endl;

	return 0;
}

