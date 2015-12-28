#ifndef EXAMPLE_VEC_H
#define EXAMPLE_VEC_H
#include <vector>

using namespace std;

int intArray[] = {13, 2, 24, 12, 1, 28, 93, 120, 21, 25, 42, 83, 78, 68, 93, 91, 125, 22, 9};
//[0 1 2 9 12 13 21 22 24 25 28 42 68 78 83 91 93 93 120 125]

//20 element
vector<int> example_vec(intArray, intArray+sizeof(intArray)/sizeof(intArray[0]));

#endif