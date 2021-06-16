#include <stdio.h>

int main() {
    int a; 
    long long i;
    long long k;
    int j;
    printf("size of long long: %d\n", sizeof(i)); 
    printf("stack top is near: %p\n", &a);
    printf("stack top is near: %p\n", &i);
    printf("stack top is near: %p\n", &j);
    printf("stack top is near: %p\n", &k);
    return 0;
}

