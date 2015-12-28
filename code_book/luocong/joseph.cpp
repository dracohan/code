///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   joseph.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/26 12:55:13
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "clist.h"
#include <iostream>
using namespace std;

int main()
{
	int i;
	int n;
	int m;
	int nNumber;
	int nCurIndex;
	CCList<int> clist;
	
//#ifdef _DEBUG
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//#endif

	cout << "Please input the number of person: ";
	cin >> n;
	
	cout << "Please enter the deatch number: ";
	cin >> m;
	
	for(i = 1; i <= n; ++i)
	{
		clist.AddTail(i);
	}
	
	i = 0;
	do 
	{
		++i;
		nNumber = clist.GetNext();
		if(i == m)
		{
			cout << "The " << nNumber << " is removed." << endl;
			
			nCurIndex  = clist.GetCurrentIndex();
			clist.RemoveAt(nCurIndex);
			--n;
			
			i = 0;
		}
		
	}while(1 != n);
	
	cout << "The last number left is: " << clist.GetHead() << endl;
}

