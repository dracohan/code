
///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   meffect_item29.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/11/28
//  Comment     :	
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <memory>
#include <string>
#include "meffect_item29.h"


int main(){
	string s1 = "moreeffective";
	char* p = &s1[1];

	string s2 = s1;

	//s1 is:moreeffective and s2 is: moreeffective
	//s1 is:mmreeffective and s2 is: moreeffective
	//string here is not RC string
	cout << "s1 is:" << s1 << " and s2 is: " << s2 << endl;
	*p = 'm';
	cout << "s1 is:" << s1 << " and s2 is: " << s2 << endl;	
}