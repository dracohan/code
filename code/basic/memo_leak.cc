///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   memo_leak.cc
//  Version     :   0.10	created	2014/05/24 00:00:00		
//  Author      :   Jimmy Han
//  Comment     :  查看内存泄漏的情况
//
///////////////////////////////////////////////////////////////////////////////
#include <unistd.h>

int main() {
	int i = 0;
	while(i <= 1000)
		char* pi = new char[531365852];
		sleep(2);
		//delete pi;

}