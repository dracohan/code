#include <vector>
#include <iostream>
using namespace std;

int
main()
{
	vector<int> intv;

	for(int i = 0; i < 10; i++)
		intv.push_back(i);

	for(int i = 0; i < 10; i++)
		intv[i] = intv[i] * 10;

	for(int i = 0; i < 10; i++)
		cout << intv[i] << endl;

	return 0;
}