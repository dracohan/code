#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;
#define N 100050
char a[N];
int pre[N],chi[N];
void init(int n)
{
    pre[0]=0;
    for(int i=1; i<n; i++)
        pre[i]=i-1;
    for(int i=0; i<n; i++)
        chi[i]=i+1;
}
int main()
{
    int n,d;
    while(~scanf("%d %d",&n,&d)&&(n+d))
    {
        init(n);
        scanf("%s",a);
        int pos=0;
        while(d)
        {
            if(a[pre[pos]]<a[pos])
                pos=pre[pos];
            if(chi[pos]<n)
            {
                if(a[pos]<a[chi[pos]])
                {
                    a[pos]=0;
                    chi[pre[pos]]=chi[pos];
                    if(pos==pre[pos]) pre[chi[pos]]=chi[pos];
                    else pre[chi[pos]]=pre[pos];
                    d--;
                }
                pos=chi[pos];
            }
            else
            {
                while(d)
                {
                    a[pos]=0;
                    pos=pre[pos];
                    d--;
                }
            }
        }
        for(int i=0;i<n;i++)
            if(a[i]!=0)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}
