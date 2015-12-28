#include <iostream>
#include <vector>
#include "utility.h"
using namespace std;

int ia[] = {123,1,32,53,23,21,45,56,54,223,669,654};

int
main()
{
	vector<int> vint(ia, ia+10);
	PRINT_ELEMENT(vint, "haha");

	//sort try 
	sort(vint.begin(), vint.end());
	PRINT_ELEMENT(vint);

	//find try
	int search_value;
	cout << endl << "Please enter your number: " << endl;
	cin >> search_value;
	vector<int>::iterator found;
	found =	find(vint.begin(), vint.end(), search_value);
	if(found == vint.end())
		cout << "search value not found." << endl << endl;
	else
		cout << "search value found." << endl << endl;;

	//reverse try
	reverse(vint.begin(), vint.end());
	PRINT_ELEMENT(vint);

	//insert try
	INSERT_ELEMENT(vint, 3, 7);
	PRINT_ELEMENT(vint);

	return 0;
}