///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   stack.cpp
//  Version     :   0.10
//  Author      :   Ryan Han
//  Date        :   2013/06/28 13:31:35
//  Comment     :  
//
///////////////////////////////////////////////////////////////////////////////
#include "stack.h"
#include <iostream>
using namespace std;

static void PrintValue(const int nRetCode, const int nValue)
{
	if(nRetCode)
		cout << nValue << endl;
	else 
		cout << "Error occurred!" << endl;
}

int main()
{
	CStack<int> stack;
	int nValue;
	int nRetCode;
	
//#ifdef _DEBUG
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//#endif

	stack.push(1);
	stack.push(2);
	stack.push(3);
	
	nRetCode = stack.top(&nValue);
	PrintValue(nRetCode, nValue);
	
	nRetCode = stack.pop(&nValue);
	PrintValue(nRetCode, nValue);
	
	nRetCode = stack.pop(&nValue);
	PrintValue(nRetCode, nValue);
	
	nRetCode = stack.pop(&nValue);
	PrintValue(nRetCode, nValue);
	
	//Error occurred!
	nRetCode = stack.pop(&nValue);
	PrintValue(nRetCode, nValue);
}


