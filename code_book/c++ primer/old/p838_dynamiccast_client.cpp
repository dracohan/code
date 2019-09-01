///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   page_content_client.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//	Output		:
//	$ ./a
//	payroll was called.
//	employee::salary() was called.
//	This is not programmer
//	payroll was called.
//	programmer::salary() was called.
//	New added programmer::bonus() was called.
///////////////////////////////////////////////////////////////////////////////
#include "page_content.h"

#include <iostream>
using namespace std;

void payroll(employee *pe) {
	cout << "payroll was called. " << endl;
	pe->salary();
	
	programmer* pm = dynamic_cast<programmer*>(pe);
	
	if(pm)
		pm->bonus();
	else
		cout << "This is not programmer" << endl;
}

void programmer::bonus() {
	cout << "New added programmer::bonus() was called. " << endl;
}

int main() {

	employee* pe = new employee();
	
	payroll(pe);
	
	programmer* pp = new programmer();
	
	payroll(pp);
	
	return 0;
}



	


