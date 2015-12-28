#include <iostream>
using namespace std;

int 
main()
{
	int num;
	cout << "please enter a number" << endl;
	cin >> num;
	//output is dec
	cout << "the num in dec is: " << dec << num << endl;
	//output is hex
	cout << "the num in hex is: " << hex << num << endl;
	//output is dec again
	cout << "the num in dec is: " << dec << num << endl;
	//check
	cout << "the num of 16 is: " << 16 << endl;
}