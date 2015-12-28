///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   slist.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/18 19:06:45
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "slist.h"

using namespace std;

int main()
{
	int i;
	int nCount; 
	CSList<int> slist;
	
#ifdef _DEBUG
#	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	slist.InsertAfter(slist.InsertAfter(slist.AddHead(1),2),3);
	slist.InsertAfter(slist.InsertAfter(slist.GetCount(),4),5);
	
	nCount = slist.GetCount();
	for(i = 1; i <= nCount; i++)
	{
		cout << slist.GetAt(i) << endl;
	}
}
