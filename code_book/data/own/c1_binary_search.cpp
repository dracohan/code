#include <iostream>
#include <algorithm>
#include <vector>
#include "example_vec.h"
#include "../../utility/printCollection.h"
using namespace std;

extern vector<int> example_vec;

template<typename comparable>
int binarySearch(const vector<comparable> &a, const comparable &x){
	int low = 0, high = a.size() - 1;

	while(low <= high)
	{
		int center = (high + low)/2;
		if(x < a[center])
			high = center - 1;
		else if(x > a[center])
			low = center + 1;
		else
			return center;
	}

	return -1;
}
int main(){

	cout << "The count of array is: " << example_vec.size() << endl;

	printCollection(example_vec);

	stable_sort(example_vec.begin(), example_vec.end());

	printCollection(example_vec);

	cout << "The index of 13 is " << binarySearch(example_vec, 13) << endl;

	return 0;

}