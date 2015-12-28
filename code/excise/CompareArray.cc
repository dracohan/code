#include <iostream>
#include <vector>
#include <algorithm>
#include "../basic/utility.h"
using namespace std;

int main()
{
	//input
	string arr1, arr2;
	cout << "Please enter array 1: " << endl;
	cin >> arr1;
	cout << "Please enter array 2: " << endl;
	cin >> arr2;

	cout << "arr1 is: " << arr1 << endl;
	cout << "arr2 is: " << arr2 << endl;

	//initilize two vectors
	vector<char> varr1(arr1.c_str(), arr1.c_str()+arr1.size());
	PRINT_ELEMENT(varr1);
	vector<char> varr2(arr2.c_str(), arr2.c_str()+arr2.size());
	PRINT_ELEMENT(varr2);

	//sort two vectors
	sort(varr1.begin(), varr1.end());
	PRINT_ELEMENT(varr1);
	sort(varr2.begin(), varr2.end());
	PRINT_ELEMENT(varr2);

	//compare two vectors
	if(varr1 == varr2)
		cout << "equal" << endl;
	else
		cout << "unequal" << endl;

	return true;
}