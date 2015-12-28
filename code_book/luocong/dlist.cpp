///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   dlist.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/25 16:50:15
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "dlist.h"
using namespace std;

int main()
{
	int i;
	int nCount;
	CDList<int> dlist;
	
//#ifdef _DEBUG
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//#endif

	dlist.AddTail(1);
	dlist.AddTail(3);
	dlist.InsertBefore(2, 2);
	dlist.AddHead(4);
	dlist.RemoveTail();
	
	nCount = dlist.GetCount();
	for(i = 1; i <= nCount; )
	{
		cout << dlist.GetNext(i) << endl;
	}
}

