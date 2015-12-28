///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   singleton.cpp
//  Version     :   0.10
//  Author      :   Jimmy Han
//  Date        :   2014/6/25 21:54
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////

#include "singleton.h"
#include <iostream>
using namespace std;

Singleton* Singleton::uniqueInstance = NULL;

Singleton::Singleton()
{
	cout << "Singleton class was initilized!" << endl;
}

	
	
