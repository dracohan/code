#define K 0xFFFFFFFF

#include <stdio.h>

int main(){
    if (0 < K) printf("K is unsigned (Standard C)\n");
    else printf("K is signed (traditional C)\n");
    return 0;
}