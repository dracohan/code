///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   page_content.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/07/26 16:50:14
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "page_content.h"

#include <iostream>
using namespace std;

int employee::salary() {
	cout << "employee::salary() was called. " << endl;
}

int manager::salary() {
	cout << "manager::salary() was called. " << endl;
}

int programmer::salary() {
	cout << "programmer::salary() was called. " << endl;
}
