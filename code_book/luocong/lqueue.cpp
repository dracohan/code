///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   lqueue.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/28 16:00:57
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "lqueue.h"
using namespace std;

int main()
{
	CLQueue<int> queue;
	
//#ifdef _DEBUG
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | CRTDBG_LEAK_CHECK_DF);
//#endif

	queue.EnQueue(1);
	queue.EnQueue(2);
	queue.EnQueue(3);
	
	while(!queue.IsEmpty())
		cout << queue.DeQueue() << endl;
		
	//Segmentation Fault (core dump)
	//cout << queue.DeQueue() << endl;
	
}
	