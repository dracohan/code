///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item5.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/18
//  Comment     :	pass arg by value/const reference will be auto-converted
//					pass arg by refernce will not be auto-converted because, the reference will be meaningless
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "meffect_item5.h"
using namespace std;

void uppercase(const string& str){
	cout << "uppercase() was called" << endl;
}



int main(){
	char chararray[] = "abc";

	uppercase(chararray);

	int c = 1+2;

	return 0;
}