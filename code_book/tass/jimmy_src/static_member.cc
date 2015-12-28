#include <iostream>
using namespace std;

//template<class T>
class testClass {
public:
	static int _data;	
};

int testClass::_data = 1;
//char testClass<char>::_data = 'a';

int
main()
{
	cout << testClass::_data << endl;
	// cout << testClass<char>::_data << endl;

	testClass obj1, obj2;
	//testClass<char> obj3, obj4;

	cout << obj1._data << endl;
	cout << obj2._data << endl;
	// cout << obj3._data << endl;
	// cout << obj4._data << endl;

	return 0;
}