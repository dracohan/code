#include <stdio.h>

int n;

int main() {
    int i;
    static int k; 
    double j;
    printf("hello\n");
    printf("i: %d, j: %f\n", i, j);
    printf("n: %d, k: %d\n", n, k);
    return 0;
}