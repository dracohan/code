///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   singleton.h
//  Version     :   0.10
//  Author      :   Jimmy Han
//  Date        :   2014/6/25 21:54
//  Comment     :   
//
///////////////////////////////////////////////////////////////////////////////

#ifndef __H__
#define __H__
#include <iostream>
using namespace std;

class Singleton {
public:
	static Singleton* getInstance(){
			if(uniqueInstance == NULL){
				cout << "synchronized!" << endl;
				if(uniqueInstance == NULL)
					uniqueInstance = new Singleton();
			}
			return uniqueInstance;
		}
private: 
		static Singleton* uniqueInstance;
		
		Singleton();
};


#endif
