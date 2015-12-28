///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   max_malloc.cc
//  Version     :   0.10	created	2014/05/24 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  查看可以分配的最大内存
//
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <malloc.h>
using namespace std;

int main()
{
    if(NULL == (char*)malloc(0x70000000*sizeof(char)))
        cout << "failed!" << endl;
    else
        cout << "succeed!" << endl;
}

