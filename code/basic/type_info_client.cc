///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   page_content_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//	Output		:
//	$ ./a
///////////////////////////////////////////////////////////////////////////////
#include "type_info.h"
#include <type_info>
#include <iostream>
using namespace std;
int main() {
	int iobj = 4;
	cout << typeid(iobj).name() << endl;
	cout << typeid(employee).name() << endl;
	return 0;
}



	


