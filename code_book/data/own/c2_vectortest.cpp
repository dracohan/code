#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main() 
{
	vector<int> testVector(100);

	for( int i = 0; i <= 100; i++) 
		testVector[i] = i*i;

	for( int j = 0; j <= testVector.size(); j++)
		cout << "Value of " << j << "is " << testVector[j] << endl;

	return 0;
}
