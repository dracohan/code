// calc the number of 1 in a number 
#include "stdio.h"
#include <iostream>
using namespace std;

int fcount(int s)
{
    int num = 0;
    while(s)
    {
        s &= (s-1);
        num++;
    }
    return num;
}
int main()
{
    int v =9999;
    int num = fcount(v);
    cout << "the num of 1 in V is" <<num; 
}
