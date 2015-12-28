///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   page_content_client.cpp
//  Version     :   0.10
//  Author      :   Jimmy Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//	Output		:	1 2 3 4 5 
//	$ ./a
///////////////////////////////////////////////////////////////////////////////
#include "access_private_data.h"
#include <iostream>
using namespace std;

int main() {
	int a[5] = {1,2,3,4,5};
	data d(a);
	int* b;
	//can cast class to int* to access private data
	b = (int *)&d;
	for(int i = 0; i < 5; i++)
		cout << b[i] << " ";
	return 0;
}



	


