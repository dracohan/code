#include <vector>
#include <iostream>
#include "printCollection.h"

using namespace std;

/**
 * Return the maximum item in array a.
 *Assume a.size()>0;
 *Comparable object must provide operator< and operator=
 */
template<class comparable>
const comparable& findMax(const vector<comparable> &rhs)
{
	int maxIndex = 0;

	for(int i = 0; i < rhs.size(); i++)
		if(rhs[maxIndex] < rhs[i] )
			maxIndex = i;

	return rhs[maxIndex];
}

int main() 
{
	int ia[7] = {1, 2, 23, 13, 44, 12, 231};
	string sa[] = {"ab", "b", "c"};

	vector<int> iva(ia, ia+sizeof(ia)/sizeof(ia[0]));
	vector<string> sva(sa, sa+sizeof(sa)/sizeof(sa[0]));

	cout << findMax(iva) << endl;
	cout << findMax(sva) << endl;
}