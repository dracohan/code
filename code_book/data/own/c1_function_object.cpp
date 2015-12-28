// Generic findMax, with a function object, version #1
// Precondition,  a.size() > 0
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

template <class Object, class Comparator>
const Object& findMax(const vector<Object> &arr, Comparator cmp)
{
	int maxIndex = 0;
	for(int i = 1; i < arr.size(); i++) {
		if(cmp.isLessThan(arr[maxIndex], arr[i]))
			maxIndex = i;
	}
	return arr[maxIndex];
}

#include <functional>
template <class Object>
const Object& findMax(const vector<Object> &arr)
{
	return findMax(arr, less<Object>() );
}

class CaseInsensitiveCompare {
	public:
			bool isLessThan(const string &lhs, const string &rhs) const
				{return (stricmp(lhs.c_str(), rhs.c_str())< 0); }
};

int main() 
{
	vector<string> arr(3);
	arr[0] = "ZEBRA"; arr[1] = "alligator"; arr[2] = "crocodile";
	cout << findMax(arr, CaseInsensitiveCompare()) << endl;
	//cout << findMax(arr) << endl;
	return 0;
}

	
			
	
	