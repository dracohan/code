#include <stdio.h>

#define foo(i, j) ((i > j)? i : j);

int main(){
    int i, j = 1;
    foo(i++, j++);
    printf("j: %d\n", j);
    return 0;
}